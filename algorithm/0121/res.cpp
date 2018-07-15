#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = prices.size();
        int res = 0;
        int temp = 0;
        if(max==1)return 0;
        if(max==2)return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        for(int i=0;i<max-1;i++){
            for(int j=i;j<max;j++){
                temp = prices[j]-prices[i];
                if(temp>res){
                    res = temp;
                }
            }
        }
        return res;
    }
};

int main(){
    return 0;
}