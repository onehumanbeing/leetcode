#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0?num==1?true:isPowerOfFour(num/4)&&num%4==0:false;
    }
};

int main(){
    return 0;
}