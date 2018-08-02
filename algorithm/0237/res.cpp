#include <iostream>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // 从链表中，删除指定的节点，但又没有给出前指针
        // 所以先交换当前节点和下一节点的值，然后删除下一节点即可。
        if (!node || !node->next)
			return;
		node->val = node->next->val;
		node->next = node->next->next;
    }
};

int main(){
    return 0;
}