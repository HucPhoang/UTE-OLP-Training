#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    cin >> n;
    
    int cnt = 0;
    vector<pair<ll, int>> res;
    while (n % 2LL == 0) {
        cnt++;
        n >>= 1LL;
    }
    if (cnt > 0)
        res.push_back({ 2, cnt });

    cnt = 0;
    for (ll i = 3; i * i <= n; ++i) {
        if (n%i == 0 ) {
            cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            res.push_back({ i, cnt });
        }
    }
    if (n > 1)
        res.push_back({ n, 1 });
    cout << res.size() << '\n';
    for (auto item : res)
        cout << item.first << ' ' << item.second << '\n';

    return 0;
}