#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {        
        if(p.empty())
            return s.empty();
        if(p.length()==1){
            if(s.length() != 1)
                return false;
            return (s[0] == p[0]) || p[0] == '.';
        }
        if(p[1]=='*'){
            int slen = s.length();
            int plen = p.length();
            for(int i=0; i<slen;i++){
                if(((s[i]!=p[0]) && p[0] != '.') || isMatch(s.substr(i), p.substr(2))){ 
                    // 如果当前栈顶字符不匹配，或者剩余内容可以匹配，这里可以优化
                    //cout << s.substr(i) << " " << p.substr(2) << endl;
                    return isMatch(s.substr(i), p.substr(2));
                }
            }
            return isMatch("", p.substr(2));
        }
        if(s.empty()){
            return false;
        }
        return (s[0] == p[0]) || p[0] == '.' ? isMatch(s.substr(1), p.substr(1)) : false;
    }
};

int main(){
    string s, p;
    Solution o = Solution();
    s = "aaaasd";
    p = "ab*a*c*aasd";
    cout << o.isMatch(s, p) << endl;
    return 0;
}