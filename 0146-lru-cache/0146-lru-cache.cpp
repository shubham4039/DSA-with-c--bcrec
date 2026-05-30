class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    void addNode(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node){
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;      
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        }
        else{
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);

            if (mp.size() > capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */