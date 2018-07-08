/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <queue>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> queue;
        ListNode* q, * p;
        int queue_lenght = 0;
        for(p=head;p!=NULL;p=p->next){
            if(queue_lenght>=n+1){
                queue.pop();
                queue_lenght -= 1;
            }
            queue.push(p);
            queue_lenght += 1;
        }
        // 这里队首为倒数第N+1个数
        if(queue_lenght==n){
            // 删除的为头
            q = head;
            head = head->next;
            free(q);
            return head;
        }
        if(queue_lenght>= n+1){
            // 删除的为链表非头
            q = queue.front(); // N + 1 可能为头
            queue.pop();
            p = queue.front(); // N 
            q->next = p->next;
            free(p);
            return head;
        }
        return head;
    }
};

int main(){
    // 一次过了，不写 case 了
    return 0;
}