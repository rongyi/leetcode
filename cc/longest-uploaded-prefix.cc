// https://leetcode.com/problems/longest-uploaded-prefix/
#include "xxx.hpp"

class LUPrefix {
public:
  LUPrefix(int n) : prefix_(0) { videos_.resize(n + 1, 0); }

  void upload(int video) {
    videos_[video] = 1;
    for (int i = prefix_ + 1; i < videos_.size(); ++i) {
      if (videos_[i] != 0) {
        prefix_ = i;
      } else {
        break;
      }
    }
  }

  int longest() { return prefix_; }

private:
  int prefix_;
  // using set is slower than vector,
  vector<int> videos_;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

int main(int argc, char *argv[]) {
  LUPrefix p(4);
  p.upload(3);
  return 0;
}
