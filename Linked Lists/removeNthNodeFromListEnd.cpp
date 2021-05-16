/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

	ListNode *helper = new ListNode(0), *t = A;

	helper->next = A;

	int size = 0;
	while (t) {
		t = t->next;
		size++;
	}

	int pos = size - B;
	t = helper;
	while (pos > 0) {
		t = t->next;
		pos--;
	}

	t->next = t->next->next;
	return helper->next;


}


// or

// start slow from 0 and fast from n
// when fast reaches k slow is at k - n