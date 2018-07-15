#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.length();
        vector<int>vis(len);
        string ans;
        
        ans = dominoes;
        for(int i = 0;i < len;i++)
            vis[i] = 0;
      
    
        for(int i = 0;i < len;i++){
            for(int j = 0;j < len;j++){
                if(ans[j] == 'R' && ans[j + 1] == '.' && j < len - 1)
                    vis[j + 1] += 1;
                if(ans[j] == 'L' && ans[j - 1] == '.' && j >= 1)
                    vis[j - 1] -= 1;
            }
            int flag = 0;
            for(int j = 0;j < len;j++){
                if(dominoes[j] == '.' && vis[j] != 0){
                    if(vis[j] == 1)
                        ans[j] = 'R';
                    else
                        ans[j] = 'L';
                    flag = 1;
                }
            } 
            for(int i = 0;i < len;i++)
                vis[i] = 0;
            if(flag == 0)
                break;
        }
        return ans;
    }
};


int main(){
    Solution s = Solution();
    cout << s.pushDominoes(".L.R...LR..L..") << endl;
    return 0;
}