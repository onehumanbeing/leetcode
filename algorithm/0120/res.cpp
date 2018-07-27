#include <iostream>
#include <vector>
using namespace std;

// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); //层数
        if(n==0)return 0;
        if(n==1)return triangle[0][0];
        vector<int> sum(triangle[n-1]); // 使用三角形最下面一层当作初始化
        for(int i=n-2;i>=0;i--){
            //i 从 倒数第二层开始
            for(int j=0;j<i+1;j++){
                // j 扫描 每列 左右对比
                if(sum[j]<sum[j+1]){
                    // 左边的小
                    sum[j] += triangle[i][j]; // 类加
                } else {
                    sum[j] = triangle[i][j] + sum[j+1];
                }
            }
        }
        return sum[0];
    }
};

int main(){
    return 0;
}