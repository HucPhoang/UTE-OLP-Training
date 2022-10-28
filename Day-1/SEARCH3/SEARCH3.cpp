#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int binarySearch(vector<pair<int, int>>& a, int key)
{
    int l = 0, r = a.size() - 1;
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid].first == key) {
            pos = a[mid].second;
            r = mid - 1;
        }
        else if (a[mid].first > key)
            r = mid - 1;
        else l = mid + 1;
    }

    return pos;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a.begin(), a.end());
    for (auto i : b) {
        cout << binarySearch(a, i) << ' ';
    }
    return 0;
}