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
    ListNode* removeElements(ListNode* head, int val) {
        bool first = true;
        ListNode *p, *q=NULL;
        for(p=head;p!=NULL;p=p->next){
            if(p->val==val){
                if(first){
                    head = p->next;
                    continue;
                }
                q->next = p->next;
                continue;
            }
            first = false;
            q = p;
        }
        return head;
    }
};

int main(){
    return 0;
}