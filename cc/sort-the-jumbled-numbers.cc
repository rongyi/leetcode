// https://leetcode.com/problems/sort-the-jumbled-numbers/
#include "xxx.hpp"

class Solution {
public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    auto trans = [&](int num) {
      if (num == 0) {
        return mapping[num];
      }
      int digit = 1;
      int ret = 0;
      while (num) {
        ret += mapping[(num % 10)] * digit;

        num /= 10;
        digit *= 10;
      }

      return ret;
    };
    // using multimap
    multimap<int, int> relation;
    for (auto &num : nums) {
      relation.insert({trans(num), num});
    }
    nums.clear();
    for (auto &kv : relation) {
      nums.push_back(kv.second);
    }
    return nums;
  }
};

// faster than %47
class SolutionFast {
public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    vector<int> ret;
    map<int, vector<int>> decode;
    // find the origin digit which will decoded to zero
    // we just want ignore all leading zero in decoded form
    // so when we meet origin we just ignore those leading digit
    int i = 0;
    for (; i < 10; ++i) {
      if (mapping[i] == 0) {
        break;
      }
    }
    char leading_ignore = '0' + i;
    for (auto &num : nums) {
      string s = to_string(num);
      int i = 0;
      while (i < s.size() && s[i] == leading_ignore) {
        ++i;
      }

      if (i == s.size()) {
        decode[0].push_back(num);
      } else {
        s = s.substr(i);
        for (int i = 0; i < s.size(); ++i) {
          s[i] = mapping[s[i] - '0'] + '0';
        }
        auto k = stoi(s);
        decode[k].push_back(num);
      }
    }

    for (auto &kv : decode) {
      ret.insert(ret.end(), kv.second.begin(), kv.second.end());
    }

    return ret;
  }
};

class SolutionTLE {
public:
  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
    auto trans = [&](int num) {
      if (num == 0) {
        return mapping[num];
      }
      int ret = 0;
      int digit = 1;
      int cp = num;
      while (cp) {
        digit *= 10;
        cp /= 10;
      }
      digit /= 10;

      while (digit) {
        ret *= 10;
        ret += mapping[num / digit];
        num %= digit;
        digit /= 10;
      }

      return ret;
    };

    int sz = nums.size();
    vector<int> decode(sz, 0);
    map<int, int> decode_cache;
    map<int, int> index;
    for (int i = 0; i < sz; ++i) {
      if (decode_cache.count(nums[i])) {
        decode[i] = decode_cache[nums[i]];
      } else {
        // better than string
        decode[i] = trans(nums[i]);
        decode_cache[nums[i]] = decode[i];
      }
      // cout << decode[i] << "->" << nums[i] << endl;
      index[nums[i]] = i;
    }
    sort(nums.begin(), nums.end(), [&](int l, int r) {
      auto idxl = index[l];
      auto idxr = index[r];
      if (l == r) {
        return idxl < idxr;
      }
      return decode[idxl] < decode[idxr];
    });

    return nums;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> table{9, 7, 0, 6, 2, 3, 1, 4, 5, 8};
  vector<int> input{49563, 13160, 242, 87356, 7905, 649399};
  so.sortJumbled(table, input);
  return 0;
}
