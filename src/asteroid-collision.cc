// http://leetcode.com/problems/asteroid-collision/description/
#include "xxx.h"

class Solution {
public:
  // Each asteroid will be a non-zero integer in the range [-1000, 1000].
  vector<int> asteroidCollision(vector<int> &asteroids) {
    if (asteroids.size() < 2) {
      return asteroids;
    }
    return colision(asteroids);
  }

private:
  vector<int> colision(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums;
    }
    bool has_colision = false;
    vector<int> ret;
    // 第一个元素左走，完全无害
    if (nums[0] > 0) {
      // 同向，完全无害
      if (nums[1] > 0) {
      }
      if (nums[1] < 0) {
        has_colision = true;
        auto n0 = abs(nums[0]);
        auto n1 = abs(nums[1]);
        if (n0 == n1) {
          nums[0] = 0;
          nums[1] = 0;
        } else if (n0 < n1) {
          nums[0] = 0;
        } else {
          nums[1] = 0;
        }
      }
    }
    // 最后一个元素向右走，完全无害
    int n = nums.size();
    if (nums[n - 1] < 0) {
      if (nums[n - 2] > 0) {
        has_colision = true;
        auto right = abs(nums[n - 1]);
        auto left = abs(nums[n - 2]);
        if (left == right) {
          nums[n - 1] = 0;
          nums[n - 2] = 0;
        } else if (left < right) {
          nums[n - 2] = 0;
        } else {
          nums[n - 1] = 0;
        }
      }
    }

    for (int i = 1; i < n - 1; i++) {
      int cur = nums[i];
      if (cur > 0) {
        // check right
        int right = nums[i + 1];
        if (right < 0) {
          has_colision = true;
          auto abscur = abs(cur);
          auto absright = abs(right);
          if (abscur == absright) {
            nums[i] = 0;
            nums[i + 1] = 0;
          } else if (abscur < absright) {
            nums[i] = 0;
          } else {
            nums[i + 1] = 0;
          }
        }

      } else if (cur < 0) {
        // check left
        int left = nums[i - 1];
        if (left > 0) {
          has_colision = true;
          auto absleft = abs(left);
          auto abscur = abs(cur);
          if (abscur == absleft) {
            nums[absleft] = 0;
            nums[abscur] = 0;
          } else if (abscur < absleft) {
            nums[i] = 0;
          } else {
            nums[i - 1] = 0;
          }
        }
      }
    }
    for (auto &num : nums) {
      if (num != 0) {
        ret.push_back(num);
      }
    }
    if (ret.empty()) {
      return ret;
    }
    if (has_colision) {
      return colision(ret);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{10, 2, -5};
  auto ret = so.asteroidCollision(input);
  cout << ret.size() << endl;
}
