#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lld long long int

struct ListNode {
	int val;
	ListNode *next;
};

void print(ListNode *head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}


void insert(ListNode **head, int pos, int val) {
	ListNode *temp1 = *head;
	ListNode *temp2 = new ListNode();
	temp2->val = val, temp2->next = NULL;

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

void remove(ListNode **head, int pos) {

	ListNode *temp1 = *head, *temp2;

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


ListNode *rev(ListNode *t) {
	ListNode *curr = t, *prev = NULL, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

ListNode* solve(ListNode* A) {
	ListNode *odd = new ListNode(), *even = new ListNode(), *curr = A, *next = NULL;
	odd->val = 0, odd->next = NULL;
	even->val = 0, even->next = NULL;

	ListNode *oHead = odd, *eHead = even;
	int cnt = 1;
	while (curr) {
		next = curr->next;

		if (cnt) {
			odd->next = curr;
			odd = odd->next;
		}
		else {
			even->next = curr;
			even = even->next;
		}

		curr = next;
		cnt = (cnt + 1) % 2;
	}
	eHead = eHead->next;
	oHead = oHead->next;
	odd->next = NULL;
	even->next = NULL;

	eHead = rev(eHead);



	ListNode *ans = new ListNode();
	ans->val = 0, ans->next = NULL;
	ListNode *ansHead = ans;
	even = eHead, odd = oHead;
	cnt = 1;
	ListNode *oNext = NULL, *eNext = NULL;
	while (even || odd) {
		if (cnt) {
			oNext = odd->next;
			ans->next = odd;
			odd = oNext;
		}
		else {
			eNext = even->next;
			ans->next = even;
			even = eNext;
		}

		ans = ans->next;
		cnt = (cnt + 1) % 2;

	}

	return ans->next;
}

int main () {

	ListNode *head = NULL;
	insert(&head, 1, 4);
	insert(&head, 1, 3);
	insert(&head, 1, 2);
	insert(&head, 1, 1);

	print(head);

	head = solve(head);
	print(head);

}
