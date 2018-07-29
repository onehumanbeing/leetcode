#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool mov = false; // 进位
        bool bigger = true;
        ListNode* res = l1; // 假设 l1 长度大于等于 l2
        ListNode *p, *q, *tailp, *tailq;
        q = l1, p = l2;
        tailp = p;
        tailq = q;
        int value;
        while(q || p){
            if(q==NULL && bigger){
                // p != NULL, l2 更长
                res = l2;
                bigger = false;
                continue;
            }
            if(q==NULL || p==NULL){
                // 其中有一个链到头了
                if(bigger){
                    // l2 到头了
                    if(mov){
                        value = q->val + 1;
                        if(value>=10){
                            value -= 10;
                            q->val = value;
                        }
                        else{
                            q->val = value;
                            mov = false;
                        }
                    }
                    tailq = q;
                    q = q->next;
                    continue;

                } else {
                    // l1 到头了
                    if(mov){
                        value = p->val + 1;
                        if(value>=10){
                            value -= 10;
                            p->val = value;
                        }
                        else{
                            p->val = value;
                            mov = false;
                        }
                    }
                    tailp = p;
                    p = p->next;
                    continue;
                }
            }
            // 这里两个链到没有到头
            if(mov){
                value = p->val + q->val + 1;
                mov = false;
            } else {
                value = p->val + q->val;
            }
            if(value>=10){
                value -= 10;
                mov = true;
            }
            p->val = value;
            q->val = value;
            tailp = p;
            tailq = q;
            p = p->next;
            q = q->next;
            continue;
        }
        // 如果最后一位保持进位的话
        if(mov){
            ListNode *temp = new ListNode(1);
            if(bigger){
                tailq->next = temp;
            } else {
                tailp->next = temp;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}