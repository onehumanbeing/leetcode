#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int max_num = nums[0];
        int min_num = nums[0];
        int res = max_num;
        int res_max = nums[0];
        int res_min = nums[0];
        for(int i=1;i<n;i++){
            res_max = max(nums[i], max(min_num * nums[i], max_num * nums[i])); // 最小的数可能会变成最大的数
            res_min = min(nums[i], min(min_num * nums[i], max_num * nums[i])); // 最大的数可能会变成最小的数
            max_num = res_max; // 保证上述运算的数不变
            min_num = res_min;
            res = max(max_num, res);
        }
       return res;
    }
};

int main(){
    int temp[9] = {-1,-2,  -9,-6};
    vector<int> n(0);
    for(int i=0;i<4;i++){
        n.push_back(temp[i]);
    }
    Solution s = Solution();
    cout << s.maxProduct(n) << endl;
    return 0;
}