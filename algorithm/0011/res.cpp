#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int res = 0;
        while(l<r){
            res = max(res, (r-l)*min(height[l], height[r]));
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return res;
    }
};

int main(){
    int temp[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> a(temp, temp+9);
    Solution s = Solution();
    cout << s.maxArea(a) << endl;
    return 0;
}