// http://leetcode.com/problems/clone-graph/description/
#include "xxx.hpp"

/**
 * Definition for undirected graph.
 */
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int, UndirectedGraphNode*> cache;
    return doClone(node, cache);
  }
private:
  UndirectedGraphNode* doClone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &cache) {
    if (!node) {
      return nullptr;
    }
    if (cache.find(node->label) != cache.end()) {
      return cache[node->label];
    }

    // copy action
    UndirectedGraphNode *cp = new UndirectedGraphNode(node->label);
    cache.insert(make_pair(node->label, cp));
    for (auto cur_neb : node->neighbors) {
      UndirectedGraphNode *cp_nei = doClone(cur_neb, cache);

      cp->neighbors.push_back(cp_nei);
    }

    return cp;
  }
};
