#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string rev(string s, int l, int r)
{
    reverse(s.begin() + l, s.begin() + r);
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    int n;
    cin >> n;
    int lenS = s.size();
    vector<int> a(n);
    vector<int> cnt(lenS + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    
    for (int i = 0; i < lenS; ++i)
        cnt[i] %= 2;

    for (int i = 1; i < lenS; ++i)
        if (cnt[i] == 0)
            cnt[i] = -abs(cnt[i-1]);
        else cnt[i] += abs(cnt[i - 1]);

    vector<pair<int, int>> revList;
    for (int i = 0; i < lenS; ++i)
        if (cnt[i] > 0)
            revList.push_back({ i, cnt[i] });

    if (revList.size() && revList.back().second % 2)
        s = rev(s, revList.back().first, lenS - revList.back().first);

    for (int i = 0; i < (int)revList.size()-1; ++i) {
        if (revList[i].second % 2) {
            for (int j = revList[i].first; j < revList[i + 1].first; ++j)
                swap(s[j], s[lenS - j - 1]);
        }
    }

    cout << s;
    return 0;
}