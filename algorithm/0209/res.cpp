#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0]==s;
        int ans = nums[0] >= s ? 1 : n;
        int t, i, j;
        int beg = 0;
        bool match = false;
        int curr_val = nums[0];     
        for(i=1;i<n;i++){
            curr_val += nums[i];
            if(curr_val>=s){
                match = true;
                for(j=beg;j<i;j++){
                    // 往前滑动
                    if(curr_val-nums[j]<s){
                        // 无法滑动
                        break;
                    }
                    // 可以滑动
                    curr_val -= nums[j];
                    beg++;
                }
                t = i-beg+1;
                if(t<ans)ans=t;
            } else {
                // 当前序列不满足
                continue;
            }
        }
        return match ? ans : 0;
    }
};

int main(){
    int s[6] = {2,3,1,2,4,3};
    vector<int> a(s, s+6);

    cout << Solution().minSubArrayLen(7, a) << endl;
    return 0;
}