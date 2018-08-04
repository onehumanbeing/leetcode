#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector< vector<char> > & matrix) {
        int m = matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        if(n==0)return 0;
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, dfs(matrix, i, j, 0, m, n));
            }
        }
        return res;
    }

    int dfs(vector< vector<char> > & matrix, int x, int y, int r, int m, int n){
        if(x+r>=m || y+r>=n)return -1;
        for(int i=0;i<=r;i++){
            if(matrix[x+r][y+i]=='1' && matrix[x+i][y+r]=='1')
                continue;
            return -1;
        }
        // 如果通过当前
        int next = dfs(matrix, x, y, r+1, m, n);
        if(next == -1){
            // 当前层是最大的了
            return (r+1)*(r+1);
        }
        return next;
    }
};

int main(){
    char t[5][5] = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector< vector<char> > b(5 ,vector<char>(5));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            b[i][j] = t[i][j];
    cout << Solution().maximalSquare(b) << endl;
    return 0;
}