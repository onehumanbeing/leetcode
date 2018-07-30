#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)return s;
        bool dp[n][n];
        int start;
        int maxlength;
        // 子串长度为1和为2的初始化
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            if(i < n - 1 && s[i]==s[i+1]){
                dp[i][i + 1] = true;
                start = i;
                maxlength = 2;
            }
        }
        // 使用上述结果可以dp出子串长度为3~len -1的子串
        for(int strlen = 3; strlen < n; strlen++){
            for(int i = 0; i <= n - strlen; i++){
                int j = i + strlen - 1; // 子串结束的位置
                if(dp[i + 1][j - 1] && s[i] == s[j]){
                    dp[i][j] = true;
                    maxlength = strlen;
                    start = i;
                }
            }
        }
        if(maxlength > 0)
            cout << start << " " << maxlength << endl;
            return s.substr(start, maxlength);
        return NULL;
        
    }
};

int main(){
    cout << Solution().longestPalindrome("ccc") << endl;
    return 0;
}