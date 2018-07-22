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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> res;
        if(!root)
            return res;
        vector<int> left, right;
        left = preorderTraversal(root->left);
        right = preorderTraversal(root->right);
        res.push_back(root->val);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};

int main(){
    return 0;
}