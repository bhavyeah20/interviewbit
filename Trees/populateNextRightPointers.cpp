//full binary tree

class Solution {
public:
    Node* connect(Node* head) {
        Node *root = head;
        if(!root){
            return root;
        }

        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                Node *root = q.front();
                q.pop();
                if(i != sz - 1){
                    root->next = q.front();
                }
                if(root->left)
                    q.push(root->left);

                if(root->right)
                    q.push(root->right);
            }
        }
        return head;
    }
};

//or

class Solution {
public:
    Node* connect(Node* head) {
        Node *root = head;
        if(!root)
            return root;
        Node *next = root->left;
        
        while(root && root->left){
            next = root->left;
            while(root){
                root->left->next = root->right;
                if(root->next)
                    root->right->next = root->next->left;
                
                root = root->next;
            }
            root = next;
        }
        return head;
    }
};