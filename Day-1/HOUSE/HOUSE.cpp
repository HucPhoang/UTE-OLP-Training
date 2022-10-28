#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = { s[i], i };
    }

    sort(a.begin(), a.end());
    int res = 0;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first && a[i].second - 1 == a[i - 1].second) {
            cnt++;
        }
        else {
            res += cnt / 2;
            cnt = 1;
        }
    }
    res += cnt / 2;
    cout << res;
    return 0;
}