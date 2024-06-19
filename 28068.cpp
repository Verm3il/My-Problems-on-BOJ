#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ld, ld> pdd;
typedef pair<pdd, pdd> ppdd;
typedef pair<ld, int> pdi;

const ld eps = 1e-12;
const int mod = 1e9 + 7;
const int inf = 1e9;

#define all(v) (v).begin(),(v).end()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define X first
#define Y second

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define MAX(a, b) a = (((a)<(b))?(b):(a))
#define MIN(a, b) a = (((a)>(b))?(b):(a))


// end of def



int main() {
    fastio;
    int n; cin>>n;
    vector<pii> L, R;
    for (int i=1;i<=n;i++){
        int l, r; cin>>l>>r;
        if (l < r) L.emplace_back(l, -r);
        else R.emplace_back(r, -l);
    }
    sort(all(L)); sort(all(R)); reverse(all(R));
    ll now = 0;
    int yes = 1;
    for (auto &[l, r]: L){
        now -= l;
        yes &= now >= 0;
        now -= r;
    }
    for (auto &[l, r]: R){
        now += r;
        yes &= now >= 0;
        now += l;
    }
    cout << yes << endl;

    return 0;
}
