class Solution {
public:
    TreeNode *fun(ListNode *start, ListNode *end){
        ListNode *fast = start, *slow = start;
        
        if(start == end){ 
            return NULL;
        }
        
        
        while(fast != end && fast->next != end){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode *temp = new TreeNode(slow->val);
        temp->right = fun(slow->next,end);
        temp->left = fun(start, slow);
        return temp;
        
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return fun(head,NULL);
    }
};