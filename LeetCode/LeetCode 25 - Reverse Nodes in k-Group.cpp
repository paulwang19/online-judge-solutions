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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newTail = head;
        ListNode *nextGroupHead = nullptr;
        head = reverseKNodes(head, k, nextGroupHead);
        while (nextGroupHead != nullptr) {
            ListNode *prevGroupTail = newTail;
            newTail = nextGroupHead;
            prevGroupTail->next = reverseKNodes(nextGroupHead, k, nextGroupHead);
        }

        return head;
    }

    ListNode* reverseKNodes(ListNode* head, int k, ListNode*& remainingListHead) {
        ListNode *walk = head;
        int cnt = 0;
        while (walk != nullptr && cnt < k) {
            cnt++;
            walk = walk->next;
        }

        remainingListHead = walk;
        if (cnt < k) {
            return head;
        }
        
        walk = head;
        cnt = 0;
        ListNode *newNext = nullptr;
        while (cnt < k) {
            ListNode *newPrev = walk->next;
            walk->next = newNext;
            newNext = walk;
            walk = newPrev;
            cnt++;
        }

        return newNext;
    }
};