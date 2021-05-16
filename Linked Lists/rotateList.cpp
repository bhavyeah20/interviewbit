/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
	ListNode *t = A;
	int N = 0;

	if (!t)
		return t;

	while (t) {
		t = t->next;
		N++;
	}

	B %= N;

	N = N - B - 1;
	t = A;

	if (!B)
		return A;

	while (N--) {
		t = t->next;
	}

	ListNode *helper = new ListNode(0);
	ListNode *helperHead = helper;

	helper->next = t->next;

	while (helper && helper->next) {
		helper = helper->next;
	}

	helper->next = A;

	t->next = NULL;

	return helperHead->next;




}
