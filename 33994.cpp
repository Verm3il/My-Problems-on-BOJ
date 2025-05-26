#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 0){
        cout << "No";
        return 0;
    }

    vector<pair<int,int> > ans[3];
    for (int i = 1; i <= n - 2; i += 2){
        ans[0].emplace_back(i, i + 1);
        ans[0].emplace_back(i, i + 2);
 
        ans[1].emplace_back(i, i + 1);
        ans[1].emplace_back(i + 1, i + 2);

        ans[2].emplace_back(i, i + 2);
        ans[2].emplace_back(i + 1, i + 2);
    }

    cout << "Yes\n";

    for (int i = 0; i < 3; i++){
        for (pair<int, int> e: ans[i]){
            cout << e.first << " " << e.second << '\n';
        }
    }

    return 0;
}
