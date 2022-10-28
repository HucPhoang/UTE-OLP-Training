#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll L, R;
    cin >> L >> R;

    vector<ll> a;
    for (ll i = 1; i * i <= R; ++i)
        a.push_back(i * i);

    
    cout << a.size() - (lower_bound(a.begin(), a.end(), L)-a.begin());
    return 0;
}