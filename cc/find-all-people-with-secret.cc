// https://leetcode.com/problems/find-all-people-with-secret/
#include "xxx.hpp"

class Solution {
public:
  struct UnionFind {
    // each id is in its own group
    UnionFind(int n) : group_(n) { iota(group_.begin(), group_.end(), 0); }

    void connect(int l, int r) {
      int idl = find(l);
      int idr = find(r);
      group_[idl] = idr;
    }
    bool connected(int l, int r) { return find(l) == find(r); }
    // return its group
    int find(int id) {
      if (group_[id] == id) {
        return id;
      }
      return group_[id] = find(group_[id]);
    }
    void reset(int id) { group_[id] = id; }
    vector<int> group_;
  };

public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    sort(meetings.begin(), meetings.end(),
         [](auto &l, auto &r) { return l[2] < r[2]; });
    UnionFind uf(n);
    uf.connect(0, firstPerson);
    vector<int> ppl;
    int sz = meetings.size();
    for (int i = 0; i < sz;) {
      ppl.clear();
      int cur_time = meetings[i][2];
      for (; i < sz && meetings[i][2] == cur_time; ++i) {
        uf.connect(meetings[i][0], meetings[i][1]);
        ppl.push_back(meetings[i][0]);
        ppl.push_back(meetings[i][1]);
      }
      // only keep the group0, and all other group is useless
      // we clean it for next round check
      for (auto p : ppl) {
        if (!uf.connected(0, p)) {
          uf.reset(p);
        }
      }
    }
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      if (uf.connected(0, i)) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};
