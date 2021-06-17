void preorder(Node *root){
	stack<Node *> s;
	
	while(root || !s.empty()){
		if(root){
			s.push(root);
			cout<<root->data<<" ";
			root = root->left;
		}

		else{
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}

void inorder(Node *root){
	stack<Node *> s;
	
	while(root || !s.empty()){
		if(root){
			s.push(root);
			root = root->left;
		}

		else{
			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	}
}

void postorder(Node *root){
	stack<Node *> s1;
	stack<Node *> s2;

	if(root)
		s1.push(root);

	while(!s1.empty()){
		Node *root = s1.top();
		s1.pop();

		s2.push(root);
		if(root->left)
			s1.push(root->left);
		if(root->right)
			s1.push(root->right);
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}

}

void postorder(Node *root){
	stack<Node *> s;
	
	while(root || !s.empty()){
		if(root){
			s.push(root);
			cout<<root->data<<" "; //reverse this
			root = root->right;
		}

		else{
			root = s.top();
			s.pop();
			root = root->left;
		}
	}
}
