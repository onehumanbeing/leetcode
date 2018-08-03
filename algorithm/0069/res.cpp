#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        if(x==1)return 1;
        double beg=0, end=x, mid=1, ans=0;
        while((ans>=x?ans-x:x-ans)>0.000001){
            mid = (beg+end)/2;
            ans = mid * mid;
            //cout << ans << endl;
            if(ans>=x){
                end = mid;
            } else {
                beg = mid;
            }
        }
        return (int)mid;
    }
};

int main(){
    cout << Solution().mySqrt(8) << endl;
    return 0;
}