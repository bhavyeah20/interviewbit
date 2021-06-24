struct TrieNode {
    map<char,TrieNode *> child;
    bool endOfWord;
    int cnt;
    TrieNode(){
        child.clear();
        cnt = 0;
        endOfWord = false;
    }
};

TrieNode *insert(TrieNode *head, string s){
    if(!head)
        head = new TrieNode();

    TrieNode *root = head;
    int n = s.length();
    for(int i = 0; i < n; i++){
        //Increase whenever current node is used in word
        root->cnt += 1;
        if(root->child.find(s[i]) == root->child.end()){
            TrieNode *temp = new TrieNode();
            root->child[s[i]] = temp;
        }
        root = root->child[s[i]];
    }

    root->endOfWord = true;
    return head;
}

vector<string> Solution::prefix(vector<string> &words) {
    vector<string> ans;
    TrieNode *root = NULL;
    for(string word: words){
        root = insert(root,word);
    }


    for(string word: words){
        TrieNode *temp = root;
        string res = "";
        
        for(char x: word){
            if(temp->cnt == 1){
                ans.push_back(res);
                break;
            }
        
            res.push_back(x);
            temp = temp->child[x];
        }
        
        if(temp->child.empty())
            ans.push_back(res);
    }
 
    return ans;
}
