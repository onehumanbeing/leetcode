#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) return -1;
        vector<int> cnt(amount+1, 0x7fffffff); // 初始化不可达到的极大值
        cnt[0] = 0;
        for(int i=1; i<=amount; ++i) {
            for(int j=0; j<coins.size(); ++j) {
                if(i>=coins[j] && cnt[i - coins[j]] != 0x7fffffff) {
                    cnt[i] = min(cnt[i], cnt[i-coins[j]] + 1);
                }
            }
        }
        return (cnt[amount]==0x7fffffff) ? -1 : cnt[amount];
    }
};


int main(){
    return 0;
}