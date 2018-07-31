#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x<10)return true;
        int nums[32];
        int t = x;
        int curr;
        int len = 0;
        while(t){
            curr = t % 10;
            nums[len++] = curr;
            t /= 10;
        }
        int l = 0, r = len - 1;
        while(l<=r){
            if(nums[l]!=nums[r])
                return false;
            l++, r--;
        }
        return true;   
    }
};

int main(){
    cout << Solution().isPalindrome(111222) << endl;
    return 0;
}