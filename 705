class MyHashSet {
vector<vector<int>> bucket;
public:
    MyHashSet() {
        // 'at most 10^4 calls will be made to add, remove, & contain'
        bucket.resize(10000);
    }

    int bucketLocation(int key) {
        return key % 10000;
    }
    
    void add(int key) {
        auto loc = bucketLocation(key);

        if(contains(key)) {
            return;
        }

        bucket[loc].push_back(key);
    }
    
    void remove(int key) {
        auto loc = bucketLocation(key);

        for (int i; i < bucket[loc].size(); ++i) {
            if (bucket[loc][i] == key) {
                bucket[loc].erase(bucket[loc].begin() + i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        auto loc = bucketLocation(key);

        if (bucket[loc].size() == 0) {
            return false;
        }

        for (auto val : bucket[loc]) {
            if (val == key) {
                return true;
            }
        }

        return false;
    }
};

/*
runtime:
    time:17ms
    beats: 48.80%
    
memory:
    amt: 56.25MB
    beats: 22.71
*/
