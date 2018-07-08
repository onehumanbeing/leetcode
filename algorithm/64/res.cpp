#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> & grid) {
        int m = grid.size();// 非负整数的 m x n 网格
        if(m==0){
            return 0;
        }
        int n = grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else if(i==0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else{
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    // 官网又挂了。
    vector<vector<int>> g(0);
    /*
        [1,3,1],
        [1,5,1],
        [4,2,1]
    */
    //g.push_back({1,3,1});
    //g.push_back({1,5,1});
    //g.push_back({4,2,1});
    //Solution s = Solution();
    //cout << s.minPathSum(g) << endl;
    return 0;
}  