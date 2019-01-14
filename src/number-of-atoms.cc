// http://www.lintcode.com/zh-cn/problem/number-of-atoms

#include "xxx.h"
class Solution {
public:
  string countOfAtoms(string formula) {
    stack<map<string, int>> stk;
    map<string, int> cur;

    const int n = formula.size();
    for (int i = 0; i < n;) {
      if (formula[i] == '(') {
        i++;
        // 意思是把这一层统计压栈，同时清空cur
        stk.push(move(cur));
      } else if (formula[i] == ')') {
        // i++;
        // collect the multiply coeffient
        int j = i + 1;
        while (j < n && isdigit(formula[j])) {
          j++;
        }
        int multi = stoi(formula.substr(i + 1, j - i - 1));

        // 统计之后恢复cur，出栈
        for (auto c : cur) {
          stk.top()[c.first] += c.second * multi;
        }
        cur = move(stk.top());
        stk.pop();

        i = j;
      } else {
        int j = i + 1;
        while (j < n && islower(formula[j])) {
          j++;
        }
        string ele{""};
        // only captial element
        if (j == (i + 1)) {
          ele = formula[i];
        } else {
          ele = formula.substr(i, j - i);
        }
        // cout << ele << " ";

        int k = j;
        while (k < n && isdigit(formula[k])) {
          k++;
        }
        int num = 1;
        if (k != j) {
          num = stoi(formula.substr(j, k - j));
        }
        // cout << num << endl;
        // stk.push(ele + ":" + num);
        cur[ele] += num;

        i = k;
      }
    }
    // now we have a stack with no parent
    string ret;
    for (auto a : cur) {
      ret += a.first + (a.second == 1 ? "" : to_string(a.second));
    }

    return ret;
  }
  // 字符串转来转去要吐血了， fuck
  string countOfAtomsLame(string formula) {
    stack<string> stk;
    const int n = formula.size();
    for (int i = 0; i < n;) {
      if (formula[i] == '(') {
        stk.push("(");
        i++;
      } else if (formula[i] == ')') {
        // i++;
        // collect the multiply coeffient
        int j = i + 1;
        while (j < n && isdigit(formula[j])) {
          j++;
        }
        int multi = stoi(formula.substr(i + 1, j - i - 1));
        // cout << "multiply digit: " << multi << endl;

        vector<string> tmp;
        while (!stk.empty() && stk.top() != "(") {
          auto cur = stk.top();
          stk.pop();
          tmp.push_back(multiply(cur, multi));
        }
        // pop the left "("
        stk.pop();
        // and now push all the new ele
        for (int i = tmp.size() - 1; i >= 0; --i) {
          stk.push(tmp[i]);
        }

        i = j;
      } else {
        int j = i + 1;
        while (j < n && islower(formula[j])) {
          j++;
        }
        string ele{""};
        // only captial element
        if (j == (i + 1)) {
          ele = formula[i];
        } else {
          ele = formula.substr(i, j - i);
        }
        // cout << ele << " ";

        int k = j;
        while (k < n && isdigit(formula[k])) {
          k++;
        }
        string num = "1";
        if (k != j) {
          num = formula.substr(j, k - j);
        }
        // cout << num << endl;
        stk.push(ele + ":" + num);

        i = k;
      }
    }
    // now we have a stack with no parent
    vector<string> sorted;
    while (!stk.empty()) {
      auto cur = stk.top();
      stk.pop();
      sorted.push_back(cur);
    }
    sort(sorted.begin(), sorted.end());
    string ret;
    for (auto s : sorted) {
      auto digit_part = s.substr(s.find(':') + 1);
      if (digit_part == "1") {
        ret += s.substr(0, s.find(':'));
      } else {
        ret += s;
      }
    }
    ret.erase(std::remove(ret.begin(), ret.end(), ':'), ret.end());

    return ret;
  }

public:
  string multiply(string &s, int n) {
    string ele = s.substr(0, s.find(':'));
    int count = stoi(s.substr(s.find(':') + 1));
    return ele + ":" + to_string(count * n);
  }
};
int main() {
  Solution so;
  // string input{"Kabc4(OxaNii(SO3)2)2"};
  string input{"(H2O(MKO3)30)10"};
  auto ret = so.countOfAtoms(input);
  cout << ret << endl;
}
