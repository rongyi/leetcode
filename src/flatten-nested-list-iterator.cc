// http://leetcode.com/problems/flatten-nested-list-iterator/description/
#include "xxx.h"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) : lst_(), index_(0) {
    // now we get a flat list
    for (auto cur_ni : nestedList) {
      recur(cur_ni, lst_);
    }
  }

  int next() {
    auto i = lst_[index_++];
    return i;
  }

  bool hasNext() {
    if (lst_.empty()) {
      return false;
    }
    return index_ < lst_.size();
  }

private:
  void recur(NestedInteger &ni, vector<int> &lst) {
    if (ni.isInteger()) {
      lst.push_back(ni.getInteger());
      return;
    }
    // then this is a list
    auto nest_lst = ni.getList();
    for (auto cur_ni : nest_lst) {
      recur(cur_ni, lst);
    }
  }

private:
  vector<int> lst_;
  int index_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
