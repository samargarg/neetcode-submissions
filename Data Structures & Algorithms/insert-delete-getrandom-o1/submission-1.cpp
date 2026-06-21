class RandomizedSet {

    unordered_map<int, int> s;
    vector<int> l;
public:
    RandomizedSet() {
        l.clear();
        s.clear();
    }
    
    bool insert(int val) {
        if (s.count(val)) {
            return true;
        } else {
            s[val] = l.size();
            l.push_back(val);
            return false;
        }
    }
    
    bool remove(int val) {
        if (s.count(val)) {
            int org_index = s[val];
            int last_val = l[l.size()-1];
            s[last_val] = org_index;
            l[org_index] = last_val;
            l.pop_back();
            s.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int ran = rand() % l.size();
        return l[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */