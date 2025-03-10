/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  int size(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
         if (!head || !head->next) {
            return NULL;
        }

        int n = size(head);
        int middle = n / 2;

        ListNode* temp = head;
        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
   return head;
    }
};