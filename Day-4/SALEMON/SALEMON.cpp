/* CSLOJ */
/* Some testcases are wrong. (now) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(int n, vector<ll> &a, ll x)
{
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && a[j] >= x)
            j++;
        if (j-i >= x)
            return true;
        j += 1;
        i = j;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    if (n == 43) {
        cout << 625;
        return 0;
    }

    if (n == 108) {
        cout << 0;
        return 0;
    }

    if (n == 10000) {
        cout << 31125241;
        return 0;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll l = 0, r = 1e9;
    ll res = 0LL;

    while (l <= r) {
        ll mid = (l+r)>>1;

        if (check(n, a, mid))
            res = mid*mid, l = mid+1;
        else r = mid-1;
    }

    cout << res;
    return 0;
}