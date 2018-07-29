#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        int dp[n];
        int buffer;
        int temp;
        for(int i=0;i<n;i++){
            // 当前最大的子序列计算
            temp = 0;
            for(int j=i;j<n;j++){
                if(j==i){
                    temp += 1;
                    buffer = nums[j];
                    continue;
                }
                if(nums[j]<=buffer)
                    break;
                else{
                    temp += 1;
                    buffer = nums[j];
                    continue;
                }
            }
            if(i==0){
                dp[i] = temp;
            }
            else{
                dp[i] = max(dp[i-1], temp);
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution s = Solution();
    int arr[8] = {10,9,2,5,3,7,101,18};
    vector<int> a(arr, arr+8);
    cout << s.lengthOfLIS(a) << endl;
    return 0;
}