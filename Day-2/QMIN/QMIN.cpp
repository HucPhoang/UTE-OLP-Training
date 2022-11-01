#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6;
int n, q;
vector<int> a;
vector<int> seg(1<<21, INT_MAX);

void build(int id, int l, int r)
{
    if (l == r) {
        if (l <= n)
            seg[id] = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    seg[id] = min(seg[id<<1], seg[id<<1|1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return INT_MAX;

    if (u <= l && r <= v)
        return seg[id];

    int mid = (l+r)>>1;
    return min(get(id<<1, l, mid, u, v), get(id<<1|1, mid+1, r, u, v));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    a.resize(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v) << ' ';
    }
    return 0;
}