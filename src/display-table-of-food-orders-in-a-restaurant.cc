// http://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  vector<vector<string>> displayTable(vector<vector<string>> &orders) {
    set<string> foods;
    // table --> foods
    map<int, vector<string>> tords;

    for (auto &o : orders) {
      foods.insert(o[2]);
      tords[stoi(o[1])].push_back(o[2]);
    }
    const int n = foods.size();
    unordered_map<string, int> food_index;
    int i = 0;
    for (auto &f : foods) {
      food_index[f] = i++;
    }

    vector<string> header{"Table"};
    for (auto &f : foods) {
      header.push_back(f);
    }
    vector<vector<string>> ret;
    ret.push_back(header);

    for (auto &kv : tords) {
      vector<string> cur;
      cur.push_back(to_string(kv.first));
      vector<int> count(n, 0);
      for (auto &tf : kv.second) {
        count[food_index[tf]]++;
      }
      for (auto c : count) {
        cur.push_back(to_string(c));
      }
      ret.push_back(cur);
    }

    return ret;
  }
};
