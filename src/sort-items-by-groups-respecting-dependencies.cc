// http://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &before_items) {
    // group之间的依赖, key是group number，value也是group number序列
    unordered_map<int, vector<int>> inter;
    // 每一个group内部之间元素的依赖，map中的key是node编号，value是node编号序列
    vector<unordered_map<int, vector<int>>> inner_of_group(m);
    // 没有group的那些也给他分一个独立的group
    for (int i = 0; i < group.size(); ++i) {
      if (group[i] == -1) {
        group[i] = m++;
        inner_of_group.resize(m);
      }
      // 先有group[i],依赖谁咱先不说
      inter[group[i]] = {};
      // 在group[i]中有i这个node，依赖谁咱先不说
      inner_of_group[group[i]][i] = {};
    }

    // 第i个节点前面必须要存在bi节点
    // 以树表示就是 bi --> i 有一条边
    // dfs recursive visit will first visit i
    // then bi, the order is recorded in group_order
    // and inner_order
    for (int i = 0; i < n; ++i) {
      for (auto const &bi : before_items[i]) {
        if (group[i] == group[bi]) {
          inner_of_group[group[bi]][bi].push_back(i);
        } else {
          inter[group[bi]].push_back(group[i]);
        }
      }
    }

    // inter group
    list<int> group_order;
    if (!topo_sort(inter, group_order)) {
      return {};
    }

    vector<list<int>> inner_order(m);
    for (int i = 0; i < m; ++i) {
      if (!topo_sort(inner_of_group[i], inner_order[i])) {
        return {};
      }
    }

    list<int> ret;
    for (auto &i : group_order) {
      ret.splice(ret.end(), inner_order[i]);
    }

    return vector<int>(ret.begin(), ret.end());
  }

private:
  bool topo_sort(unordered_map<int, vector<int>> &g, list<int> &topo) {
    unordered_map<int, int> visited;
    for (const auto &kv : g) {
      if (!dfs(kv.first, g, topo, visited)) {
        return false;
      }
    }
    return true;
  }
  bool dfs(int i, unordered_map<int, vector<int>> &g, list<int> &topo,
           unordered_map<int, int> &visited) {
    if (visited[i] == -1) {
      return false;
    }
    if (visited[i] == 0) {
      visited[i] = -1;
      for (auto &j : g[i]) {
        if (!dfs(j, g, topo, visited)) {
          return false;
        }
      }
      visited[i] = 1;
      // 依赖的节点都在后面，所以，后面的节点应该是先
      // 这里有一张图片简单明了
      // https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/discuss/402945/C%2B%2B-with-picture-generic-topological-sort
      topo.push_front(i);
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<int> group{-1, -1, 1, 0, 0, 1, 0, -1};
  vector<vector<int>> bi{{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
  so.sortItems(8, 2, group, bi);
}
