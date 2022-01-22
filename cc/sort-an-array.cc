// http://leetcode.com/problems/sort-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    const int n = nums.size();
    quickSort(nums, 0, n - 1);
    return nums;
  }

private:
  // 什么是quicksort，就是随机找一个值，然后左边的都比塔小
  // 右边的都比塔大，违反规矩的，交换
  void quickSort(vector<int> &array, int low, int high) {
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i < j) {
      while (array[i] < pivot)
        i++;
      while (array[j] > pivot)
        j--;
      if (i <= j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
      }
    }
    if (j > low)
      quickSort(array, low, j);
    if (i < high)
      quickSort(array, i, high);
  }
};

int main() {
  Solution so;
  vector<int> nums{1, 2, 7, 3, 4};
  so.sortArray(nums);
  for (auto n : nums) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
