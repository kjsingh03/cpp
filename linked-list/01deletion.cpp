struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr = node;

        while(ptr->next->next){
            ptr->val=ptr->next->val;
            ptr=ptr->next;
        }

        ptr->val=ptr->next->val;
        ptr->next = nullptr;
    }
};