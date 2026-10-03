class MyHashMap {
    vector<list<pair<int,int>>>arr;
    const double MAX_LOAD_FACTOR = 0.15;
    const int INITIAL_CAPACITY=1;
    int currSize,currBuckets;

    int hash(int key)
    {
        return key % currBuckets;
    }

    list<pair<int,int>>::iterator get(list<pair<int,int>> &ll,int key)
    {
        auto it = ll.begin();
        while(it != ll.end())
        {
            if(it->first==key)
            {
                return it;
            }
            it++;
        }
        return ll.end();
    }


    void rehash() {
        vector<list<pair<int,int> > > arr2(2*currBuckets);
        currBuckets *= 2;

        // Go to all the elements in the old Array & add to new Array
        for(auto &ll : arr) {
            for(auto currPair : ll) {
                int newId = hash(currPair.first);
                arr2[newId].push_front(currPair);
            }
        }

        arr = arr2; // Update the arr;
    }

    double currLoadFactor() {
        return currSize/(double)currBuckets;
    }
public:
    MyHashMap() {
        currSize=0;
        currBuckets=INITIAL_CAPACITY;
        arr.resize(currBuckets);
    }
    
    void put(int key, int value) {
        int i=hash(key);
        auto it=get(arr[i],key);

        if(it!=arr[i].end()) // found
        {
            it->second=value;
        }else{
            arr[i].push_front({key, value});
            currSize++;
        }

        if(currLoadFactor()>MAX_LOAD_FACTOR)
        {
            rehash();
        }
    }
    
    int get(int key) {
        int i=hash(key);
        for(auto a : arr[i])
        {
            if(a.first == key)
            {
                return a.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i=hash(key);
        auto it=get(arr[i],key);

        if(it!=arr[i].end())
        {
            arr[i].erase(it);
            currSize--;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */