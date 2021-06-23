/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> sorted;
void build(TreeNode *root){
    if(!root)
        return;

    build(root->left);
    sorted.push_back(root->val);
    build(root->right);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    sorted.clear();
    build(A);
    vector<int> ans(2);
    bool first = 0;
    for(int i = 0; i < sorted.size()-1; i++){
        if(sorted[i+1] < sorted[i]){
            if(first)
                ans[0] = sorted[i+1];

            else{
                //adjacents maybe swapped as well
                first = 1;
                ans[0] = sorted[i+1];
                ans[1] = sorted[i];
            }
        }
    }

    return ans;
}

//or 

//Morris Traversal. TC O(n) + SC O(1) inorder traversal
vector<int> Solution::recoverTree(TreeNode* root) {

    TreeNode *prev = NULL, *first = NULL, *second = NULL;
    while(root){
        if(root->left){
            TreeNode *temp = root->left;
            while(temp->right && temp->right != root){
                temp = temp->right;
            }
            if(temp->right){
                temp->right = NULL;
                if(prev && prev->val > root->val){
                    if(first)
                        second = root;
                    else{
                        first = prev, second = root;
                    }
                }

                prev = root;
                root = root->right;
                    
            }
            else{
                temp->right = root;
                root = root->left;
            }
        }
        else{

            if(prev && prev->val > root->val){
                if(first)
                    second = root;
                else{
                    first = prev, second = root;
                }
            }

            prev = root;
            root = root->right;
        }
    }
    
    vector<int> ans(2);
    ans[0] = second->val, ans[1] = first->val;
    return ans;
}

    
