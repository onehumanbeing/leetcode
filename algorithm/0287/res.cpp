#include <iostream>
#include <vector>
using namespace std;

/*
    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。
    时间复杂度小于 O(n2) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int max = nums.size();
        for(int i=0;i<max-1;i++){
            for(int j=i+1;j<max;j++){
                if(nums[i]==nums[j])return nums[i];
            }
        }
        return 0;
    }
};

int main(){

    return 0;
}