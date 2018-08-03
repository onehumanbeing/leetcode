#include <iostream>
#include <vector>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long int beg = 0, end = n, mid, t;
        while(beg<=end){
            mid = (beg+end)/2;
            t = guess(mid);
            if(t==0)return mid;
            else if(t==1){
                beg = mid + 1;
            }
            else if(t==-1){
                 end = mid - 1;
            }
        }
        return end;
    }
};

int main(){
    return 0;
}