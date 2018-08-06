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
        ListNode *p=head->next, *q=head, *o=head;
        int record = head->val;
        bool repeat = false;

        for(;p!=NULL;p=p->next){
            if(record==p->val){
                // 出现了重复的点
                o = p;
                repeat = true;
            } else {
                // 出现了新的点
                if(repeat){
                    // 先把旧的点删除
                    if(q==head){
                        if(q->val!=record){     
                            head->next = p;
                            q = head;
                        } else { 
                            head = p;
                            q = head;
                        }
                    } else {
                        q->next = p;
                    }
                    repeat = false;
                } else {
                    q = o;
                }
                record = p->val;
                o = p;
            }
        }
        if(repeat){
            if(q==head){
                if(q->val!=record){ // 对于 1，1，2，3，3这种结果为1的长度的要单独处理
                    head->next = NULL;
                } else {
                    return NULL;
                }
            }
            else {
                q->next = NULL;
            }
        }
        return head;
    }
};


int main(){
    return 0;
}