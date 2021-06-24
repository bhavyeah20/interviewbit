#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

struct TrieNode {
	//TrieNode* child[alphabetSize] can also be implemented
	unordered_map<char,TrieNode *> child;
	bool endOfWord;

	TrieNode(){
		child.clear();
		endOfWord = false;
	}
};

TrieNode *insert(TrieNode *head, string s){
	if(!head)
		head = new TrieNode();

	TrieNode *root = head;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(root->child.find(s[i]) == root->child.end()){
			TrieNode *temp = new TrieNode();
			root->child[s[i]] = temp;
		}
		root = root->child[s[i]];
	}

	root->endOfWord = true;
	return head;
}

bool search(TrieNode *root, string s){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(!root)
			return false;

		if(root->child.find(s[i]) == root->child.end())
			return false;

		root = root->child[s[i]];
	}

	return root->endOfWord;
}

TrieNode *Delete(TrieNode *root, string s, int depth = 0){
	if(!root)
		return root;

	if(depth == s.length()){
		root->endOfWord = false;

		if(root->child.empty()){
			delete root;
			root = NULL;
		}

		return root;

	}

	root->child[s[depth]] = Delete(root->child[s[depth]],s,depth+1);
	if(root->child[s[depth]] == NULL && root->child.size() == 1 && root->endOfWord == false){
		delete root;
		root = NULL;
	}

	return root;
}


int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	TrieNode *root = new TrieNode();
	root = insert(root,"abc");
	root = insert(root,"abcd");
	root = insert(root,"abgl");
	root = insert(root,"cdf");
	root = insert(root,"lmn");

	cout<<search(root,"abgl")<<endl;
	root = Delete(root,"abc");
	cout<<search(root,"abgl")<<endl;

}
