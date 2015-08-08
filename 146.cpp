class LRUCache{
public:
    struct Node {
        int key;
        int val;
        Node(int k, int v): key(k), val(v) {}
    };
    LRUCache(int capacity) {
        cp = capacity;
    }
    int get(int key) {
        if (cache_index.find(key) == cache_index.end())
            return -1;
        moveToHead(key);
        return cache_index[key]->val;
    }
    void set(int key, int value) {
        if (cache_index.find(key) != cache_index.end()) {
            cache_index[key]->val = value;
            moveToHead(key);
        }
        else {
            if (cache.size() < cp) {
                cache.push_front(Node(key, value));
                cache_index[key] = cache.begin();
            }
            else {
                cache_index.erase(cache.back().key);
                cache.pop_back();
                cache.push_front(Node(key, value));
                cache_index[key] = cache.begin();
            }
        }
    }
    void moveToHead(int key) {
        auto it = cache_index[key];
        cache.erase(it);
        cache.push_front(*it);
        cache_index[key] = cache.begin();
    }
private:
    unordered_map<int, list<Node>::iterator> cache_index;
    list<Node> cache;
    int cp;
};