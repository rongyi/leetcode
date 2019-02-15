// http://leetcode.com/problems/minimum-genetic-mutation/description/
#include "xxx.h"

class Solution {
public:
  int minMutation(string start, string end, vector<string> &bank) {
    unordered_set<string> dict(bank.begin(), bank.end());
    // end must be in bank
    if (!dict.count(end)) {
      return -1;
    }
    // start may or may not in bank, so ensure it
    dict.insert(start);
    queue<string> visit_quque;
    visit_quque.push(start);

    int ret = 0;
    while (!visit_quque.empty()) {
      const int n = visit_quque.size();
      // 按照BFS，每一轮在队列中的都是修改的一个维度的所有可能
      // 如果在这些可能中找到目标end则返回
      for (int i = 0; i < n; i++) {
        auto cur = visit_quque.front();
        visit_quque.pop();
        if (cur == end) {
          return ret;
        }
        edit(cur, dict, visit_quque);
      }
      // 否则，又增加一轮维度，像层序遍历一下增加了一层高度
      ret++;
    }


    return -1;
  }

private:
  void edit(string cur, unordered_set<string> &dict,
            queue<string> &visit_quque) {
    // clear cur in dict to make it not go this way
    dict.erase(cur);
    for (int i = 0; i < cur.size(); i++) {
      auto origin = cur[i];
      for (auto c : "ACGT") {
        cur[i] = c;
        if (dict.count(cur)) {
          visit_quque.push(cur);
          dict.erase(cur);
        }
      }

      // restore
      cur[i] = origin;
    }
  }
};

int main() {
  Solution so;
  vector<string> input{"AACCGGTA"};
  auto ret = so.minMutation("AACCGGTT", "AACCGGTA", input);
  cout << ret << endl;
}
