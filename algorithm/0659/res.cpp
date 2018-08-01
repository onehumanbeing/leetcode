#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return false;
        map<int, int> buffer;
        int minappear = 1;
        int temp;
        for(int i=0;i<n;i++){
            if(buffer.find(nums[i])==buffer.end()){
                buffer.insert(map<int, int>::value_type (nums[i], 1));
            } else {
                
            }
        }

    }
};

int main(){
    int a[] = {1,2,3,3,4,4,5,5};
    vector<int> b(a, a+8);
    cout << Solution().isPossible(b) << endl;
    return 0;
}