// https://leetcode.com/problems/encrypt-and-decrypt-strings/
#include "xxx.hpp"

class Encrypter {
public:
  Encrypter(vector<char> &keys, vector<string> &values,
            vector<string> &dictionary) {
    for (int i = 0; i < keys.size(); ++i) {
      expand_[keys[i]] = values[i];
    }
    for (auto &d : dictionary) {
      ++enigma_count_[encrypt(d)];
    }
  }

  string encrypt(string word1) {
    string ret;
    for (auto c : word1) {
      // this is for dictionary, word in dictionary may not in expand_
      if (expand_.find(c) == expand_.end()) {
        return "";
      }
      ret += expand_[c];
    }
    return ret;
  }

  int decrypt(string word2) { return enigma_count_[word2]; }

private:
  map<char, string> expand_;
  map<string, int> enigma_count_;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
