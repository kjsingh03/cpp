struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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