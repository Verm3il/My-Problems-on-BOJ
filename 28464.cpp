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


int a[202020];


int main() {
    fastio;
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int f = 0;
    int s = 0;
    for (int i=0;i<n;i++){
        if ((i + 1) <= (n / 2)) f += a[i];
        else s += a[i];
    }
    cout << f << " " << s << endl;
    return 0;
}
