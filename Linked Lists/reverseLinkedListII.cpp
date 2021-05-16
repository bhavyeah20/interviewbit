/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

	ListNode *helper = new ListNode(0);
	helper->next = A;

	ListNode *t1 = helper;

	int b = B - 1, c = C;

	while (b--) {
		t1 = t1->next;
	}

	ListNode *curr = t1->next, *next = NULL, *prev = NULL;
	int cnt = C - B + 1;
	while (cnt-- && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	t1->next->next = curr;
	t1->next = prev;

	return helper->next;



}
