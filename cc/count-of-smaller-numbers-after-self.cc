// http://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int sz = nums.size();

    vector<int> index(sz, 0);
    iota(index.begin(), index.end(), 0);

    vector<int> ret(sz, 0);
    mergesort(nums, 0, sz, index, ret);

    return ret;
  }

private:
  void mergesort(vector<int> &nums, int start, int end, vector<int> &index,
                 vector<int> &ret) {
    int len = end - start;
    if (len <= 1) {
      return;
    }
    int step = len / 2;
    int mid = start + step;
    mergesort(nums, start, mid, index, ret);
    mergesort(nums, mid, end, index, ret);

    vector<int> tmp_idx;
    tmp_idx.reserve(len);
    int idx1 = start;
    int idx2 = mid;
    int low_cnt = 0;

    while (idx1 < mid || idx2 < end) {
      if (idx2 == end ||
          (idx1 < mid && nums[index[idx1]] <= nums[index[idx2]])) {
        tmp_idx.push_back(index[idx1]);
        ret[index[idx1]] += low_cnt;
        ++idx1;
      } else {
        tmp_idx.push_back(index[idx2]);
        ++low_cnt;
        ++idx2;
      }
    }

    move(tmp_idx.begin(), tmp_idx.end(), index.begin() + start);
  }
};

class SolutionTLE {
public:
  vector<int> countSmaller(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return vector<int>{};
    }
    if (n == 1) {
      return vector<int>{0};
    }

    vector<int> ret(n, 0);
    Node *root = nullptr;
    for (int i = n - 1; i >= 0; --i) {
      ret[i] = insert(&root, root, nums[i]);
    }

    return ret;
  }

private:
  struct Node {
    int val_;
    int less_than_;
    int count_;
    int space_;
    Node *left_;
    Node *right_;
    Node(int val)
        : val_(val), less_than_(0), count_(1), left_(nullptr), right_(nullptr) {
    }
  };

  int insert(Node **parent, Node *node, int val) {
    if (!node) {
      *parent = new Node(val);
      return 0;
    } else if (val < node->val_) {
      // 左子数的个数统计都在当前这个节点上，如果
      // 左子数为空此field的值还是为零
      node->less_than_++;
      return insert(&node->left_, node->left_, val);
    } else if (val == node->val_) {
      node->count_++;
      return node->less_than_;
    } else {
      return node->less_than_ + node->count_ +
             insert(&node->right_, node->right_, val);
    }
  }
};
