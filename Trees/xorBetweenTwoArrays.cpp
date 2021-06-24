struct TrieNode{
    TrieNode* child[2];

    TrieNode(){
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

TrieNode* insert(TrieNode* head, int x){
    if(!head)
        head = new TrieNode();
    TrieNode *root = head;
    for(int i = 31; i >= 0; i--){
        int temp = x & (1 << i);
        int key = 0;
        if(temp)
            key = 1;

        if(root->child[key] == NULL){
            TrieNode *newChild = new TrieNode();
            root->child[key] = newChild;
        }
        root = root->child[key];   
    }

    return head;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    TrieNode *root = NULL;
    for(int num : B){
        root = insert(root,num);
    }
    int ans = 0, curr = 0;
    for(int num: A){
        curr = 0;
        TrieNode *it = root;
        for(int i = 31; i >= 0; i--){
            int temp = num & (1 << i);
            int key = 0;
            if(temp)
                key = 1;

            if(it->child[key^1]){
                curr |= key^1;
                it = it->child[key^1];
            }

            else{
                curr |= key;
                it = it->child[key];
            }
            
            if(i)
                curr <<= 1;
        }

        ans = max(ans,curr^num);
    }

    return ans;
}
