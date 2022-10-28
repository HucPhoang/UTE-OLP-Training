#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int res = 1;
    int _5 = 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp % 5 == 0) {
            _5++;
            temp /= 5;
        }
        a[i] = temp;
    }

    for (int i = 1; i <= n; ++i) {
        while (a[i] % 2 == 0 && _5 > 0) {
            a[i] /= 2;
            _5--;
        }
        res = (res * a[i]) % 10;
    }

    cout << res;
    return 0;
}