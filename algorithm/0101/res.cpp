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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSymmetricCompare(root->left, root->right);  
    }
    
    bool isSymmetricCompare(TreeNode* left, TreeNode* right){
        if(!left && !right)return true;
        if(!left || !right)return false;
        if(left->val!=right->val)
            return false;
        return isSymmetricCompare(left->left, right->right) && isSymmetricCompare(left->right, right->left);     
    }
};

int main(){
    return 0;
}