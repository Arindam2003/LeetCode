class MyHashMap {
    vector<list<pair<int, int>>> arr;
    const int initial_capacity = 1;
    int cap, bucketSize;
    const double MAX_LOAD_FACTOR=0.75;
public:
    int blackBox(int key) { return key % bucketSize; }

    void reHash()
    {
        vector<list<pair<int, int>>> arr2;
        bucketSize=2*bucketSize;
        arr2.resize(bucketSize);
        for(auto a:arr)
        {
            for (auto x:a)
            {
                int newIndex=blackBox(x.first);
                arr2[newIndex].push_back({x.first,x.second});
            }
        }

        arr=arr2;
    }

    MyHashMap() {
        bucketSize = initial_capacity;
        cap = 0;
        arr.resize(bucketSize);
    }

    void put(int key, int value) {
        int currIndex = blackBox(key);

        for (auto &a : arr[currIndex]) {
            if (a.first == key) {
                a.second = value;
                return;
            }
        }
        arr[currIndex].push_back({key, value});
        cap++;

        double currLoadFactor=(double)cap/bucketSize;
        
        if(currLoadFactor>MAX_LOAD_FACTOR)
        {
            reHash();
        }
    }

    int get(int key) {
        int currIndex = blackBox(key);
        for (auto a : arr[currIndex]) {
            if (a.first == key) {
                return a.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int currIndex = blackBox(key);
        auto it = arr[currIndex].begin();

        while (it != arr[currIndex].end()) {
            if (it->first == key) {
                arr[currIndex].erase(it);
                return;
            }

            ++it;
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