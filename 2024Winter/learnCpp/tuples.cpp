#include<iostream>
#include<vector>
pair<int, int> divide(int n, int q){
    //n/q, n%q
    return {n/q, n%q};
}

int main(){
    auto ans = divide(10, 3);
    std::cout << std::format("10 / 3 = {} + {}/3", ans.first, ans.second);
    return 0;
}
