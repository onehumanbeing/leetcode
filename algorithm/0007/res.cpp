#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        /*
        假设我们的环境只能存储 32 位有符号整数，
        其数值范围是 [−231,  231 − 1]。
        根据这个假设，如果反转后的整数溢出，则返回 0。
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        */
        if(x<=INT_MIN|| x==0 || x>=INT_MAX)
            return 0;// 反转后一定溢出, 0一定0
        bool positive = x > 0;
        double res = 0;
        x = abs(x);
        stack<int> buffer; //栈特性
        double d = 1;
        while(x>=1){
            buffer.push(x%10);
            x /= 10;
        }
        while(!buffer.empty()){
            res += buffer.top() * d;
            if(positive&&res>INT_MAX)return 0;
            if((!positive)&&res*-1<INT_MIN)return 0;
            buffer.pop();
            d *= 10;
        }
        return positive ? res : res * -1;
    }
};

int main(){
    cout << Solution().reverse(1534236469) << endl;
    return 0;
}