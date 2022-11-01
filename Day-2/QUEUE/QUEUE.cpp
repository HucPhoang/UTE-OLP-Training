#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    queue<int> q;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (type == 2) {
            if (!q.empty())
                q.pop();
        }
        else {
            if (q.empty()) cout << "Empty!\n";
            else cout << q.front() << '\n';
        }
    }
    return 0;
}