#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1 , 1);
        if(rowIndex<=1)return res;
        for(int i=3;i<=rowIndex+1;i++){
            int index = i%2==0 ? i/2 - 1: (i+1)/2 - 1;
            for(int j=index;j>=1;j--){
                res[j] = res[j] + res[j-1];
                res[i-j-1] = res[j];
            }
        }
        return res;
    }
};

int main(){
    vector<int> temp = Solution().getRow(1);
    for(int i=0;i<temp.size();i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}