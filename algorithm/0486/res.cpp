#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // 动态规划
        int n = nums.size();
        if(n==0)return false;
        if(n<=2)return true;
        int dp[n][n]; // 代表从i到j序列中双方玩家的数值差
        for(int i=0;i<n;i++)
            dp[i][i] = nums[i]; // 当序列长度为1时，值为当前值
        for(int i=n-2;i>=0;i--) {
            for(int j=i+1; j<n;j++) {
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};

int main(){
    Solution s = Solution();
    int temp[4] = {1, 5, 233, 7};
    vector<int> a(temp, temp+4);
    cout << s.PredictTheWinner(a) << endl;
    return 0;
}