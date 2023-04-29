// http://leetcode.com/problems/peeking-iterator/description/
#include "xxx.hpp"

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int> &nums)
      : Iterator(nums), peeked_(false), peek_val_(0) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!peeked_) {
      peek_val_ = next();
      peeked_ = true;
    }

    return peek_val_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (peeked_) {
      // peek value is invalidated
      peeked_ = false;
      return peek_val_;
    }

    return Iterator::next();
  }

  bool hasNext() const {
    if (peeked_) {
      return true;
    }
    return Iterator::hasNext();
  }

private:
  int peek_val_;
  bool peeked_;
};
