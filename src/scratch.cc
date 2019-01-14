#include "xxx.h"
class Solutionmq {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};

class Solution {
public:
  // void dfs(vector<vector<int>> &grid, int i, int j, vector<string> path) {
  //   const int m = grid.size();
  //   const int n = grid[0].size();
  //   if (i >= m || j >= n) {
  //     return;
  //   }
  //   stringstream ss;
  //   ss << "i: " << i << " j:" << j;
  //   path.push_back(ss.str());

  //   if (i == m - 1 && j == n - 1) {
  //     for (auto p : path) {
  //       cout << p << endl;
  //     }
  //     cout << "==========" << endl;
  //     return;
  //   }

  //   dfs(grid, i + 1, j, path);
  //   dfs(grid, i, j + 1, path);
  // }
  void dfs(string input, vector<int> &res) {
    if (input.size() == 0)
      return;
    bool all_digit = true;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        all_digit = false;
        vector<int> l, r;
        dfs(input.substr(0, i), l);
        dfs(input.substr(i + 1, input.size() - i), r);
        for (auto x : l) {
          for (auto y : r) {
            if (input[i] == '+')
              res.push_back(x + y);
            else if (input[i] == '-')
              res.push_back(x - y);
            else
              res.push_back(x * y);
          }
        }
      }
    }
    if (all_digit)
      res.push_back(stoi(input));
  }
};

class Solution2 {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    int size = input.size();
    for (int i = 0; i < size; i++) {
      char cur = input[i];
      if (cur == '+' || cur == '-' || cur == '*') {
        // Split input string into two parts and solve them recursively
        vector<int> result1 = diffWaysToCompute(input.substr(0, i));
        vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
        for (auto n1 : result1) {
          cout << n1 << "  n1" << endl;
          for (auto n2 : result2) {
            if (cur == '+')
              result.push_back(n1 + n2);
            else if (cur == '-')
              result.push_back(n1 - n2);
            else
              result.push_back(n1 * n2);
          }
        }
      }
    }
    // if the input string contains only number
    if (result.empty())
      result.push_back(atoi(input.c_str()));
    return result;
  }
};

struct mycompare {
  bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.first + p1.second < p2.first + p2.second;
  }
};

int main() {
  // Solution so;
  // vector<vector<int>> input{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  // vector<string> path;
  // so.dfs(input, 0, 0, path);

  // unordered_map<int, int> test;
  // test[1] = 1;
  // for (int i = 0; i < 2; i++) {
  //   --test[i];
  // }
  // for (auto kv : test) {
  //   cout << kv.first << "--> " << kv.second << endl;
  // }

  // bool b1 = true;
  // bool b2 = false;
  // if (b1 ^ b2) {
  //   cout << "yes" << endl;
  // }

  // Solution2 so;
  // auto ret = so.diffWaysToCompute("2-1-1");
  // for (auto i : ret) {
  //   cout << i << endl;
  // }

  // Solutionmq so;
  // vector<int> input{1, 3, -1, -3, 5, 3, 6, 7};
  // auto ret = so.maxSlidingWindow(input, 3);
  // for (auto i : ret) {
  //   cout << i << endl;
  // }

  // priority_queue<int, vector<int>, std::less<int>> max_heap;
  // max_heap.push(1);
  // max_heap.push(2);
  // cout << max_heap.top() << endl;

  // priority_queue<int, vector<int>, std::greater<int>> min_heap;
  // min_heap.push(1);
  // min_heap.push(2);
  // cout << min_heap.top() << endl;

  // string s{"324"};
  // int i = 0;
  // if (s[0] == '-') {
  //   i++;
  // }
  // int j = i;
  // while (s[j] <= '9' && s[j] >= '0') {
  //   j++;
  // }
  // string number = s.substr(i, j - i);
  // cout << number << endl;

  // vector<int> i{1, 2, 3, 4};
  // i.erase(next(next(i.begin())));
  // cout << i.size() << endl;
  // for (int j = 0; j < i.size(); j++) {
  //   cout << i[j] << endl;
  // }

  // priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
  // pq.push({1, 3});
  // pq.push({1, 2});
  // cout << pq.top().first << "   :    " << pq.top().second << endl;
  // pq.pop();

  // cout << pq.top().first << "   :    " << pq.top().second << endl;

  // set::lower_bound/upper_bound
  // std::set<int> myset;
  // std::set<int>::iterator itlow, itup;

  // for (int i = 1; i < 10; i++) {
  //   myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
  // }

  // // >= 28里面找最小的
  // itlow = myset.lower_bound(29);
  // cout << *itlow << endl;
  // // 大于81的第一个
  // itup = myset.upper_bound(81);
  // cout << *itup << endl;

  // myset.erase(itlow, itup); // 10 20 70 80 90

  // std::cout << "myset contains:";
  // for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
  //   std::cout << ' ' << *it;
  // }
  // std::cout << '\n';

  unordered_map<int, unordered_set<int>> s;
  s[1].insert(2);
  for (auto i : s[1]) {
    cout << i << endl;
  }
}

// void inorder(TreeNode *root) {
//   if (!root)
//     return;
//   inorder(root->left);
//   if (!pre)
//     pre = root;
//   else {
//     if (pre->val > root->val) {
//       if (!first)
//         first = pre;
//       second = root;
//     }
//     pre = root;
//   }
//   inorder(root->right);
// }
