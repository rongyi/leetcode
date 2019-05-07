// http://leetcode.com/problems/accounts-merge/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    auto rest = [](vector<string> &record) {
      unordered_set<string> ret;
      for (int i = 1; i < record.size(); i++) {
        ret.insert(record[i]);
      }
      return ret;
    };
    const int n = accounts.size();
    // cache email set
    vector<unordered_set<string>> emails;
    for (auto &account : accounts) {
      emails.push_back(rest(account));
    }
    // construct edge from node i to j
    unordered_map<int, vector<int>> chain;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (intersect(emails[i], emails[j])) {
          chain[i].push_back(j);
          chain[j].push_back(i);
        }
      }
    }

    vector<vector<string>> ret;
    // processed index cache
    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      // already processed
      if (visited.find(i) != visited.end()) {
        continue;
      }
      visited.insert(i);
      string cur_name = accounts[i][0];
      unordered_set<string> cur_set = emails[i];
      vector<string> merged_record{cur_name};
      dfs(visited, cur_set, emails, chain, i);

      for (auto &e : cur_set) {
        merged_record.push_back(e);
      }

      ret.push_back(merged_record);
    }

    for (auto &record : ret) {
      sort(next(record.begin()), record.end());
    }

    return ret;
  }
  void dfs(unordered_set<int> &visited, unordered_set<string> &eater,
           vector<unordered_set<string>> &emails,
           unordered_map<int, vector<int>> &chain, int cur_id) {
    // already visited
    // if (visited.find(cur_id) != visited.end()) {
    //   return;
    // }
    // no route come or from this node
    if (chain.find(cur_id) == chain.end()) {
      return;
    }
    visited.insert(cur_id);
    auto next_ids = chain[cur_id];
    for (auto nid : next_ids) {
      if (visited.find(nid) != visited.end()) {
        continue;
      }
      // eat them all
      for (auto &e : emails[nid]) {
        eater.insert(e);
      }
      visited.insert(nid);
      dfs(visited, eater, emails, chain, nid);
    }
  }
  bool intersect(unordered_set<string> &set1, unordered_set<string> &set2) {
    for (const auto &w : set1) {
      if (set2.find(w) != set2.end()) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<vector<string>> input{{"David", "David0@m.co", "David1@m.co"},
                               {"David", "David3@m.co", "David4@m.co"},
                               {"David", "David4@m.co", "David5@m.co"},
                               {"David", "David2@m.co", "David3@m.co"},
                               {"David", "David1@m.co", "David2@m.co"}};
  auto ret = so.accountsMerge(input);
  cout << ret.size() << endl;
}
