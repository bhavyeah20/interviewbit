class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL;

        while(root || !s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }

            else{
                root = s.top();
                s.pop();

                if(pre && pre->val >= root->val)
                    return false;

                pre = root;
                root = root->right;
            }
        }

        return true;
    }
};



//or

class Solution {
public:
    
    bool check(TreeNode *root, int min, int max){
        if(!root) return 1;
        
        if(root->val < max && root->val > min){
            return check(root->left,min,root->val) && check(root->right,root->val,max);
        }
        
        return 0;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};