#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int old = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 || nums[i]==old){
                continue;
            }
            if(old>0 && nums[i]-old!=1){
                return old + 1;
            }
            if(old<0 && nums[i]!=1){
                return 1;
            }
            old = nums[i];
        }
        return old > 0 ? old + 1 : 1;
    }
};

int main(){
    return 0;
}