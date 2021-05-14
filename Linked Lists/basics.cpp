#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lld long long int

struct Node {
	int data;
	Node *next;
};

void print(Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}


void insert(Node **head, int pos, int val) {
	Node *temp1 = *head;
	Node *temp2 = new Node();
	temp2->data = val, temp2->next = NULL;

	if (pos == 1) {
		temp2->next = temp1;
		temp1 = temp2;
		*head = temp1;
		return ;
	}

	for (int j = 0; j < pos - 2; j++) {
		temp1 = temp1->next;
	}

	temp2->next = temp1->next;
	temp1->next = temp2;



	return;
}

void remove(Node **head, int pos) {

	Node *temp1 = *head, *temp2;

	if (pos == 1) {
		*head = temp1->next;
		free(temp1);
		return ;
	}

	for (int j = 0; j < pos - 2; j++) {
		temp1 = temp1->next;
	}

	temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);

	return ;

}


int main () {

	Node *head = NULL;
	insert(&head, 1, 40);
	insert(&head, 1, 20);
	insert(&head, 1, 10);
	insert(&head, 4, 10000);
	print(head);

	remove(&head, 4);


	print(head);


}
