class LRUCache {
private: 
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
  
public:
    LRUCache(int capacity) {
        this->capacity = capacity;        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        
        //Extracting and storing the value
        auto it = mp[key];
        int value = it->second;
        
        //Removing and Pushing it to front in dll
        dll.erase(it);
        dll.push_front({key, value});

        //mapping the key to {key, value}
        mp[key] = dll.begin();

        //returning the value
        return value;
    }
    
    void put(int key, int value) {
        //if already exists
        if(mp.find(key)!=mp.end()){
            //remove from dll
            dll.erase(mp[key]);
            //remove the mapping
            mp.erase(key);
        }
        //if capacity equals size
        if(dll.size()==capacity){
            //remove the last pair in dll
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        //push to front
        dll.push_front({key, value});
        //map the key, value
        mp[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */