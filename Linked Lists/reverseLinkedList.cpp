ListNode* Solution::reverseList(ListNode* A) {

	ListNode *curr = A, *prev = NULL, *next;

	while (curr != NULL) {
		next = curr -> next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

// or

void rev(ListNode *A, ListNode **head) {   // void rev(ListNode *A, ListNode* &head)
	ListNode *curr = A;

	if (curr->next == NULL) {
		*head = curr;					  // head = curr;
		return ;
	}

	rev(curr->next, head);


	curr->next->next = curr;
	curr->next = NULL;
}

ListNode* Solution::reverseList(ListNode* A) {

	rev(A, &A);							// rev(A,A);
	return A;

}


