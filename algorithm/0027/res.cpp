#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int max = nums.size();
        if(max==0)return 0;
        int index = 0;
        for(int i=0;i<max;i++){
            if(nums[i]==val){
                continue;
            }
            nums[index++] = nums[i];
        }
        return index;
    }
};

int main(){
    return 0;
}