#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<str.length();i++)
            str[i] |= 32;
        return str;
    }
};

int main(){
    Solution s = Solution();
    cout << s.toLowerCase("HellO") << endl;
    return 0;
}