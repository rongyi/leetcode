// http://leetcode.com/problems/design-hashset/description/
#include "xxx.h"

class MyHashSet {
public:
  /** Initialize your data structure here. */
  MyHashSet() { fill(data_, data_ + 1000001, 0); }

  void add(int key) { data_[key] = true; }

  void remove(int key) { data_[key] = false; }

  /** Returns true if this set contains the specified element */
  bool contains(int key) { return data_[key]; }

private:
  bool data_[1000001];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
