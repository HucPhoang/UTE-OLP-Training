#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum%3 != 0) {
        cout << 0;
        return 0;
    }

    vector<int> b(n+1);
    ll currsum = 0;

    for (int i = n-1; i >= 0; --i) {
        currsum += a[i];
        if (currsum == sum/3)
            b[i] = b[i+1]+1;
        else  b[i] = b[i+1];
    }

    ll ans = 0LL;
    currsum = 0;
    for (int i = 0; i < n-1; ++i) {
        currsum += a[i];
        if (currsum == sum/3) {
            ans += b[i+2];
        }
    }

    cout << ans;
    return 0;
}
 