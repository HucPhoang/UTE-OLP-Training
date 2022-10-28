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

    a.erase(unique(a.begin(), a.end()), a.end());
    sort(a.rbegin(), a.rend());

    int res = 0;
    n = (int)a.size();
    for (int i = 1; i < n; ++i) {
        int l = 0, r = i - 1;
        int temp = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] % a[i] > temp) {
                temp = a[mid] % a[i];
                r = mid - 1;
            }
            else l = mid + 1;
        }
        res = max(res, temp);
    }

    cout << res;
    return 0;
}