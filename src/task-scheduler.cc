// http://leetcode.com/problems/task-scheduler/description/
#include "xxx.h"

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> count(26, 0);
    for (auto c : tasks) {
      count[c - 'A']++;
    }
    sort(count.begin(), count.end());
    int i = 25;
    while (i >= 0 && count[i] == count[25]) {
      i--;
    }
    int repeat = 25 - i;
    int slot_count = count[25] - 1;
    // 1个就是n 个xxx
    int slot_len = n - (repeat - 1);
    int empty_slots = slot_count * slot_len;
    int available_tasks = tasks.size() - count[25] * repeat;
    int idles = max(0, empty_slots - available_tasks);

    return tasks.size() + idles;
  }
};

int main() {
  Solution so;
  vector<char> input{'A', 'A', 'A', 'B', 'B', 'B'};
  auto ret = so.leastInterval(input, 2);
  cout << ret << endl;
}
