// http://leetcode.com/problems/mini-parser/description/
#include "simpleone.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution {
public:
  NestedInteger deserialize(string s) {
    if (s.find_first_of('[', 0) == string::npos) {
      return NestedInteger(stoi(s));
    }
    int pos = 1;
    return recur(pos, s);
  }

private:
  // hold the parent to modify it
  NestedInteger recur(int &pos, string &s) {
    NestedInteger ret;
    string d{""};
    for (; pos < s.size(); pos++) {
      const char cur = s[pos];
      if (cur == '[') {
        NestedInteger tmp = recur(++pos, s);
        ret.add(tmp);
      } else if (cur == ']') {
        if (!d.empty()) {
          ret.add(stoi(d));
        }
        d = "";
        return ret;
      } else if (cur == '-' || isdigit(cur)) {
        d.push_back(cur);
      } else if (cur == ',') {
        if (!d.empty()) {
          ret.add(stoi(d));
        }
        d = "";
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.deserialize("324");
}
