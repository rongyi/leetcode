// http://leetcode.com/problems/average-of-levels-in-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<vector<int>> vec;
    level(root, 1, vec);
    vector<double> ret;
    for (auto l : vec) {
      ret.push_back(accumulate(l.begin(), l.end(), 0.0) / l.size());
    }

    return ret;
  }
  void level(TreeNode *root, int cur_level, vector<vector<int>> &vec) {
    if (!root) {
      return;
    }
    if (vec.size() < cur_level) {
      vec.push_back({});
    }
    vec[cur_level - 1].push_back(root->val);
    level(root->left, cur_level + 1, vec);
    level(root->right, cur_level + 1, vec);
  }
};
