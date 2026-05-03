class MyHashMap {
    vector<vector<pair<int, int>>> bucket;
public:
    MyHashMap() {
        // resize to make the land, not buy
        bucket.resize(10000); // 10^4
    }

    int hash(int key) {
        return key % 10000;
    }
    
    void put(int key, int value) {
        auto loc = hash(key);

        for (int i = 0; i < bucket[loc].size(); ++i) {
            if (key == bucket[loc][i].first) {
                bucket[loc][i].second = value;
                return;
            }
        }

        bucket[loc].push_back({key, value});
    }
    
    int get(int key) {
        auto loc = hash(key);

        for (int i = 0; i < bucket[loc].size(); ++i) {
            if (bucket[loc][i].first == key) {
                return bucket[loc][i].second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        auto loc = hash(key);

        for (int i = 0; i < bucket[loc].size(); ++i) {
            if (bucket[loc][i].first == key) {
                bucket[loc].erase(bucket[loc].begin() + i);
                return;
            }
        }
    }
};

/*
runtime:
    time: 24ms
    beats: 61.87%
memory:
    amt: 69.15MB
    beats: 45.66%
*/
