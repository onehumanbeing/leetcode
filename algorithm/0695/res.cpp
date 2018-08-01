#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 
    int dfs(vector<vector<int>>& grid, int x0, int y0, int m, int n){
        int sum=1;
        grid[x0][y0] = 0; //当前元素设置为0，避免再次搜索到
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // 上下左右
 
        for(int i=0; i<4; i++){
            int x = x0 + dir[i][0];
            int y = y0 + dir[i][1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                sum += dfs(grid, x, y, m, n); // 判断边界
        }
        return sum;
 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int mx = 0, n, m;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)   
                    mx = max(dfs(grid, i, j, m, n), mx);// 找到最大岛屿
            }
        return mx;
    }
};

int main(){
    vector<int> t(3, 1);
    int b[3] = {0, 1, 0};
    vector<int> bb(b, b+3);
    vector< vector<int> > a;
    a.push_back(t);
    a.push_back(bb);
    cout << Solution().maxAreaOfIsland(a) << endl;
    return 0;
}