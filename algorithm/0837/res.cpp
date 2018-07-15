#include <iostream>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==1){
            // one turn
            return (double)N/(double)W;
        }
        return (double)(1-new21GameReal(N, K, W, 1));
    }

    double new21GameReal(int N, int K, int W, int T) {
        if(W<K){
            // 在所有的情况下都需要抽卡
            return new21GameReal(N, K, W+W, T+1);
        }
        // 存在不用抽卡和需要抽卡的两种情况
        
        

    }
};

int main(){
    Solution s = Solution();
    cout << s.new21Game(21, 17, 10) << endl;
}