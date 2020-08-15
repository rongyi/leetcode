// http://leetcode.com/problems/iterator-for-combination/description/
#include "xxx.h"

class CombinationIterator {
public:
  CombinationIterator(string s, int k) {
    string tmp{};

    // select k from n in string s, start with index 0
    dfs(s, s.size(), k, 0, tmp);
  }

  string next() {
    auto cur = cache_.top();
    cache_.pop();

    return cur;
  }

  bool hasNext() { return !cache_.empty(); }

private:
  // copy from combination
  void dfs(string &raw, int n, int k, int idx, string cur) {
    if (cur.size() == k) {
      cache_.push(cur);
      return;
    }

    if (idx >= n) {
      return;
    }
    // don't pick current
    dfs(raw, n, k, idx + 1, cur);

    // pick current
    cur.push_back(raw[idx]);
    dfs(raw, n, k, idx + 1, cur);
  }

private:
  priority_queue<string, vector<string>, greater<string>> cache_;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(s,
 * clen); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */

int main() {
  CombinationIterator ci("abc", 2);
  cout << ci.next() << endl;
  cout << ci.next() << endl;
  cout << ci.next() << endl;
}
