#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = s.length();
        if(m<=1) return m;
        int buffer;
        int res = 1;
        map<char, int> temp;
        for(int i=0;i<m;i++){
            temp.clear();
            buffer = 0;
            for(int j=i;j<m;j++){
                if(temp.find(s[j])==temp.end() || j==0){
                    // 说明没有重复
                    temp.insert(map<char, int>::value_type (s[j], j));
                    buffer++;
                    continue;
                }
                break;
            }
            res = max(res, buffer);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}