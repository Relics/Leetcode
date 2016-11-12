class RandomizedSet {
private:
    unordered_map<int, int> umap;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.find(val) != umap.end()) return false;
        v.push_back(val);
        umap[val] = (int)v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (umap.find(val) == umap.end()) return false;
        int position = umap[val];
        umap[v.back()] = position;
        swap(v[position], v[(int)v.size()-1]);
        v.pop_back();
        umap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return (int)v.size() > 0 ? v[rand()%((int)v.size())] : -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */