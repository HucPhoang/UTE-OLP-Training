#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int m[10][5] = {
                            {0, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1},
                            {6, 2, 4, 8, 0},
                            {1, 3, 9, 7, 0},
                            {6, 4, 0, 0, 0},
                            {5, 5, 5, 5, 5},
                            {6, 6, 6, 6, 6},
                            {1, 7, 9, 3, 0},
                            {6, 8, 4, 2, 0},
                            {1, 9, 0, 0, 0}
                         };

    int a, n;
    cin >> a >> n;

    if (n == 0)
        cout << 1;
    else {
        int last = a % 10;
        if (last == 2 || last == 3 || last == 7 || last == 8)
            n %= 4;
        else if (last == 4 || last == 9)
            n %= 2;
        else n = 1;
        cout << m[last][n];
    }
    return 0;
}