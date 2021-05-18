stack <pair<int, int> > s;

MinStack::MinStack() {
	while (!s.empty())
		s.pop();
}

void MinStack::push(int x) {

	if (s.empty())
		s.push({x, x});

	else
		s.push({x, min(x, s.top().second)});


}

void MinStack::pop() {
	if (!s.empty())
		s.pop();
}

int MinStack::top() {
	if (s.empty())
		return -1;
	return s.top().first;
}

int MinStack::getMin() {
	if (s.empty())
		return -1;
	return s.top().second;
}


//or


struct Node
{
	int data;
	int min;
	Node *next;
};

class MinStack {
private:
	Node *head;
public:



	/** initialize your data structure here. */
	MinStack() {
		head = NULL;
	}

	void push(int val) {
		Node *temp = new Node();
		temp->data = val;
		temp->next = head;
		temp->min = val;

		if (head)
			temp->min = min(temp->min, head->min);

		head = temp;
	}

	void pop() {
		if (head) {
			Node *temp = head;
			head = head->next;
			delete(temp);
		}

	}

	int top() {
		if (head)
			return head->data;

		return -1;

	}

	int getMin() {
		if (head)
			return head->min;

		return -1;

	}
};
