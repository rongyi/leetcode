// http://leetcode.com/problems/top-k-frequent-words/description/
#include "xxx.h"

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> count;
    for (auto w : words) {
      count[w]++;
    }
    // using set instead of unordered_set is a bit faster
    // in this case, because we need to sort the words
    // in this set, so unordered_set need extra sort action
    unordered_map<int, set<string>> group;
    for (auto kv : count) {
      group[kv.second].insert(kv.first);
    }
    priority_queue<int> pq;
    for (auto kv : group) {
      // insert key
      pq.push(kv.first);
    }
    vector<string> ret;
    const int total = k;
    while (k) {
      auto cur_freq = pq.top();
      pq.pop();

      auto cur_strs = group[cur_freq];
      // vector<string> tmp(cur_strs.begin(), cur_strs.end());
      for (auto it = cur_strs.begin(); it != cur_strs.end(); it++) {
        ret.push_back(*it);
        if (ret.size() == total) {
          goto out;
        }
      }

      k--;
    }
  out:
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"i", "love", "leetcode", "i", "love", "coding"};
  auto tops = so.topKFrequent(input, 2);
  for_each(tops.begin(), tops.end(), [](const string &s) { cout << s << " "; });
  cout << endl;
}
