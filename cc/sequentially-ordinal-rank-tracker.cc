// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/
#include "xxx.hpp"

class SORTracker {
public:
  SORTracker() {}

  void add(string name, int score) {
    auto it = sorted_.insert({-score, name}).first;
    if (cur_ == sorted_.end() || (*it) < (*cur_)) {
      --cur_;
    }
  }

  string get() { return (cur_++)->second; }

private:
  set<pair<int, string>> sorted_;
  decltype(sorted_)::iterator cur_ = sorted_.end();
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

int main() {
  set<pair<int, string>> s;
  s.insert({-1, "hello"});
  s.insert({-2, "hello"});
  s.insert({-2, "hell"});
  for (auto &k : s) {
    cout << k.first << ", " << k.second << endl;
  }
}

