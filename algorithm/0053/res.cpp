#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // sum[i]表示从i开始的最大子串和，
        // 则有递推公式：sum[i] = max{nums[i], nums[i] + sum[i+1]}
        int n = nums.size();
        int sum = nums[n - 1];
        int res = sum;
        for (int i = n - 2; i >= 0; i--) {
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }
        return res;
    }
};

int main(){
    int temp[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> n(0);
    for(int i=0;i<9;i++){
        n.push_back(temp[i]);
    }
    Solution s = Solution();
    cout << s.maxSubArray(n) << endl;
    return 0;
}