#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0)return false;
        if(num==1)return true;
        int beg = 0, end = num, mid, res, t;
        while(beg<=end){
            if(beg==end)return beg%mid==0 && beg == num/beg;
            if(beg+1==end)return false; // 一个比num小，一个比num大，中间没东西了，不用比了
            mid = (end-beg)/2 + beg;
            //res = mid * mid; // 这里可能溢出了
            res = num/mid;
            t = num%mid;
            if(t==0 && mid==res) return true;
            if(mid>res || (mid==res)&&(t!=0)){
                end = mid;
            } else {
                beg = mid;
            }
        }
        return false;
    }
};

int main(){
    cout << Solution().isPerfectSquare(808201) << endl;
    return 0;
}