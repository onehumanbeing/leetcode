#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(); // 偶数
        if(n<=2)return true;
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i] = piles[i];
        }
        for(int i=n%2-1;i>=1;i--)
        {
            for(int j=n%2;j<n-1;j++){
                dp[i-1][j+1] = max(piles[i-1] - dp[i][j+1], piles[j+1] - dp[i-1][j]);
            }
        }
        cout << dp[0][n-1] << endl;
        return dp[0][n-1] > 0;
    }
};

int main(){
    int temp[4] = {5, 3, 4, 5};
    vector<int> a(temp, temp+4);
    cout << Solution().stoneGame(a) << endl;
    return 0;
}