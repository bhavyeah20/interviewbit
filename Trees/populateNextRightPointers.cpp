/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* head) {
        queue<Node *> q;
        Node *root = head;
        if(!root)
            return root;
        
        q.push(root);
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                Node *root = q.front();
                q.pop();
                if(root->left) 
                    q.push(root->left);
                if(root->right)
                 q.push(root->right);
            }
            queue<Node *> t;
            t = q;
            Node *prev = NULL;
            for(int i = 0; i < t.size(); i++){
                Node *root = t.front();
                if(prev)
                    prev->next = root;
                prev = root;
                t.pop();
            }
            
        }
        
        return head;
    }
};

//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root;
        if(!root) return root;
        queue<Node *> q, t;
        q.push(root);
        
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                Node *root = q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);

            }
            t = q;
            
            for(int i = 0; i < t.size(); i++){
                Node *root = t.front();
                t.pop();
                root->next = t.empty() ? NULL : t.front();
            }
        }
        
        return head;
        
    }
};