#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int a=0, b=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(board[i][j]=='X'){
                    a++;
                }
                if(board[i][j]=='O'){
                    b++;
                }

            }
        if(a==0 && b>=1)return false; // 不能先O
        if(abs(b-a)>1) return false; // 数量相差不大于1
        if(b>a)return false; // 后手不可能多于先手
        //统计赢
        int x = 0, o = 0;
        for(int i=0;i<3;i++){
            if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')x++;
            if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')o++;

            if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')x++;
            if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')o++;
        }
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')x++;
        if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')o++;
        if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')x++;
        if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')o++;
        if(x>=1 && o>=1) return false; // 不能同时赢
        if(x>=1 && a-b!=1) return false; // 赢了必须结束游戏
        if(o>=1 && a!=b) return false; // 赢了必须结束游戏
        // 所有的验证完毕
        return true;
    }
};

int main(){
    return 0;
}