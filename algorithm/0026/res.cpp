#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int max = nums.size();
        if(max<=1)return max;
        if(max==2){
            return nums[1]==nums[0] ? 1 : 2;
        }
        int index = 1;
        int buffer = nums[0];
        bool run = false;
        for(int i=1;i<max;i++){
            if(run && nums[i]==buffer)
                continue;
            if(nums[i]==buffer){
                run = true;
                continue;
            }
            nums[index++] = nums[i];
            buffer = nums[i];
            run = false;
        }
        return index;

        
        
    }
};

int main(){
    return 0;
}