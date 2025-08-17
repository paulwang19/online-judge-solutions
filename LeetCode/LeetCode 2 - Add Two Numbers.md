# LeetCode 2 - Add Two Numbers

## 程式碼

```cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* walk1 = l1;
        ListNode* walk2 = l2;
        ListNode* headSum = nullptr;
        ListNode* walkSum = nullptr;
        int lastCarry = 0;

        while (walk1 != nullptr && walk2 != nullptr) {
            if (headSum == nullptr) {
                headSum = new ListNode;
                walkSum = headSum;
            } // if
            else {
                walkSum->next = new ListNode;
                walkSum = walkSum->next;
            } // else

            walkSum->val = (lastCarry + walk1->val + walk2->val) % 10;
            lastCarry = (lastCarry + walk1->val + walk2->val) / 10;
            walk1 = walk1->next;
            walk2 = walk2->next;
        }

        while (walk1 != nullptr) {
            walkSum->next = new ListNode;
            walkSum = walkSum->next;
            walkSum->val = (lastCarry + walk1->val) % 10;
            lastCarry = (lastCarry + walk1->val) / 10;
            walk1 = walk1->next;
        }

        while (walk2 != nullptr) {
            walkSum->next = new ListNode;
            walkSum = walkSum->next;
            walkSum->val = (lastCarry + walk2->val) % 10;
            lastCarry = (lastCarry + walk2->val) / 10;
            walk2 = walk2->next;
        }

        if (lastCarry > 0) {
            walkSum->next = new ListNode;
            walkSum = walkSum->next;
            walkSum->val = lastCarry % 10;
        }

        return headSum;
    }
};
```
