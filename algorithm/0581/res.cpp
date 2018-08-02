#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        if(n==2){
            return nums[1] >= nums[0] ? 0 : 2;
        }
        int max_index = -1, min_index = -1;
        int max_num = nums[0], min_num = nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[n-1-i]>min_num){
                min_index = n-1-i;
            } else {
                min_num = nums[n-1-i];
            }
            if(nums[i]<max_num){
                max_index = i;
            } else {
                max_num = nums[i];
            }
        }
        return r-l+1
        
    }
};

int main(){
    int b[7] = {1, 2, 3, 5, 4, 7};
    vector<int> a(b, b+6);
    cout << Solution().findUnsortedSubarray(a) << endl;;
    return 0;
}