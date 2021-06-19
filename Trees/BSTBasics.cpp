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

TreeNode *insert(TreeNode *root, int key){
    TreeNode *t = NULL;

    if(!root){
        TreeNode *t = new TreeNode(key);
        t->left = NULL, t->right = NULL;
        return t;
    }
    
    if(root->val == key)
        return root;
    
    if(root->val < key)
        root->right = insert(root->right,key);

    else
        root->left = insert(root->left,key);

    return root;
}



