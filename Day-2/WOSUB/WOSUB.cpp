#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int s;
    cin >> s;

    int res = -1;
    int i = 0, j = 0;
    int currSum = 0;
    while (i < n) {
        while (j < n && currSum < s) {
            currSum += a[j];
            j++;
        }
        if (currSum == s)
            res = max(res, j-i);
        currSum -= a[i];
        i++;
    }

    cout << res;
    return 0;
}