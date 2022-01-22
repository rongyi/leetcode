// http://leetcode.com/problems/design-circular-deque/description/
#include "xxx.hpp"

class MyCircularDeque {
public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) : n_(k), readable_(0), front_(k - 1), rear_(0) {
    data_ = vector<int>(n_, 0);
  }

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    // full?
    if (readable_ == n_) {
      return false;
    }
    data_[front_] = value;

    readable_++;
    front_ = (front_ - 1 + n_) % n_;

    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    // full?
    if (readable_ == n_) {
      return false;
    }
    data_[rear_] = value;
    readable_++;
    rear_ = (rear_ + 1) % n_;

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (readable_ == 0) {
      return false;
    }
    front_ = (front_ + 1) % n_;
    readable_--;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (readable_ == 0) {
      return false;
    }
    rear_ = (rear_ - 1 + n_) % n_;
    readable_--;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (readable_ == 0) {
      return -1;
    }
    return data_[(front_ + 1) % n_];
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (readable_ == 0) {
      return -1;
    }
    return data_[(rear_ - 1 + n_) % n_];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return readable_ == 0; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return readable_ == n_; }

private:
  vector<int> data_;
  int n_;
  int readable_;
  int front_;
  int rear_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
