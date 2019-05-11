// http://leetcode.com/problems/parse-lisp-expression/description/
#include "xxx.h"

class Solution {
private:
  struct scope {
    scope *outer_;
    unordered_map<string, int> vars_;
  };

public:
  static const int kLet = 1;
  static const int kMult = 2;
  static const int kAdd = 3;
  int evaluate(string expression) {
    global_scope_.outer_ = nullptr;

    return withScope(expression, global_scope_);
  }
  int withScope(string &s, scope &outer) {
    scope cur_scope{&outer, unordered_map<string, int>{}};
    const int n = s.size();
    bool func_parsed = false;

    // 标记括号位置
    unordered_map<int, int> parens;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
        continue;
      }
      if (s[i] == ')') {
        auto match = stk.top();
        stk.pop();
        parens[match] = i;
      }
    }

    int ret = 0;
    int exp_type = 0;
    int i = 0;
    int let_last_exp_idx = -1;
    int exp_end_idx = -1;
    while (i < n) {
      int j = i;
      // now j stop at ' '
      while (j < n && s[j] != ' ') {
        j++;
      }
      string tmp = s.substr(i, j - i);
      cout << "parse section: " << tmp << endl;
      // 处理第一个位置上的行为
      if (!func_parsed) {
        func_parsed = true;
        exp_end_idx = parens[i];
        if (tmp == "(let") {
          // process binding
          exp_type = Solution::kLet;
          // 此时需要找到最后一个expression的开始位置
          // 第一个变量名的第一个字符上
          int end = parens[i];
          for (int k = j + 1; k < end;) {
            if (s[k] == '(') {
              // 忽略内嵌的任何expression
              k = parens[k] + 1;
              continue;
            }
            if (s[k] == ' ') {
              let_last_exp_idx = k + 1;
            }
            k++;
          }
          cout << "oh last express is:" << let_last_exp_idx << endl;
        } else if (tmp == "(mult") {
          // process multiply
          ret = 1;
          exp_type = Solution::kMult;
        } else if (tmp == "(add") {
          // process add
          exp_type = Solution::kAdd;
        }
        i = j + 1;
      } else {
        // 根据exp_type来走咯
        // 两个两个的取
        // there are 1 or more pairs of alternating variables and expressions
        // 至少有一对
        // 此时i停留在第一个变量的第一个字符上
        if (exp_type == Solution::kLet) {
          // ignore the space before last exp in let
          int end = let_last_exp_idx - 1;
          while (i < end) {
            // 取变量名
            int j = i;
            while (j < end && s[j] != ' ') {
              j++;
            }
            string var = s.substr(i, j - i);
            cout << var << endl;

            // pass over space between var and value
            j++;
            int k = j;

            while (j < end && s[j] != ' ') {
              j++;
            }
            string value = s.substr(k, j - k);
            cout << value << endl;
            if (value[0] == '(') {
              string sub_exp = s.substr(k, parens[k] - k + 1);
              cur_scope.vars_[var] = withScope(sub_exp, cur_scope);
            } else {
              cur_scope.vars_[var] = stoi(value);
            }

            i = j + 1;
          }
          // 处理完变量，就进行最后的执行了
          i = let_last_exp_idx;
          if (s[i] == '(') {
            string sub_exp = s.substr(i, parens[i] - i + 1);
            return withScope(sub_exp, cur_scope);
          } else {
            string last_exp = s.substr(i, exp_end_idx - i);
            if (s[i] == '-' || isdigit(s[i])) {
              return stoi(last_exp);
            }
            return closureFind(last_exp, cur_scope);
          }
        } else if (exp_type == Solution::kAdd) {
          int end = exp_end_idx;
          while (i < end) {
            int j = i;
            while (j < end && s[j] != ' ') {
              j++;
            }
            string cur_exp = s.substr(i, j - i);
            // cout << "(Add " << cur_exp << endl;
            if (cur_exp[0] == '(') {
              string sub_exp = s.substr(i, parens[i] - i + 1);
              ret += withScope(sub_exp, cur_scope);
            } else if (cur_exp[0] == '-' || isdigit(cur_exp[0])) {
              ret += stoi(cur_exp);
            } else {
              ret += closureFind(cur_exp, cur_scope);
            }

            i = j + 1;
          }
          i = exp_end_idx + 1;
        } else if (exp_type == Solution::kMult) {
        }
      } // parse 非首个function
    }   // 最外层
    return ret;
  }

private:
  int closureFind(string &key, scope &scope) {
    if (scope.vars_.find(key) != scope.vars_.end()) {
      return scope.vars_[key];
    }
    if (scope.outer_ == nullptr) {
      return -1;
    }

    return closureFind(key, *scope.outer_);
  }

private:
  scope global_scope_;
};

int main() {
  Solution so;
  // string input{"(let x 2 (add (let x 3 (let x 4 x)) x))"};
  string input{"(let x 2 (add 10 x))"};
  auto ret = so.evaluate(input);
  cout << "----" << endl;
  cout << ret << endl;
}
