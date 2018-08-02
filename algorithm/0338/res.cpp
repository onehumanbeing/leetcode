#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for(int i=1; i<=num; ++i)
            ret[i] = ret[i>>1] + i%2;
        return ret;
    }
};


int main(){
    return 0;
}