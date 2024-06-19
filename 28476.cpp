#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;
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


ll n;
pll px;
pll a[2020];
vector<pll> v;


ll ccw(pll x, pll y, pll z) {
    return x.X * y.Y + y.X * z.Y + z.X * x.Y - x.Y * y.X - y.Y * z.X - z.Y * x.X;
}


pll operator + (const pll x, const pll y) {
    return { x.X + y.X, x.Y + y.Y };
}

pll operator - (const pll x, const pll y) {
    return { x.X - y.X, x.Y - y.Y };
}

ll operator * (const pll x, const pll y) {
    return x.X * y.X + y.Y * x.Y;
}

ll operator / (const pll x, const pll y) {
    return x.X * y.Y - x.Y * y.X;
}

bool cmp (const pll x, const pll y) {
    pll pdx = x - px;
    pll pdy = y - px;
    if ((pdx.X < 0) != (pdy.X < 0)) {
        return pdx.X < pdy.X;
    }
    if (pdx.X == 0 && pdy.X == 0) return pdx.Y < pdy.Y;
    return pdx.X * pdy.Y > pdx.Y * pdy.X;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        v.clear();
        px = a[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            v.emplace_back(a[j]);
        }
        sort(v.begin(), v.end(), cmp);
        int k = 0;
        int c = 0;
        for (int j=0;j<n-1;j++){
            while(ccw(a[i], v[j], v[k%(n-1)]) >= 0 && c < n - 1){
                k++; c++;
            }
            ans += (c - 1) * (c - 2) / 2;
            c--;
        }
    }
    // # of convex:  A
    // # of concave: B
    ll apb = n * (n - 1) * (n - 2) * (n - 3) / 4 / 3 / 2;   // apb: A + B
    ll A = ans - apb * 3;    // ans: 4A + 3B
    cout << A * 2 << endl;
    return 0;
}

