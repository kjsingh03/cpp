struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow && fast){
                    if(slow==fast)
                        return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }

        return nullptr;
    }
};