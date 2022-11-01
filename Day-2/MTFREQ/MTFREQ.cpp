#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    map<int, int> freq;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    cout << freq.size() << '\n';
    for (int i = 0; i < n; ++i) {
        int currFreq = freq[a[i]];
        if (currFreq != -1) {
            cout << a[i] << ' ' << currFreq << '\n';
            freq[a[i]] = -1;
        }
    }
    return 0;
}