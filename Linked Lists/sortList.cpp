ListNode *sortt(ListNode *start, ListNode *end) {
	if (start == end) {
		start->next = NULL;
		return start;
	}

	ListNode *mid = start, *fast = mid->next;

	while (fast != end->next && fast->next != end->next) {
		mid = mid->next;
		fast = fast->next->next;
	}
	ListNode *sortedMid = sortt(mid->next, end);
	ListNode *sortedStart = sortt(start, mid);


	ListNode *ans = NULL;
	ListNode *ansHead = ans;
	while (sortedStart && sortedMid) {
		ListNode *sortedStartNext = sortedStart->next;
		ListNode *sortedMidNext = sortedMid->next;

		if (sortedStart->val < sortedMid->val) {
			if (!ans)
				ans = sortedStart, ansHead = ans;
			else {
				ans->next = sortedStart;
				ans = ans->next;
			}
			sortedStart = sortedStartNext;

		}

		else {
			if (!ans)
				ans = sortedMid, ansHead = ans;
			else {
				ans->next = sortedMid;
				ans = ans->next;
			}
			sortedMid = sortedMidNext;

		}

	}

	while (sortedStart) {
		ans->next = sortedStart;
		ans = ans->next;
		sortedStart = sortedStart->next;
	}

	while (sortedMid) {
		ans->next = sortedMid;
		ans = ans->next;
		sortedMid = sortedMid->next;
	}

	ans->next = NULL;

	return ansHead;
}

ListNode* Solution::sortList(ListNode* A) {

	ListNode *start = A, *end = A;

	while (end->next) {
		end = end->next;
	}

	return sortt(start, end);
}

//or T/D

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode* mid = getMid(head);
		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		return merge(left, right);
	}

	ListNode* merge(ListNode* list1, ListNode* list2) {
		ListNode dummyHead(0);
		ListNode* ptr = &dummyHead;
		while (list1 && list2) {
			if (list1->val < list2->val) {
				ptr->next = list1;
				list1 = list1->next;
			} else {
				ptr->next = list2;
				list2 = list2->next;
			}
			ptr = ptr->next;
		}
		if (list1) ptr->next = list1;
		else ptr->next = list2;

		return dummyHead.next;
	}

	ListNode* getMid(ListNode* head) {
		ListNode* midPrev = nullptr;
		while (head && head->next) {
			midPrev = (midPrev == nullptr) ? head : midPrev->next;
			head = head->next->next;
		}
		ListNode* mid = midPrev->next;
		midPrev->next = nullptr;
		return mid;
	}
};


// or B/U


class Solution {
public:
	ListNode* tail = new ListNode();
	ListNode* nextSubList = new ListNode();

	ListNode* sortList(ListNode* head) {
		if (!head || !head -> next)
			return head;
		int n = getCount(head);
		ListNode* start = head;
		ListNode dummyHead(0);
		for (int size = 1; size < n; size = size * 2) {
			tail = &dummyHead;
			while (start) {
				if (!start->next) {
					tail->next = start;
					break;
				}
				ListNode* mid = split(start, size);
				merge(start, mid);
				start = nextSubList;
			}
			start = dummyHead.next;
		}
		return dummyHead.next;
	}

	ListNode* split(ListNode* start, int size) {
		ListNode* midPrev = start;
		ListNode* end = start->next;
		//use fast and slow approach to find middle and end of second linked list
		for (int index = 1; index < size && (midPrev->next || end->next); index++) {
			if (end->next) {
				end = (end->next->next) ? end->next->next : end->next;
			}
			if (midPrev->next) {
				midPrev = midPrev->next;
			}
		}
		ListNode* mid = midPrev->next;
		nextSubList = end->next;
		midPrev->next = nullptr;
		end->next = nullptr;
		// return the start of second linked list
		return mid;
	}

	void merge(ListNode* list1, ListNode* list2) {
		ListNode dummyHead(0);
		ListNode* newTail = &dummyHead;
		while (list1 && list2) {
			if (list1->val < list2->val) {
				newTail->next = list1;
				list1 = list1->next;
				newTail = newTail->next;
			} else {
				newTail->next = list2;
				list2 = list2->next;
				newTail = newTail->next;
			}
		}
		newTail->next = (list1) ? list1 : list2;
		// traverse till the end of merged list to get the newTail
		while (newTail->next) {
			newTail = newTail->next;
		}
		// link the old tail with the head of merged list
		tail->next = dummyHead.next;
		// update the old tail with the new tail of merged list
		tail = newTail;
	}

	int getCount(ListNode* head) {
		int cnt = 0;
		ListNode* ptr = head;
		while (ptr) {
			ptr = ptr->next;
			cnt++;
		}
		return cnt;
	}
};

