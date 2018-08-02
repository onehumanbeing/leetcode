#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int plen = p.length();
        int slen = s.length();
        if((s=="" && p=="") || p=="*")return true;
        if(s==""){
            for(int i=0;i<plen;i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        // 上面为一些结算状态
        if(p[0]=='?'){
            return isMatch(s.substr(1), p.substr(1));
        }
        if(p[plen-1]=='?'){
            return isMatch(s.substr(0, slen-1), p.substr(0, plen-1));
        }
        if(p[0]!='*'){
            return s[0]==p[0] ? isMatch(s.substr(1), p.substr(1)) : false;
        }
        if(p[plen-1]!='*'){
            return s[slen-1]==p[plen-1] ? isMatch(s.substr(0, slen-1), p.substr(0, plen-1)) : false;
        }
        if(plen>=2 && p[0]=='*' && p[1]=='*'){
            int index = 1;
            for(int i=2;i<plen;i++){
                if(p[i]!='*')break;
                index++;
            }
            return isMatch(s, p.substr(index));
        }
        if(p[0]=='*'){
            if(isMatch(s, p.substr(1)))
                return true; // 空匹配
            for(int i=1;i<s.length();i++){
                if(isMatch(s.substr(i), p.substr(1)))
                    return true;
            }
            return false;
        }    
    }
};

int main(){
    string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}