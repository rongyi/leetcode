// https://leetcode.com/problems/process-restricted-friend-requests/
#include "xxx.hpp"

class Solution {
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
    vector<int> group_;
  };

public:
  vector<bool> friendRequests(int n, vector<vector<int>> &restrictions,
                              vector<vector<int>> &requests) {
    vector<bool> ret;
    UnionFind uf(n);
    for (auto &req : requests) {
      auto l = uf.find(req[0]);
      auto r = uf.find(req[1]);
      bool valid = true;
      if (!uf.connected(l, r)) {
        for (auto &ban : restrictions) {
          auto x = uf.find(ban[0]);
          auto y = uf.find(ban[1]);
          if ((l == x && r == y) || (l == y && r == x)) {
            valid = false;
            break;
          }
        }
      }
      ret.push_back(valid);
      if (valid) {
        uf.connect(l, r);
      }
    }

    return ret;
  }
};
