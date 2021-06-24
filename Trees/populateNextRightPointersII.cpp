//Tree not necessarily full
class Solution {
public:
    Node* connect(Node* head) {
        Node *root = head;
        if(!root)
            return root;
        Node *next = NULL, *prev = NULL;
        
        while(root){
            next = NULL;
            while(root){
                if(root->left){
                    if(prev)
                        prev->next = root->left;
                    prev = root->left;
                    if(!next)
                        next = root->left;
                }
                if(root->right){
                    if(prev)
                        prev->next = root->right;
                    prev = root->right;
                    if(!next)
                        next = root->right;
                }
                root = root->next;
            }
            root = next;
            prev = NULL;

        }
        return head;
    }
};