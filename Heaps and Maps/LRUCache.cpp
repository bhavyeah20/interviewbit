struct Node{
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
private:
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int,Node*> mp; //key->node
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();

        head = new Node(-1,-1);
        tail = new Node(-2,-1);

        head->next = tail;
        tail->prev = head;
    }
        
    void addToHead(int key, int val){
        Node *temp;
        if(mp.find(key) != mp.end()){
            Node *it = mp[key];
            it->prev->next = it->next;
            it->next->prev = it->prev;
            mp.erase(it->key);
            delete(it);
        }
        
        temp = new Node(key,val);
        temp->prev = head;
        temp->next = head->next;

        head->next->prev = temp;
        head->next = temp;
        mp[key] = temp;
    }

    void removeTail(){
        Node *temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;

        mp.erase(temp->key);
        
        delete(temp);
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *it = mp[key];
            addToHead(key,it->val);
            return mp[key]->val;
        }

        return -1;
    }
    
    void put(int key, int val) {
        if(mp.find(key) != mp.end()){
            Node *it = mp[key];
            it->val = val;
            addToHead(key, val);
        }

        
        else{
            Node *it = new Node(key,val);
            addToHead(key,val);
        
            if(mp.size() > capacity){
                removeTail();
            }
        }
    }
};


//or

class LRUCache {
private:
    int capacity;
    int currCapacity;
    int when;
    set<pair<int,int>> s; //insertedAt, key
    unordered_map<int,pair<int,int>> mp; // key val insertedAt
    
public:
    
    LRUCache(int capacity) {
        mp.clear();
        s.clear();
        this->capacity = capacity;
        this->currCapacity = 0;
        this->when = 0;
    }
    
    int get(int key) {
        when++;
        if(mp.find(key) != mp.end()){
            int ia = mp[key].second;
            s.erase({ia,key});
            mp[key].second = when;
            s.insert({when,key});
            return mp[key].first;
        }
        
        return -1;
    }
    
    void put(int key, int val) {
        when++;
        
        if(mp.find(key) != mp.end()){
            auto ia = mp[key].second;
            s.erase({ia,key});            
        }
        
        else{
            currCapacity++;
            if(currCapacity > capacity){
                auto node = *s.begin();
                s.erase(node);
                mp.erase(node.second);
                currCapacity--;
            }
        }

        mp[key].first = val;
        mp[key].second = when;
        s.insert({when,key});
        
    }
};
