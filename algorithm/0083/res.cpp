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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        int record = head->val;
        ListNode *q=head, *p=head->next;
        // 没有删掉head的需求
        for(;p!=NULL;p=p->next){
            if(p->val==record){
                // 等于当前，删
                q->next = p->next;
                // 旧点不变
            } else {
                // 新的点
                record = p->val;
                q = p;
            }
        }
        return head;
    }
};

int main(){
    return 0;
}