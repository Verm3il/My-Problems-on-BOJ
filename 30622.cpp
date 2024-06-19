#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int, int>, int> num;
int par[101010];
long long minDist[101010];
int dx[] = {0,  0,  1,  1,  1, -1, -1, -1};
int dy[] = {1, -1, -1,  0,  1, -1,  0,  1};
const long long INF = 1e12;

int getPar(int x){
    if (x == par[x]) return x;
    par[x] = getPar(par[x]);
    return par[x];
}

void merge(int x, int y){ // y <- parent of x
    x = getPar(x);
    y = getPar(y);
    if (x == y) return;
    par[x] = y;
    minDist[y] = min(minDist[x], minDist[y]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    iota(par, par + n + 1, 0);
    fill(minDist, minDist + n + 1, INF);
    for (int i=1;i<=n;i++){
        int x_i, y_i;
        cin >> x_i >> y_i;
        num[{x_i, y_i}] = i;
        minDist[i] = abs(x_i) + abs(y_i);
        for (int k=0;k<8;k++){
            int nx = x_i + dx[k];
            int ny = y_i + dy[k];
            if (num[{nx, ny}]){ // target exists?
                merge(i, num[{nx, ny}]);
            }
        }
    }
    long long ans = 0;
    long long mx = 0;
    for (int i=1;i<=n;i++){
        if (getPar(i) == i){
            ans += minDist[i] * 2;
            mx = max(mx, minDist[i]);
        }
    }
    ans -= mx;
    cout << ans << '\n';
    return 0;
}
