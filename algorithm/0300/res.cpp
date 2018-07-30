#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        vector<int> dp(n, 1);
        int buffer;
        int temp;
        int res = 0;
        // 注意子串和子序列的区别
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    int arr[8] = {10,9,2,5,3,7,101,18};
    vector<int> a(arr, arr+8);
    cout << s.lengthOfLIS(a) << endl;
    return 0;
}