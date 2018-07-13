#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int i = alen - 1; // index of a
        int j = blen - 1; // index of b
        bool mov = false;
        string res = "";
        while(!(i<0 && j<0)){
            if(i<0){
                // a is over
                if(mov){
                    // 1
                    if(b[j]=='1'){
                        // 1 1
                        res = "0" + res;
                    }else{
                        // 1 0
                        res = "1" + res;
                        mov = false;
                    }
                }else{
                    // 0
                    if(b[j]=='1'){
                        // 0 1
                        res = "1" + res;
                    }else{
                        // 0 0
                        res = "0" + res;
                    }
                }
                j--;
                continue;
            }
            if(j<0){
                // b is over
                if(mov){
                    // 1
                    if(a[i]=='1'){
                        // 1 1
                        res = "0" + res;
                    }else{
                        // 1 0
                        res = "1" + res;
                        mov = false;
                    }
                }else{
                    // 0
                    if(a[i]=='1'){
                        // 0 1
                        res = "1" + res;
                    }else{
                        // 0 0
                        res = "0" + res;
                    }
                }
                i--;
                continue;
            }
            // i, j >= 0
            if(a[i] xor b[j]){
                // xor 0 1 or 0 1
                if(mov){
                    // 0 1 1
                    res = "0" + res;
                }else{
                    // 0 1 0
                    res = "1" + res;
                }
                i--;
                j--;
                continue;
            }
            if(a[i]=='0' && b[j]=='0'){
                // 0 0
                if(mov){
                    // 0 0 1
                    res = "1" + res;
                    mov = false;
                }
                else{
                    // 0 0 0
                    res = "0" + res;
                }
                i--;
                j--;
                continue;
            }
            if(a[i]=='1' && b[j]=='1'){
                // 1 1
                if(mov){
                    // 1 1 1
                    res = "1" + res;
                }else{
                    // 1 1 0
                    res = "0" + res;
                    mov = true;
                }
                i--;
                j--;
                continue;
            }
        }
        if(mov){
            res = "1" + res;
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    cout << s.addBinary("11", "1")<< endl;
    return 0;
}