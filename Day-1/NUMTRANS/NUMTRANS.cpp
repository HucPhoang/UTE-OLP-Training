#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i)
        cout << a[i];
    return 0;
}