#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int max = nums.size();
        if(max==0){
            return 0;
        }
        if(max<=2){
            return max;
        }
        int index = 0;
        int buffer = 0;
        int counter = 0;
        bool run = false;
        for(int i=0;i<max;i++){
            if(i==0){
                // first time
                buffer = nums[i];
                nums[index++] = nums[i];
                counter++;
                continue;
            }
            if(run && nums[i]==buffer){
                continue;
            }
            if(nums[i]==buffer){
                if(counter>=2){
                    // too much current num
                    run = true;
                    continue;
                }
                else{
                    counter++;
                    nums[index++] = nums[i];
                    continue;
                }
            }
            // different
            counter = 1;
            run = false;
            nums[index++] = nums[i];
            buffer = nums[i];
            continue;
        }
        return index;
    }
};

int main(){
    return 0;
}