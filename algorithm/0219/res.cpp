#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> temp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(temp.find(nums[i])==temp.end()){
                temp.insert(map<int, int>::value_type (nums[i], i));
            } else {
                if(i-temp[nums[i]]<=k)return true;
                temp[nums[i]] = i;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}