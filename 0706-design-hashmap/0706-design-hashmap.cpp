class MyHashMap {
    vector<list<pair<int, int>>> arr;
    int const initial_capacity = 1;
    int cap, bucketSize;

public:
    int blackBox(int key) { return key % bucketSize; }

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