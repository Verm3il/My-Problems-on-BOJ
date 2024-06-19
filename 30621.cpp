#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int n;
long long t[101010];
long long b[101010];
long long c[101010];
long long dp[101010];
long long pf[101010];

int main() {
    fastio;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> t[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int i=1;i<=n;i++){
        int j = lower_bound(t + 1, t + i + 1, t[i] - b[i]) - t - 1;
        dp[i] = pf[j] + c[i];
        pf[i] = max(pf[i - 1], dp[i]);
    }
    cout << pf[n] << endl;
    return 0;
}
