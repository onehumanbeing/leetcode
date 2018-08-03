#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> brackets;
        stack<int> looper;
        int n = s.length();
        if(n<=1)return s;
        int loop = -1;
        int start;
        string res = "", temp;
        for(int i=0;i<n;i++){
            int t = s[i]-'0';
            if(t>=0 && t<=9){
                //数字
                if(loop==-1){
                    loop = t;
                } else {
                    loop = loop * 10 + t;
                }
                continue;
            }
            if(s[i]=='['){
                looper.push(loop);
                brackets.push(i);
                loop = -1;
                continue;
            } 
            if(s[i]==']'){
                // 由于一定是标准的，这里栈一定非空
                if(brackets.size()==1){
                    // 和最左边匹配上了
                    start = brackets.top();
                    temp = decodeString(s.substr(start+1, i-start-1));
                    for(int j=0;j<looper.top();j++){
                        res += temp;
                    }
                }
                // 不是，没匹配好，这是一种懒的方法。
                brackets.pop();
                looper.pop();
                continue;
            }
            if(brackets.empty())
                res += s[i];
        }
        return res;
    }
};

int main(){
    string s = "3[a]2[bc]";
    cout << Solution().decodeString(s) << " " << "aaabcbc" << endl;
    /*
    s = "3[a2[c]]";
    cout << Solution().decodeString(s) << " " << "accaccacc" << endl;
    s = "2[abc]3[cd]ef";
    cout << Solution().decodeString(s) << " " << "abcabccdcdcdef" << endl;
    */
    //s = "100[leetcode]";
    //cout << Solution().decodeString(s) << endl;
    return 0;
}