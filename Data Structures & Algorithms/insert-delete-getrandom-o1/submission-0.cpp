class RandomizedSet {

    unordered_set<int> s;
public:
    RandomizedSet() {
        
        s.clear();
    }
    
    bool insert(int val) {
        if (s.count(val)) {
            return true;
        } else {
            s.insert(val);
            return false;
        }
    }
    
    bool remove(int val) {
        if (s.count(val)) {
            s.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        return *s.begin();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */