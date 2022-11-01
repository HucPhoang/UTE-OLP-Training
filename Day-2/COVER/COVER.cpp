#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> a(m+1, vector<int> (n+1));
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < n; ++j)
            a[i+1][j+1] = s[j]-'0';
    }

    vector<vector<int>> preSum(m+1, vector<int> (n+1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            preSum[i][j] = preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+a[i][j];
        }
    }

    int res = INT_MAX;
    for (int width = 1; width <= n; ++width) {
        if (k%width == 0) {
            int height = k/width;
            for (int i = 1; i <= m-height+1; ++i) {
                for (int j = 1; j <= n-width+1; ++j) {
                    int topRow = i, topCol = j;
                    int botRow = i+height-1, botCol = j+width-1;
                    res = min(res, preSum[botRow][botCol]-preSum[botRow][topCol-1]-preSum[topRow-1][botCol]+preSum[topRow-1][topCol-1]);
                }
            }
        }
    }

    cout << (res == INT_MAX ? -1 : res);
    return 0;
}