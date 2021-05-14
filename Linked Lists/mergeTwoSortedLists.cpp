/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

	ListNode *t1 = A, *t2 = B;
	ListNode *ans = NULL, *ansHead = ans;

	while (t1 && t2) {
		ListNode *nxt1 = t1->next, *nxt2 = t2->next;

		if (t1->val < t2->val) {
			if (ans == NULL) {
				ans = t1;
				ansHead = ans;
			} else {
				ans->next = t1;
				ans = ans->next;
			}
			t1 = nxt1;
		} else {
			if (ans == NULL) {
				ans = t2;
				ansHead = ans;
			} else {
				ans->next = t2;
				ans = ans->next;
			}

			t2 = nxt2;
		}


	}

	while (t1 != NULL) {
		ans->next = t1;
		t1 = t1->next;
		ans = ans->next;

	}


	while (t2 != NULL) {
		ans->next = t2;
		t2 = t2->next;
		ans = ans->next;

	}

	return ansHead;


}
