#include <iostream>
#include <algorithm>

int main(){
    int N, K;
    std::string S;
    std::cin >> N >> K;
    std::cin >> S;
    int cnt['z' + 1];
    std::fill(cnt, cnt + 'z' + 1, 0);
  
    for (char &c: S){
        cnt[c]++;
    }
  
    int mn = 998'244'353;
    for (int i='a';i<='z';i++){
        mn = std::min(mn, cnt[i]);
    }

    bool ans = (mn <= K);
    std::cout << ans << '\n';
}
