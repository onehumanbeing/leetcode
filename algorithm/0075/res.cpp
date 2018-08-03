#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1,j = -1,k = -1;
        for(int m = 0; m < nums.size(); m++){
            if(nums[m] == 0){
                nums[++k] = 2;
                nums[++j] = 1;
                nums[++i] = 0;
            }else if(nums[m] == 1){
                nums[++k] = 2;
                nums[++j] = 1;
            }else{
                nums[++k] = 2;
            }
        }
    }
};


int main(){
    return 0;
}