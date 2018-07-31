#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int n = s.size();
        int j = 0;
        if(numRows==1)return s;
        int move = 2 * numRows - 2;
        bool fix = false;
        for(int i=0;i<numRows;i++){
            j = 0;
            while(1){
                fix = false;
                if(i!=0 && i!=numRows-1){
                    if(j-i>=0 && j-i<n){
                        res += s[j-i];
                        fix = true;
                    }
                    if(j+i<n && j+i>=0){
                        res += s[j+i];
                        fix = true;
                    }
                }
                else{
                    if(j+i<n && j+i>=0){
                        res += s[j+i];
                        fix = true;
                    }
                }
                if(!fix)
                    break;
                j += move;
            }
        }
        return res;
    }
};

int main(){
    cout << Solution().convert("ABCD", 3) << endl;
    return 0;
}