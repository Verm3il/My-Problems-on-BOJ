#include <bits/stdc++.h>

#include <random>

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
const ll inf = 4e18;

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
    int n; cin >> n;
    int ans = 0;
    for (int i=1;i<=n;i++){
        int x; cin >> x;
        for (int j=i;j<=n;j++){
            x = x - 1;
        }
        ans = max(ans, max(0, x));
    }
    cout<<ans<<endl;
    return 0;
}
