# LeetCode 23 - Merge k Sorted Lists

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

struct ListNodeGreaterComparator {
    bool operator()(ListNode* lNode, ListNode* rNode) {
        if (lNode == nullptr) return false; // null node has highest priority
        else if (rNode == nullptr) return true;
        return lNode->val > rNode->val;
    }
};

class Solution {
private:
    priority_queue<ListNode*, vector<ListNode*>, ListNodeGreaterComparator> *pq;

    void buildPQ(const vector<ListNode*>& lists) {
        pq = new priority_queue<ListNode*, vector<ListNode*>, ListNodeGreaterComparator>(lists.begin(), lists.end());
    }

    ListNode* getNextNode() {
        ListNode *node = nullptr;
        while (!pq->empty() && node == nullptr) {
            node = pq->top();
            pq->pop();
        }

        if (node != nullptr) {
            pq->push(node->next);
        }

        return node;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        buildPQ(lists);
        ListNode *head = getNextNode();
        ListNode *walk = head;
        while (walk != nullptr) {
            walk->next = getNextNode();
            walk = walk->next;
        }

        return head;
    }
};
```
