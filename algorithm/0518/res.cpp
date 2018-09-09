#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        int n = coins.size();
        for(int j=0;j<n;j++){
            for(int i=coins[j];i<=amount;i++){
                dp[i] += dp[i-coins[j]];
            }
        }
        /*
        for(int i=1; i<=amount; i++)
            cout << dp[i] << " ";
        cout << endl; */
        return dp[amount];
    }
};

int main(){
    int a[3] = {1, 2, 5};
    vector<int> r(a, a+3);
    cout << Solution().change(5, r);
    return 0;
}