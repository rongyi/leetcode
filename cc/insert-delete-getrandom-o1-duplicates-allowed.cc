// http://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
#include "xxx.hpp"

class RandomizedCollection {
public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    // 不管有没有直接塞
    v_.push_back(val);
    cache_[val].insert(v_.size() - 1);

    return cache_[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    auto it = cache_.find(val);
    if (it == cache_.end()) {
      return false;
    }
    // pick the first one and delete it
    auto target_index = *it->second.begin();

    // delete from the origin
    it->second.erase(it->second.begin());

    // swap the last element
    auto last_value = v_.back();
    // update index
    cache_[last_value].insert(target_index);
    // update value
    v_[target_index] = last_value;
    // also need to delete last index in the origin
    cache_[last_value].erase(v_.size() - 1);
    // now the last can be deleted
    v_.pop_back();

    // also need to check if the last is the only one to be delete
    if (it->second.size() == 0) {
      cache_.erase(it);
    }

    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    return v_[rand() % v_.size()];
  }

private:
  unordered_map<int, unordered_set<int>> cache_;
  vector<int> v_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
