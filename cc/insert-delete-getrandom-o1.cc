// http://leetcode.com/problems/insert-delete-getrandom-o1/description/
#include "xxx.hpp"

class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (cache_.find(val) != cache_.end()) {
      return false;
    }
    nums_.push_back(val);
    cache_[val] = nums_.size() - 1;

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (cache_.find(val) == cache_.end()) {
      return false;
    }
    // swap the target with last element
    auto lastvalue = nums_.back();
    // swap index, the origin place
    cache_[lastvalue] = cache_[val];
    // swap value
    nums_[cache_[val]] = lastvalue;
    // now we can do the delete action
    nums_.pop_back();
    cache_.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums_[rand() % nums_.size()];
  }
private:
  unordered_map<int, int> cache_;
  vector<int> nums_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
