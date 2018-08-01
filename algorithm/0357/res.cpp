#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        int ans = 10, val=9;
        // 排列问题
        for(int i=2;i<=n;i++){
            val *= (9-i+2); // 每次进位少一种组合
            ans += val;
        }
        return ans;
    }
};

int main(){
    return 0;
}