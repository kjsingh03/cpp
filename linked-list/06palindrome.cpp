#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head, *fast = head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        stack<int> st;

        slow=slow->next;

        while(slow){
            st.push(slow->val);
            slow=slow->next;
        }

        slow=head;

        while(!st.empty() && slow){
            int top = st.top(); st.pop();
            if(slow->val!=top)
                return false;
            slow=slow->next;
        }

        return true;
    }
};