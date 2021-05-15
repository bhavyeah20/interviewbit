/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {

	ListNode *t = A, *prev = NULL, *curr = t, *next = NULL;

	if (A == NULL || A->next == NULL)
		return A;
	int cnt = 2;
	while (curr && cnt--) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}


	if (next) {
		A->next = Solution::swapPairs(next);
	}
	return prev;

}


//or


ListNode* Solution::swapPairs(ListNode* A) {
	ListNode *ans = new ListNode(0), *prevHead = ans, *currHead = NULL;

	ListNode *curr = A, *prev = NULL, *next;
	int cnt = 2;

	if (curr == NULL || curr->next == NULL)
		return curr;


	while (curr && curr->next) {
		currHead = curr;
		while (curr && cnt--) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		cnt = 2;
		currHead->next = next;
		prevHead->next = prev;
		prevHead = currHead;
	}


	return ans->next;
}