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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSubtreeResult(s, t)){
            return true;
        }
        bool l=false, r=false;
        if(s->left){
            l = isSubtree(s->left, t);
        }
        if(s->right){
            r = isSubtree(s->right, t);
        }
        return l||r;
    }
    
    bool isSubtreeResult(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val==t->val){
            return isSubtreeResult(t->left, s->left) && isSubtreeResult(t->right, s->right);
        }
        return false;
    }
};

int main(){
    return 0;
}