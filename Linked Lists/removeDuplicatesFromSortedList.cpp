/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

	ListNode *t1 = A, *t1Head = t1;

	while (t1 && t1->next) {
		if (t1->val != (t1->next)->val) {
			t1 = t1->next;
			continue;
		}

		ListNode *t2 = t1->next;

		while (t2 && t1->val == t2->val) {
			ListNode *t3 = t2;
			t2 = t2->next;
			free(t3);
		}

		t1->next = t2;

		t1 = t1->next;
	}


	return t1Head;

}
