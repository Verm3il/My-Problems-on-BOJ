#include <iostream>
#include <algorithm>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int Q;
    std::map<int, int> mp;
    std::cin >> Q;
    while (Q--){
        int op, i;
        std::cin >> op >> i;
        if (op == 1){
            int mx = std::max({mp[i], mp[i + 1], mp[i + 2], mp[i + 3]});
            mp[i] = mp[i + 1] = mp[i + 2] = mp[i + 3] = mx + 1;
        }
        else if (op == 2){
            mp[i] += 4;
        }
        else{
            std::cout << mp[i] << '\n';
        }
    }
    
    return 0;
}
