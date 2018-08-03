#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0)return 0;
        if(s[0]=='0')return 0; // 第一个数为0我觉得不能解码
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int t;
        for(int i=1;i<n;i++){
            t = (s[i-1]-'0') * 10 + (s[i]-'0');
            if(t>=10 && t<= 26){
                // 说明是可以解码出2位之前的
                dp[i+1] += dp[i-1];
            }
            if(t%10!=0){
                // 对于 10 ，20来说，有0，0不能单独解码
                dp[i+1] += dp[i];
            }
        }
        return dp[n];
    }
};

int main(){
    cout << Solution().numDecodings("110") << endl;
    return 0;
}