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


int n;
int a[403];
ll dp[403][403];
ll p[403][403];

ll f(int l, int r){
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 1e18;
    for (int i=l;i<=r-1;i++){
        dp[l][r] = min(dp[l][r], f(l, i) + f(i + 1, r) + p[l][i] + p[i + 1][r]);
    }
    return dp[l][r];
}

int main() {
    fastio;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            for (int k=i;k<=j;k++){
                p[i][j] = max(p[i][j], (ll)a[k]);
            }
        }
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j] = -1;
    cout << f(1, n) << endl;
    return 0;
}
