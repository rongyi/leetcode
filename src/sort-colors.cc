// http://leetcode.com/problems/sort-colors/description/
#include "xxx.h"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    const int n = nums.size();

    int red = 0;
    int blue = n - 1;
    for (int i = 0; i < blue + 1;) {
      if (nums[i] == 0) {
        swap(nums[i++], nums[red++]);
      } else if (nums[i] == 2) {
        // 这里还要继续判断换过来的数字是不是0,所以没有加1
        swap(nums[i], nums[blue--]);
      } else {
        i++;
      }
    }

  }
};

int main() {
  Solution so;
  vector<int> input{0, 1};
  so.sortColors(input);
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}
