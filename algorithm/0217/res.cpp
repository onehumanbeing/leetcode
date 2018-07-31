#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(temp.find(nums[i])==temp.end()){
                temp.insert(map<int, int>::value_type (nums[i], 0));
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}