// http://leetcode.com/problems/distribute-candies/description/
#include "xxx.hpp"

class Solution {
public:
  int distributeCandies(vector<int> &candies) {
    const int num_each = candies.size() / 2;
    unordered_map<int, int> type_count;
    for (auto c : candies) {
      type_count[c]++;
    }
    unordered_map<int, vector<int>> group_by_count;
    for (auto kv : type_count) {
      group_by_count[kv.second].push_back(kv.first);
    }
    int ret = 0;
    // 妹妹先把所有仅有一个的全部拿走，这样能保证她
    // 能最大化不同种类
    for (auto kv : group_by_count) {
      if (kv.first == 1) {
        ret += kv.second.size();
        group_by_count.erase(kv.first);
        break;
      }
    }
    // single color cookie too much
    if (ret >= num_each) {
      return num_each;
    }
    // 现在还不满，那么就尽可能的去每个里面挑不同的颜色
    for (auto kv : group_by_count) {
      ret += kv.second.size();
      if (ret >= num_each) {
        return num_each;
      }
    }
    // 后面怎么分均衡已经不重要了，反正能平衡下来
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 0, 14, 0, 10, 0, 0, 0};
  auto ret = so.distributeCandies(input);
  cout << ret << endl;
}
