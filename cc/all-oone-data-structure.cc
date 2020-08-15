// http://leetcode.com/problems/all-oone-data-structure/description/
#include "xxx.h"

class AllOne {
public:
  void inc(string key) {
    if (!bucket_key_map_.count(key)) {
      bucket_key_map_[key] = buckets_.insert(buckets_.begin(), {
                                                                   0,
                                                                   {key},
                                                               });
    }
    auto cur_buck = bucket_key_map_[key];
    auto next_buck = next(cur_buck);
    // there's a gap, need to create a new node
    if (next_buck == buckets_.end() ||
        next_buck->value_ > cur_buck->value_ + 1) {
      next_buck = buckets_.insert(next_buck, {
                                                 cur_buck->value_ + 1,
                                                 {},
                                             });
    }
    next_buck->keys_.insert(key);
    bucket_key_map_[key] = next_buck;

    cur_buck->keys_.erase(key);
    if (cur_buck->keys_.empty()) {
      buckets_.erase(cur_buck);
    }
  }

  void dec(string key) {
    // do nothing when key not exist
    if (!bucket_key_map_.count(key)) {
      return;
    }
    auto cur_buck = bucket_key_map_[key];
    auto prev_buck = prev(cur_buck);

    bucket_key_map_.erase(key);

    if (cur_buck->value_ > 1) {
      // 需要一个新节点
      if (cur_buck == buckets_.begin() ||
          prev_buck->value_ < cur_buck->value_ - 1) {
        prev_buck = buckets_.insert(cur_buck, {
                                                  cur_buck->value_ - 1,
                                                  {},
                                              });
      }
      prev_buck->keys_.insert(key);
      bucket_key_map_[key] = prev_buck;
    }

    cur_buck->keys_.erase(key);
    if (cur_buck->keys_.empty()) {
      buckets_.erase(cur_buck);
    }
  }

  string getMaxKey() {
    if (buckets_.empty()) {
      return "";
    }
    return *buckets_.rbegin()->keys_.begin();
  }

  string getMinKey() {
    if (buckets_.empty()) {
      return "";
    }
    return *buckets_.begin()->keys_.begin();
  }

private:
  struct Bucket {
    int value_;
    unordered_set<string> keys_;
  };
  list<Bucket> buckets_;
  unordered_map<string, list<Bucket>::iterator> bucket_key_map_;
};
int main() {
  AllOne so;
  so.inc("hello");
  so.inc("hello");
  so.inc("fail");
}
