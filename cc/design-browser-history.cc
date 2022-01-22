// http://leetcode.com/problems/design-browser-history/description/
#include "xxx.hpp"

class BrowserHistory {
public:
  BrowserHistory(string homepage) {
    forward_.clear();
    visited_.clear();
    visited_.push_back(homepage);
  }

  void visit(string url) {
    visited_.push_back(url);
    forward_.clear();
  }

  string back(int steps) {
    if (visited_.empty()) {
      return "";
    }
    int real_steps = min(steps, (int)visited_.size() - 1);
    while (real_steps) {
      auto last = visited_.back();
      forward_.push_back(last);
      visited_.pop_back();
      real_steps--;
    }

    return visited_.back();
  }

  string forward(int steps) {
    if (forward_.empty()) {
      // 返回的值也要看题目要什么
      return visited_.back();
    }
    // 边界很烦
    int real_steps = min(steps, (int)forward_.size());
    while (real_steps) {
      auto last = forward_.back();
      visited_.push_back(last);
      forward_.pop_back();
      real_steps--;
    }

    return visited_.back();
  }

private:
  vector<string> visited_;
  vector<string> forward_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
  BrowserHistory browserHistory = BrowserHistory("zav.com");
  browserHistory.visit("kni.com");
  auto back = browserHistory.back(7);
  cout << back << endl;

  back = browserHistory.back(7);
  cout << back << endl;

  auto f = browserHistory.forward(5);
  cout << f << endl;

  // browserHistory.visit("linkedin.com");
  // browserHistory.forward(2);
  // browserHistory.back(2);

  // browserHistory.back(7);
}
