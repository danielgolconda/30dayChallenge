class LRUCache {
public:
    list <pair<int,int>> lru; // List to hold key-val pairs
    unordered_map <int,list<pair<int,int>> :: iterator> mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void moveForward(int key,int val)
    {
        lru.erase(mp[key]);
        lru.push_front({key,val});
        mp[key] = lru.begin();
        return ;
    }
    int get(int key) {
        // Values not present 
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            int val = (*mp[key]).second;
            moveForward(key,val);
            return val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) // Present
        {
            moveForward(key,value);
        }
        else
        {
            lru.push_front({key,value});
            mp[key] = lru.begin();
            if(lru.size() > capacity)
            {
                mp.erase(lru.back().first);
                lru.pop_back();
            }
        }
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
