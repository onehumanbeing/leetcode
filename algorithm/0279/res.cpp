#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n==0)return 0;
        int index = (int)sqrt(n);
        if(index * index == n) return 1;
        // int end = index * index; // 不会用到比这个大的完全平方数
        int res = n;
        for(int i = index; i >= 1; i--) {
            int cur = 0, num = n, t = i*i;
            while(num - t >= 0) {
                num -= t;
                //cout << num << " " << t << endl;
                cur++;
            }
            if(cur < res){
                res = min(numSquares(num)+cur, res);
            }
        }
        return res;
    }
};

int main(){
    cout << Solution().numSquares(8) << endl;
    return 0;
}