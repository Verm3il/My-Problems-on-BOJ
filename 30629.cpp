#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pii = pair<int, int>;

#define all(v) (v).begin(), (v).end()

#define X first
#define Y second

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX(a,b) a=(((a)>(b))?(a):(b))
#define MIN(a,b) a=(((a)<(b))?(a):(b))

// end of def

int n, m;
int a[1010];

int main() {
    fastio;
    cin>>n>>m;
    if (m <= n - 1){
        for (int i=1;i<=n-m;i++) {
            a[i] = 0;
        }
        for (int i=n-m+1;i<=n;i++){
            a[i] = 1;
        }
    }
    else{
        a[1] = 0;
        int k = n / 2;
        for (int i=2;i<=k+1;i++){
            a[i] = 1;
        }
        int sum = k;
        for (int i=k+2;i<=n;i++){
            if (sum + k + 1 >= m){
                a[i] = m - sum;
                break;
            }
            a[i] = k + 1;
            sum += k + 1;
        }
    }
    for (int i=1;i<=n;i++){
        cout << a[i];
        if (i != n) cout << " ";
    }
    cout<<endl;
    return 0;
}
