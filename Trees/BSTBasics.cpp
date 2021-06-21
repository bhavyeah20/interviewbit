TreeNode *search(TreeNode *root, int key){
    if(!root)
        return root;

    while(root){
        if(root->val == key)
            return root;

        if(root->val < key)
            root = root->right;

        else
            root = root->left;
    }

    return root;
}

void insert(TreeNode *root, int key){
    TreeNode *tail = NULL;

    if(!root){
        TreeNode *t = new TreeNode(key);
        t->left = NULL, t->right = NULL;
        root = t;
        return ;
    }

    while(root){
        tail = root;

        if(root->val == key)
            return ;
    
        if(root->val < key)
            root = root->right;

        else
            root = root->left;
    }

    TreeNode *t = new TreeNode(key);
    t->left = NULL, t->right = NULL;

    if(tail->val < key)
        tail->right = t;

    else
        tail->left = t;
}

//or

TreeNode* insert(TreeNode *root, int key){

    if(!root){
        TreeNode *head = new TreeNode(key);
        root = head;
        return root;
    }

    if(root->val < key)
        root->right = insert(root->right, key);

    else if(root->val > key)
        root->left = insert(root->left, key);

    return root;
}

bool search(TreeNode *root, int key){
    if(!root)
        return false;

    if(root->val == key)
        return true;

    return search(root->left,key) || search(root->right, key);
}

void inorder(TreeNode *root){

    if(!root)
        return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

TreeNode *inorderSuccesor(TreeNode *root){
    root = root->right;
    while(!root && root->left)
        root = root->left;

    return root;
}
TreeNode* removed(TreeNode *root, int key){

    if(!root){
        return root;
    }

    if(root->val < key){
        root->right = removed(root->right,key);
        return root;
    }

    else if(root->val > key){
        root->left = removed(root->left, key);
        return root;

    }

    
    if(!root->left && !root->right){
        delete root;
        return NULL;
    }


    if(!root->left && root->right){
        TreeNode *t = root;
        root = root->right;
        delete t;

        return root;
    }

    if(root->left && !root->right){
        TreeNode *t = root->left;
        root = root->left;
        delete t;

        return root;
    }

    TreeNode *nextPtr = inorderSuccesor(root);
    root->val = nextPtr->val;
    root->right = removed(root->right,nextPtr->val);
    return root;

}
