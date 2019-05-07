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

    vector<vector<string>> ret;
    // processed index cache
    unordered_set<int> idx;
    for (int i = 0; i < n; i++) {
      // already processed
      if (idx.find(i) != idx.end()) {
        continue;
      }
      idx.insert(i);
      string cur_name = accounts[i][0];
      unordered_set<string> &cur_set = emails[i];
      vector<string> merged_record{cur_name};

      for (int j = i + 1; j < n; j++) {
        unordered_set<string> test_set = emails[j];
        if (intersect(cur_set, test_set)) {
          // we merge j to i
          // don't process accounts[j] when we iterate to j
          idx.insert(j);
          // merget two set ==> cur_set
          for (auto &email : test_set) {
            cout << "insert: " << email << endl;
            cur_set.insert(email);
          }
        }
      }
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
  so.accountsMerge(input);
}
