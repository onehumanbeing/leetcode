#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if(n==0)return false;
        if(n==1){
            return s[0] <= '9' && s[0] >= '0';
        }
        
    }
};

int main(){
    return 0;
}