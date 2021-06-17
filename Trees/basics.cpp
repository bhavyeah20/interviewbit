#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

struct Node{
	int data;
	Node *left;
	Node *right;

	Node(int x){
		data =x;
		left = right = NULL;
	}
};

void preorder(Node *root){
	if(root == NULL)
		return ;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root){
	if(root == NULL)
		return ;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(Node *root){
	if(root == NULL)
		return ;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int height(Node *root){
	if(root == NULL)
		return -1;

	int left = height(root->left);
	int right = height(root->right);
	return 1 + max(left,right);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	cout<<"Enter root "<<endl;
	int x;
	cin >> x;
	queue<Node *> q;
	Node *root = new Node(x);
	q.push(root);

	while(!q.empty()){
		Node *curr = q.front();
		q.pop();
		int x;
		cout<<"Enter left child for "<<curr->data<<endl;
		cin >> x;
		if(x != -1){
			Node *t = new Node(x);
			curr->left = t;
			q.push(t);
		}

		cout<<"Enter right child for "<<curr->data<<endl;
		cin >> x;
		if(x != -1){
			Node *t = new Node(x);
			curr->right = t;
			q.push(t);
		}
	}

	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<height(root);
}
