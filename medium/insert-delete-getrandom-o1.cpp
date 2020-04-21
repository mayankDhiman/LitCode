// 380. Insert Delete GetRandom O(1)
// Design Question


class RandomizedSet {
public:
    /** Initialize your data structure here. */    
    RandomizedSet() {
        a.clear();
        inc.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ok = (inc[val] == 0);
        a.insert(val);
        inc[val] = 1;
        return ok;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ok = (inc[val] > 0);
        a.erase(val);        
        inc[val] = 0;
        return ok;    
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        vector <int> x(a.begin(), a.end());
        int s = x.size();
        int ix = rand() % s;
        return x[ix];
    }
    
private: // Always in Private
    unordered_set <int> a;
    unordered_map <int, int> inc; 

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
