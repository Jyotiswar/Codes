#include<iostream>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode *ptr1 = head;
        ListNode *ptr2 = ptr1->next;

        while(ptr2 != NULL){

            if(ptr2->val == ptr1->val){
                ListNode *rmv = ptr2;
                ptr2 = ptr2->next;
                delete(rmv);
            }else{ 
                ptr1->next = ptr2;
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 -> next = NULL;
        return  head;

    }
};