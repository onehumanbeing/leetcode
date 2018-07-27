#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        if(n==0)return res;
        if(n==1)return strs[0];
        char buffer;
        int index = 0;
        while(1){
            buffer = strs[0][index];
            for(int i=1;i<n;i++){
                if(strs[i].length()<=index) return res;
                if(strs[i][index]!=buffer){
                    return res;
                }
            }
            res += buffer;
            index++;
        }
    }
};

int main(){
    return 0;
}