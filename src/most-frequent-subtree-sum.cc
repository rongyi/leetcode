// http://leetcode.com/problems/most-frequent-subtree-sum/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    if (!root) {
      return {};
    }
    unordered_map<TreeNode *, int> sum_cache;
    recur(root, sum_cache);
    int max_occ = numeric_limits<int>::min();
    unordered_map<int, int> count;
    for (auto kv : sum_cache) {
      count[kv.second]++;
      max_occ = max(max_occ, count[kv.second]);
    }
    vector<int> ret;
    for (auto kv : count) {
      if (kv.second == max_occ) {
        ret.push_back(kv.first);
      }
    }

    return ret;
  }
private:
  int recur(TreeNode *root, unordered_map<TreeNode *, int> &sum_cache) {
    int sum = root->val;

    if (root->left) {
      if (sum_cache.find(root->left) == sum_cache.end()) {
        sum += recur(root->left, sum_cache);
      } else {
        sum += sum_cache[root->left];
      }
    }

    if (root->right) {
      if (sum_cache.find(root->right) == sum_cache.end()) {
        sum += recur(root->right, sum_cache);
      } else {
        sum += sum_cache[root->right];
      }
    }

    sum_cache[root] = sum;

    return sum;
  }
};

int main() {
  Solution so;
  TreeNode root(5), left(2), right(-3);
  root.left = &left;
  root.right = &right;

  so.findFrequentTreeSum(&root);
}
