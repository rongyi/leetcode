// http://leetcode.com/problems/invalid-transactions/description/
#include "xxx.h"

class Solution {
public:
  vector<string> invalidTransactions(vector<string> &transactions) {
    unordered_set<string> ret;
    unordered_map<string, vector<vector<string>>> account;
    for (auto &t : transactions) {
      istringstream ss(t);
      //  name, time (in minutes), amount, and city
      vector<string> part(5, "");
      part[4] = t;

      int i = 0;
      while (getline(ss, part[i++], ',')) {
        ;
      }
      if (stoi(part[2]) > 1000) {
        ret.insert(t);
      }
      for (auto cur_tx : account[part[0]]) {
        if (cur_tx[3] != part[3] &&
            abs(stoi(cur_tx[1]) - stoi(part[1])) <= 60) {
          ret.insert(cur_tx[4]);
          ret.insert(t);
        }
      }
      account[part[0]].push_back({part[0], part[1], part[2], part[3], part[4]});
    }

    vector<string> vret(ret.begin(), ret.end());
    return vret;
  }
};
