#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen = needle.length();
        if(nlen==0)return 0;
        int n = haystack.length();
        int i, j, k;
        if(n==0)return -1;
        bool match;
        for(i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                // 第一个匹配
                match = true;
                for(j=1, k=i+1;j<nlen && k<n;j++, k++){
                    if(haystack[k]!=needle[j]){
                        match = false;
                        break;
                    }
                }
                if(match && j==nlen){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s = Solution();
    string haystack = "hello", needle = "ll";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}