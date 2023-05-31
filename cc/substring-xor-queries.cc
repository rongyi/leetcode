// https://leetcode.com/problems/substring-xor-queries/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> substringXorQueries(string s,
                                          vector<vector<int>> &queries) {
    int sz = queries.size();
    vector<vector<int>> ret(sz, {-1, -1});
    // qi[0] ^ qi[1] to index
    map<int, vector<int>> vals;
    for (int i = 0; i < sz; i++) {
      auto q = queries[i];
      vals[q[0] ^ q[1]].push_back(i);
    }

    for (int i = 0; i < s.size(); i++) {
      long long cur = 0;
      for (int l = 0; l < 30 && i + l < s.size(); l++) {
        cur = (cur << 1) + (s[i + l] == '1');
        auto it = vals.find(cur);
        if (it != vals.end()) {
          for (auto idx : it->second) {
            ret[idx] = {i, i + l};
          }
          vals.erase(it);
        }
        // don't need leading zero
        if (s[i] == '0') {
          break;
        }
      }
    }

    return ret;
  }
};

class SolutionTLE {
public:
  vector<vector<int>> substringXorQueries(string s,
                                          vector<vector<int>> &queries) {
    auto itb = [](int i) -> string {
      if (i == 0) {
        return "0";
      }

      string s;
      while (i) {
        if (i & 1) {
          s.push_back('1');
        } else {
          s.push_back('0');
        }
        i >>= 1;
      }

      reverse(s.begin(), s.end());

      return s;
    };

    vector<vector<int>> ret;

    for (auto &q : queries) {
      int val = q[0] ^ q[1];
      string cur = itb(val);
      auto it = s.find(cur);
      if (it != string::npos) {
        int start = it;
        int end = start + cur.size() - 1;
        ret.push_back({start, end});
      } else {
        ret.push_back({-1, -1});
      }
    }

    return ret;
  }
};

