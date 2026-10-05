class LFUCache {
    unordered_map<int,int> keyToVal;
    unordered_map<int,int> keyToFreq;
    unordered_map<int,list<int>::iterator> keyToNode;
    map<int,list<int>>freqToKey;
    int cap;

    void transferFreq(int key)
    {
        // Getting rid of the old node.
        int oldFreq = keyToFreq[key];
        auto nodeToDel = keyToNode[key];
        freqToKey[oldFreq].erase(nodeToDel);
        if(freqToKey[oldFreq].empty())
            freqToKey.erase(oldFreq);

        //keyToVal theke key delete kore lav nei karon ota amr 1 tai set hye ahe.. just amk position change korlei hoi..

        keyToFreq[key] = oldFreq + 1;
        freqToKey[oldFreq + 1].push_back(key);
        keyToNode[key] = --freqToKey[oldFreq + 1].end();
    }

    void deleteListorRecent() {
        int minFreq = freqToKey.begin()->first;
        int culpritKey = freqToKey[minFreq].front();

        keyToVal.erase(culpritKey);
        keyToFreq.erase(culpritKey);
        keyToNode.erase(culpritKey);
        freqToKey[minFreq].pop_front();
        if(freqToKey[minFreq].empty())
            freqToKey.erase(minFreq);
    }

public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!keyToVal.count(key))
        {
            return -1;
        }

        /*
            1. Remove it from old freq list.
            2. Add to the back of the new freq list.
            3. Update the keyToFreq & keyToNode etc.
        */
        transferFreq(key);

        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if(keyToVal.count(key))
        {
            transferFreq(key); // mase 3 te kaj.. 1 delete from prev, 2. add to last. 3. update new address.
            keyToVal[key] = value;
            return;
        }

        if(keyToVal.size() == cap)
        {
            deleteListorRecent();
        }

        keyToVal[key]=value;
        keyToFreq[key]++;
        freqToKey[1].push_back(key);
        keyToNode[key] = --freqToKey[1].end();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */