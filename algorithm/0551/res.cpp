#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a=0, l=0, ml=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L'){
                l++;
                if(ml<l)ml = l;
            }
            else{
                l=0;
            }
            if(s[i]=='A'){
                a++;
            }
        }
        return a<=1 && ml<=2;
    }
};

int main(){
    return 0;
}