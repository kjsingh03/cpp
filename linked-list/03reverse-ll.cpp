struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head; 

        ListNode* slow = head, *mid = head, *fast = head->next;

        slow->next=nullptr;

        while(fast){
            mid=fast;
            fast=fast->next;
            mid->next=slow;
            slow=mid;
        }

        return slow;
    }
};