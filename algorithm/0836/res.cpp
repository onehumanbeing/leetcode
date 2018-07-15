#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (( (rec1[0]>rec2[0] && rec1[0]<rec2[2]) || (rec1[2]>rec2[0] && rec1[2]<rec2[2]) || (rec2[0]>rec1[0] && rec2[0]<rec1[2]) || (rec2[2]>rec1[0] && rec2[2]<rec1[2]) ) && ((rec1[1]>rec2[1] && rec1[1]<rec2[3]) || (rec1[3]>rec2[1] && rec1[3]<rec2[3]) || (rec2[1]>rec1[1] && rec2[1]<rec1[3]) || (rec2[3]>rec1[1] && rec2[3]<rec1[3])));
    }
};

//[0,0,1,1]
//[2,2,3,3]
// 大小于 没改回来

int main(){
    return 0;
}