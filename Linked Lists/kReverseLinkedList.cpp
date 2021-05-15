/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
	ListNode *curr = A, *prevHead = new ListNode(0), *currHead = NULL;
	ListNode *ans = prevHead;
	ListNode *prev = NULL, *next;
	int b = B;

	if (B == 1)
		return A;

	while (curr) {
		currHead = curr;
		while (b-- && curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		prevHead->next = prev;
		prevHead = currHead;
		prev = NULL;
		b = B;
	}

	return ans->next;
}

//or

ListNode* Solution::reverseList(ListNode* A, int B) {
	ListNode *curr = A, *prev = NULL, *next = NULL;
	int cnt = 0;
	while (cnt < B && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}
	if (next) {
		A->next = reverseList(next, B);
	}
	return prev;
}
