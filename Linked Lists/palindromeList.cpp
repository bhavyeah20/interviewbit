/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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


int Solution::lPalin(ListNode* A) {
	if (!A || !A->next)
		return 1;

	ListNode *slow = A, *fast = A->next;
	ListNode *helper = new ListNode(0), *helperHead = helper;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	helper->next = slow->next;
	slow->next = NULL;

	helperHead = helper->next;


	helperHead = rev(helperHead);
	slow = A;
	while (helperHead) {
		if (slow->val != helperHead->val)
			return 0;

		slow = slow->next;
		helperHead = helperHead->next;
	}

	return 1;

}


// OR

// Reverse list from n/2 to n using helper