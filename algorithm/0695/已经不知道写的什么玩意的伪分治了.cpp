#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector< vector<int> >& grid) {
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();

        int index = 0;
        int ans = 0;
        int buffer[1668][3]; // 缓存部分，当前块值，开始位置，结束位置，缓冲区开大 5000/3
        int bottom = 0; // 只能遍历上一层的缓存内容

        bool run = false;
        int temp;
        int start;
        int it;

        bool is_run = false;
        int curr_index = 0;
        int curr_buffer [34][2];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(run && grid[i][j]==0){
                    it = i>=2 ? bottom : 0;
                    for(int k=it;k<index;k++){
                        // 判断是否交错
                        if((start<=buffer[k][1] && j-1>=buffer[k][1]) || (start<=buffer[k][2] && j-1>=buffer[k][2]) || (start>=buffer[k][1] && j-1<=buffer[k][2])){
                            // 当前岛屿段有交错位置, 增加面积
                            if(curr_index>=1){
                                // 返回对比增加
                                for(int p=0;p<curr_index;p++){
                                    if(curr_buffer[p][1]==k){
                                        // 存在其他岛屿交错
                                        buffer[curr_buffer[p][0]][0] += temp;
                                        temp = buffer[curr_buffer[p][0]][0];
                                    }
                                }
                            }
                            temp += buffer[k][0];
                            curr_buffer[curr_index][0] = index;
                            curr_buffer[curr_index++][1] = k;
                        }
                    }
                    buffer[index][1] = start;
                    buffer[index][2] = j-1;
                    buffer[index++][0] = temp;
                    if(temp>=ans)
                        ans = temp;
                    run = false;
                    continue;
                }
                if(run && grid[i][j]==1){
                    temp++;
                    continue;
                }
                if(grid[i][j]==1 && !run){
                    // init
                    temp = 1;
                    run = true;
                    start = j;
                    continue;
                }
            }
            // 处理结束的事情
            if(run){
                it = i>=2 ? bottom : 0;
                for(int k=it;k<index;k++){
                    // 判断是否交错
                    if((start<=buffer[k][1] && n-1>=buffer[k][1]) || (start<=buffer[k][2] && n-1>=buffer[k][2]) || (start>=buffer[k][1] && n-1<=buffer[k][2])){
                        temp += buffer[k][0];
                    }
                }
                buffer[index][1] = start;
                buffer[index][2] = n-1;
                buffer[index++][0] = temp;
                if(temp>=ans){
                    ans = temp;
                }
                run = false;
            }
            // 处理结束
            bottom = index;
            is_run = false;
            curr_index = 0;
        }
        return ans;
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