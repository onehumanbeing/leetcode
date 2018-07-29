#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[1], nums[0]);
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

int main(){
    int temp[4] = {2,1,1,2};
    vector<int> a(temp, temp+4);
    Solution s = Solution();
    cout << s.rob(a) << endl;
    return 0;
}