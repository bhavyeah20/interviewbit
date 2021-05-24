/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

	RandomListNode *prev = new RandomListNode(0);
	RandomListNode *headNew = prev, *head;

	unordered_map<RandomListNode*, RandomListNode*> mp; //old->new

	head = A;

	while (head) {
		RandomListNode *temp = new RandomListNode(head->label);
		prev->next = temp;
		mp[head] = temp;
		prev = temp;
		head = head->next;
	}

	head = A;
	prev = headNew->next;

	while (head) {
		prev->random = mp[head->random];
		head = head->next;
		prev = prev->next;
	}

	return headNew->next;

}

//or without hashmap's o(n) space

// 1->1'->2->2'->3->3'
// curr->next->random = curr->random->next

public RandomListNode copyRandomList(RandomListNode head) {
	RandomListNode iter = head, next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != null) {
		next = iter.next;

		RandomListNode copy = new RandomListNode(iter.label);
		iter.next = copy;
		copy.next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != null) {
		if (iter.random != null) {
			iter.next.random = iter.random.next;
		}
		iter = iter.next.next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode pseudoHead = new RandomListNode(0);
	RandomListNode copy, copyIter = pseudoHead;

	while (iter != null) {
		next = iter.next.next;

		// extract the copy
		copy = iter.next;
		copyIter.next = copy;
		copyIter = copy;

		// restore the original list
		iter.next = next;

		iter = next;
	}

	return pseudoHead.next;
}