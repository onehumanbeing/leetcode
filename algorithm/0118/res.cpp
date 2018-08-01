#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if(numRows==0)return answer;
        vector<int> res(numRows+1 , 1);
        vector<int> buffer;
        int index;
        for(int i=1;i<=numRows+1;i++){
            if(i>=3){
                index = i%2==0 ? i/2 - 1: (i+1)/2 - 1;
                for(int j=index;j>=1;j--){
                    res[j] = res[j] + res[j-1];
                    res[i-j-1] = res[j];
                }
            }
            buffer.insert(buffer.end(), res.begin(), res.begin()+i);
            answer.insert(answer.end(), buffer);
            if(i==numRows){
                return answer;
            }
            buffer.clear();    
        }
    }
};

int main(){
    return 0;
}