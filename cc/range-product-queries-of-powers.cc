// https://leetcode.com/problems/range-product-queries-of-powers/
#include "xxx.hpp"

class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    vector<int> bits;
    for (int i = 0; i < 31; ++i) {
      if (((1 << i) & n) != 0) {
        bits.push_back(i);
      }
    }
    int sz = bits.size();
    vector<int> prefix(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      prefix[i + 1] = prefix[i] + bits[i];
    }

    vector<int> ret{};
    for (auto &q : queries) {
      int sum = prefix[q[1] + 1] - prefix[q[0] + 1 - 1];
      // will TLE
      ret.push_back(twoexpmod(sum));
    }

    return ret;
  }

private:
  int twoexpmod(int exp) {
    long long ret = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= exp; ++i) {
      ret *= 2;
      ret %= mod;
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{0, 1}};
  so.productQueries(15, input);

  return 0;
}
