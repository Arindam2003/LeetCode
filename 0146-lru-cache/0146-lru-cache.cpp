class LRUCache {
    
public:
    unordered_map<int,int> keyToval;
    unordered_map<int,list<int>::iterator> keyToNode; // address ta store korchi karon.. akta value address theke ami linkedlist er address e O(1) e giye delete korte parbo...
    list<int> orderOfkey;
    int cap;

    void evict()
    {
        int delKey=orderOfkey.front();

        orderOfkey.pop_front();
        keyToval.erase(delKey);
        keyToNode.erase(delKey);
    }

    void updateTillNow(int key)
    {
        if(keyToNode.count(key))
        {
            auto it=keyToNode[key];
            orderOfkey.erase(it);
        }

        orderOfkey.push_back(key);
        keyToNode[key]= prev(orderOfkey.end()); // list er last element er address ta store korlm.
    }

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!keyToval.count(key)) //not found
        {
            return -1;
        }
        updateTillNow(key);
        return keyToval[key];
    }
    
    void put(int key, int value) {
        keyToval[key]=value;
        updateTillNow(key);

        if(keyToval.size() > cap)
        {
            evict();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */