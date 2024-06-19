#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define X first
#define Y second

#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl '\n'

// end of def

int T;
int l[202020];
int r[202020];


int main(){
    fastio;
    int ans = 0;
    cin>>T;
    for (int i=1;i<=T;i++) {
        cin>>l[i]>>r[i];
        if (l[i] != 0 && l[i] == l[i - 1]){
            ans++; // 조건 1: 왼쪽 노브
        }
        if (r[i] != 0 && r[i] == r[i - 1]){
            ans++; // 조건 1: 오른쪽 노브
        }
        if (l[i] != 0 && r[i] != 0 && l[i] == r[i]){
            ans++; // 조건 2
        }
    }
    cout<<ans<<endl;
    return 0;
}
