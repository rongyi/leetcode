// http://leetcode.com/problems/employee-importance/description/
#include "xxx.h"

// Employee info
class Employee {
public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};

class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, int> score;
    unordered_map<int, vector<int>> chain;
    for (auto e : employees) {
      score[e->id] = e->importance;
      if (e->subordinates.size() > 0) {
        chain[e->id] = e->subordinates;
      }
    }
    int ret = 0;
    recur(id, score, ret, chain);
    return ret;
  }

private:
  void recur(int id, unordered_map<int, int> &score, int &ret,
             unordered_map<int, vector<int>> &chain) {
    if (score.find(id) == score.end()) {
      return;
    }
    // this value
    ret += score[id];
    // recusive get it'schildren
    if (chain.find(id) != chain.end()) {
      auto sub = chain[id];
      for (auto s : sub) {
        recur(s, score, ret, chain);
      }
    }
  }
};
