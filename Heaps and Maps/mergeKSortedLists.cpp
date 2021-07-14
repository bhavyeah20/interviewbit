class Solution {
public:

    ListNode *merge2(ListNode *it1, ListNode *it2){
        ListNode *ans = new ListNode(0), *head = NULL;
        int a,b;
        while(it1 || it2){
            if(!it1)
                a = 10001;

            else
                a = it1->val;

            if(!it2)
                b = 10001;
            
            else 
                b = it2->val;

            if(a < b){
                ans->next = it1;
                it1 = it1->next;
            }

            else{
                ans->next = it2;
                it2 = it2->next;
            }

            if(!head)
                head = ans->next;
            ans = ans->next;

        }

        return head;
    }

    ListNode *merge(vector<ListNode *> &lists, int start, int end){

        if(start > end)
            return NULL;

        int sz = end - start + 1;

        if(sz == 1)
            return lists[start];

        if(sz == 2)
            return merge2(lists[start], lists[end]);

        int mid = start + (end-start)/2;
        ListNode *it1 = merge(lists, start, mid);
        ListNode *it2 = merge(lists,mid+1,end);

        return merge2(it1,it2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int sz = lists.size();

        return merge(lists,0,sz-1);        
    }
};


//or

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0), *it = head;
        priority_queue<pair<int,ListNode *>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode *>>> pq;

        for(auto it: lists){
            if(it)
                pq.push({it->val, it});
        }  

        while(!pq.empty()){
           auto node = pq.top().second;
           pq.pop();
           it->next = node;
           it = it->next;

           if(node->next){
            pq.push({node->next->val,node->next});

           }
        } 

        return head->next;
    }
};