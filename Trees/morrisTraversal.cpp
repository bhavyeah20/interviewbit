//Morris Traversal. TC O(n) + SC O(1) inorder traversal

void morrisTraversal(TreeNode *root){

    while(root){
        if(root->left){
            TreeNode *temp = root->left;
            while(temp->right && temp->right != root){
                temp = temp->right;
            }
            if(temp->right){
                temp->right = NULL;
                cout<<root->val<<" ";
                root = root->right;
            }
            else{
                temp->right = root;
                root = root->left;
            }
        }
        else{
            cout<<root->val<<" ";
            root = root->right;
        }
    }
}

// Morris preorder. Print before going to left instead of right.

void morrisTraversal(TreeNode *root){

    while(root){
        if(root->left){
            TreeNode *temp = root->left;
            while(temp->right && temp->right != root){
                temp = temp->right;
            }
            if(temp->right){
                temp->right = NULL;
                root = root->right;
            }
            else{
                cout<<root->val<<" ";
                temp->right = root;
                root = root->left;
            }
        }

        else{
        cout<<root->val<<" ";
        root = root->right;
        }
    }
}