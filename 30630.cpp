#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using pil = pair<int, ll>;

#define all(v) (v).begin(), (v).end()

#define X first
#define Y second

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define MAX(a,b) a=(((a)>(b))?(a):(b))
#define MIN(a,b) a=(((a)<(b))?(a):(b))

// end of def

int n, m;
pll v[101010];
int ans[101010];
pair<pll, int> qry[101010];
int seg[808080];

ll ccw(pll p1, pll p2, pll p3){
    return p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p1.Y * p2.X - p2.Y * p3.X - p3.Y * p1.X;
}

bool cmp(pll p1, pll p2){
    return p1.Y * p2.X < p2.Y * p1.X;
}

bool cmp2(pair<pll, int> p1x, pair<pll, int> p2x){
    pll p1 = p1x.X;
    pll p2 = p2x.X;
    return p1.Y * p2.X < p2.Y * p1.X;
}

void upd(int x, int s, int e, int i){
    if (e < i || i < s) return;
    if (s == e){
        seg[x]++; return;
    }
    int mid = (s + e) / 2;
    upd(x * 2, s, mid, i);
    upd(x * 2 + 1, mid + 1, e, i);
    seg[x] = seg[x * 2] + seg[x * 2 + 1];
}

int getSum(int x, int s, int e, int l, int r){
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return seg[x];
    int mid = (s + e) / 2;
    return getSum(x * 2, s, mid, l, r) + getSum(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
    fastio;
    cin >> n;
    vector<ll> vs;
    for (int i=0;i<n;i++) {
        cin >> v[i].X >> v[i].Y;
        vs.push_back(v[i].X);
    }
    sort(v, v + n, cmp);
    cin >> m;
    for (int i=0;i<m;i++){
        cin>>qry[i].X.X>>qry[i].X.Y;
        qry[i].Y = i;
        vs.push_back(qry[i].X.X);
    }
    sort(qry, qry + m, cmp2);
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());
    int r = (int)vs.size();
    int j = 0;
    for (int i=0;i<m;i++){
        while (j < n && ccw({0,0}, qry[i].X, v[j]) <= 0){
            upd(1, 1, r, lower_bound(all(vs), v[j].X) - vs.begin() + 1);
            j++;
        }
        ans[qry[i].Y] = getSum(1, 1, r, 1, lower_bound(all(vs), qry[i].X.X) - vs.begin() + 1);
    }
    for (int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
