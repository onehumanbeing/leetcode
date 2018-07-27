#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        if(n==0)return true;
        int max = wordDict.size();
        if(max==0)return false;
        int temp, i, j, index;
        bool dp[n];
        for(i=0;i<n;i++)
            dp[i] = false;
        for(i=0;i<max;i++){
            temp = s.find(wordDict[i]);
            index = wordDict[i].length()-1;
            if(temp==0){
                // 第一个位置的元素被找到
                dp[index]=true;
            }
        }
        for(int i=0;i<n-1;i++){
            if(dp[i]){
                // 如果到这里是可以的
                for(j=0;j<max;j++){
                    temp = s.find(wordDict[j], i+1);
                    if(temp==i+1){
                        index = wordDict[j].length()+temp-1;
                        if(index==n-1)return true;
                        dp[index] = true;
                    }  
                }
            }
            // 如果为假，不处理
        }
        return dp[n-1]; //返回最后的值
    }
};

int main(){
    Solution s = Solution();
    string data = "a";
    string temp[5] = {"cats","dog","sand","and","cat"};
    vector<string> dict;
    dict.push_back("a");
    cout << s.wordBreak(data, dict) << endl;
    return 0;
}