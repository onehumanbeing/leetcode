#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        vector<int> sum(10001, 0);
        for(int i=0;i<n;i++)
            ++sum[nums[i]];
        vector<int> dp(sum.size()+1,0);
        dp[1] = sum[1]*1;
        for(int i =2; i <= 10000;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+sum[i]*i);
        }
        return dp[10000];
        // 同 198
    }
};

int main(){
    return 0;
}