#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int max = prices.size();
        if(max==1)return 0;
        if(max==2)return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        for(int i=1;i<max;i++){
            res += prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0;
        }
        return res;
    }
};

int main(){
    return 0;
}