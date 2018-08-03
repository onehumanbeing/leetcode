#include <iostream>
#include <vector>
using namespace std;

/*
    数组的长度不会超过20，并且数组中的值全为正数。
    初始的数组的和不会超过1000。
    保证返回的最终结果为32位整数。
*/

class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return S*-1==nums[0] || S==nums[0] ? 1 : 0;
        return dfs(nums, S, 0, 0, n);
    }

    int dfs(vector<int>& nums, int S, int curr, int index, int n){
        int res = 0;
        if(index+1>=n){
            // 最后一个元素
            if(curr+nums[index]==S){
                res++;
            }
            if(curr-nums[index]==S){
                res++;
            }
            return res;
        }
        // 不是最后一个，推
        /*
            if(curr>=S){
                return dfs(nums, S, curr-nums[index], index+1, n);
            }
            if(curr<=0){
                dfs(nums, S, curr+nums[index], index+1, n);
            }
        */
        return dfs(nums, S, curr+nums[index], index+1, n) + dfs(nums, S, curr-nums[index], index+1, n);
    }
};

int main(){
    int t[5] = {1,1,1,1,1};
    vector<int> a(t, t+5);
    cout << Solution().findTargetSumWays(a, 3) << endl;
    return 0;
}