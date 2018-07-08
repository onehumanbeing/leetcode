#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> temp;
        vector<int> res(0);
        int i;
        for(i=0;i<=nums.size()-1;i++){
            temp.insert(map<int, int>::value_type (target-nums[i], i));
        }
        for(int i=0;i<=nums.size()-1;i++){
            if(temp.find(nums[i])!=temp.end()){
                if(temp[nums[i]]!=i){
                    res.push_back(i);
                    res.push_back(temp[nums[i]]);
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    // pass no case 
    return 0;
}