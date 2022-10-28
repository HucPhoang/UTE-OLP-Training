#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();

    for (int tc = 1; tc <= t; ++tc) {
        string I, P;
        getline(cin, I);
        getline(cin, P);

        int res = 0;
        bool ok = true;

        if (I.size() > P.size())
            ok = false;
        else {
            int lenI = I.size(), i = 0;
            int lenP = P.size(), j = 0;
            while (i < lenI && j < lenP) {
                while (j < lenP && I[i] != P[j]) {
                    j++;
                    res++;
                }
                if (i < lenP && I[i] == P[j])
                    i++, j++;
            }

            res += lenP - j;
            if (i < lenI) ok = false;
        }

        cout << "Case #" << tc << ": ";
        if (ok) cout << res;
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
    return 0;
}