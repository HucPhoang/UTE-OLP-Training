#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> primes;
vector<bool> mark(1000005, true);
void sieve()
{
    mark[0] = mark[1] = false;
    for (ll i = 2; i <= 1000000; ++i) {
        if (mark[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i)
                mark[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sieve();

    int t;
    cin >> t;

    while (t--) {
        ll L, R;
        cin >> L >> R;
        cout << upper_bound(primes.begin(), primes.end(), R) - lower_bound(primes.begin(), primes.end(), L) << '\n';
    }
    return 0;
}