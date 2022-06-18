// https://leetcode.com/problems/design-a-text-editor/
#include "xxx.hpp"

class TextEditor {
public:
  TextEditor() {}

  void addText(string text) {
    left_.insert(left_.end(), text.begin(), text.end());
  }

  int deleteText(int k) {
    int dcnt = 0;
    while (k-- && left_.size()) {
      left_.pop_back();
      dcnt++;
    }

    return dcnt;
  }

  string cursorLeft(int k) {
    while (k-- && left_.size()) {
      right_.push_back(left_.back());
      left_.pop_back();
    }
    int sz = left_.size();
    return left_.substr(max(0, sz - 10));
  }

  string cursorRight(int k) {
    while (k-- && right_.size()) {
      left_.push_back(right_.back());
      right_.pop_back();
    }
    int sz = left_.size();

    return left_.substr(max(0, sz - 10));
  }

private:
  // left_ | right_
  //       ^
  //       |
  //     cursor
  string left_;
  string right_;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

// TextEditor is ttl version
// use list or deque is to complicate
class TextEditorTTL {
public:
  TextEditorTTL() : pos_(0), content_("") {}

  void addText(string text) {
    content_.insert(pos_, text);
    pos_ += text.size();
  }

  int deleteText(int k) {
    k = min(k, pos_);
    // int i = max(0, pos_ - k);
    string left_part{};
    string right_part{};
    if (content_.size() > pos_) {
      right_part = content_.substr(pos_);
    }
    if (pos_ > k) {
      left_part = content_.substr(0, pos_ - k);
    }

    content_ = left_part + right_part;

    // don't forget this
    pos_ = max(0, pos_ - k);
    return k;
  }

  string cursorLeft(int k) {
    int mv_step = min(pos_, k);
    pos_ -= k;
    if (pos_ < 0) {
      pos_ = 0;
    }
    // string ret;
    // for (int i = max(0, pos_ - 10); i < pos_; i++) {
    // ret.push_back(content_[i]);
    //}
    int i = max(0, pos_ - 10);
    return content_.substr(i, pos_ - i);
  }

  string cursorRight(int k) {
    int mv_step = min((int)content_.size() - pos_, k);
    pos_ += mv_step;
    if (pos_ > content_.size()) {
      pos_ = content_.size();
    }
    // string ret;
    // for (int i = max(0, pos_ - 10); i < pos_; i++) {
    // ret.push_back(content_[i]);
    //}
    int i = max(0, pos_ - 10);
    return content_.substr(i, pos_ - i);
  }

private:
  int pos_;
  string content_;
};

int main() {
  TextEditor vim;
  vim.addText("leetcode");
  int dcnt = vim.deleteText(4);
  vim.addText("practice");
  vim.cursorRight(3);
  vim.cursorLeft(8);
  vim.deleteText(10);
  vim.cursorLeft(2);
  vim.cursorRight(6);
}
