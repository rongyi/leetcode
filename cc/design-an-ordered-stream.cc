// http://leetcode.com/problems/design-an-ordered-stream/description/
#include "xxx.hpp"

// 喷的很惨
// 看描述完全不知道在讲啥，看那张动图
class OrderedStream {
public:
  OrderedStream(int n) : stream_(n + 1), ptr_(1) {}

  vector<string> insert(int idKey, string value) {
    stream_[idKey] = value;
    vector<string> ret;
    while (ptr_ < stream_.size() && stream_[ptr_] != "") {
      ret.push_back(stream_[ptr_++]);
    }
    return ret;
  }

private:
  int ptr_;
  vector<string> stream_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
