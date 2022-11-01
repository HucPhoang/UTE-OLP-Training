#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a.begin()+1, a.end());

    vector<ll> preSum(n+1);
    preSum[0] = 0;
    for (int i = 1; i <= n; ++i)
        preSum[i] = preSum[i-1] + a[i];

    while (q--) {
        ll x;
        cin >> x;

        int l = 1, r = n;
        int cnt = 0, mn = INT_MIN;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (preSum[mid] > x)
                r = mid-1;
            else {
                cnt = mid;
                int ll = mid, rr = n;
                while (ll <= rr) {
                    int midd = (ll+rr)>>1;

                    if (preSum[midd] - preSum[midd-mid] > x)
                        rr = midd-1;
                    else {
                        mn = a[midd-mid+1];
                        ll = midd+1;
                    }
                }
                
                l = mid+1;
            }
        }

        cout << cnt << ' ' << mn << '\n';
    }
    return 0;
}