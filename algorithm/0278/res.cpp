#include <iostream>
#include <vector>
using namespace std;
/*
    给定 n = 5，并且 version = 4 是第一个错误的版本。

    调用 isBadVersion(3) -> false
    调用 isBadVersion(5) -> true
    调用 isBadVersion(4) -> true

    所以，4 是第一个错误的版本。 
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n<=0) return 0;
        long int beg=0, end=n;
        int mid, t;
        while(beg<=end){
            mid = (beg+end)/2;
            if(!isBadVersion(mid)){
                // 稳定版本，让版本号提前, 前面的都稳定不用看了
                beg = mid + 1;
            } else {
                // 坏掉的版本，后面的一定都坏了不用看了
                end = mid - 1;
            }   
        }
        return beg;
    }
};

int main(){
    return 0;
}