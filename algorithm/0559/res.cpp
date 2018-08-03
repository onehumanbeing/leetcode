#include <iostream>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        int res = 0;
        int t;
        for(int i=0;i<root->children.size();i++){
            t = maxDepth(root->children[i]);
            if(t>res)res=t;
        }
        return res + 1;
    }
};

int main(){
    return 0;
}