#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* curr, int val){
        val = 10 * val + curr->val;
        if(!curr->left && !curr->right){
            return val;
        }
        int res = 0;
        if(curr->left){
            res += dfs(curr->left, val);
        }
        if(curr->right){
            res += dfs(curr->right, val);
        }
        return res;
    }
};

int main(){
    return 0;
}