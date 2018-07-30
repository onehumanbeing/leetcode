#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=1)
            return 0;
        int l = 0;
        int r = n-1;
        int min_height;
        int res = 0;
        while(l<r){
            min_height = min(height[l], height[r]);
            if(height[l]==min_height){
                // 最左侧比最右侧小
                while(++ l < r && height[l] < min_height)
                    res += min_height - height[l];
            }
            else{
                // 最右侧比最左侧小
                while(l < -- r && height[r] < min_height)
                    res += min_height - height[r];
            }
        }
        return res;
    }
};

int main(){
    int temp[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> a(temp, temp+12);
    cout << Solution().trap(a) << endl;
    return 0;
}