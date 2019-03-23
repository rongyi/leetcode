// http://leetcode.com/problems/quad-tree-intersection/description/

// Definition for a QuadTree node.
class Node {
public:
  // 不是leaf的val没有什么卵用
  bool val;

  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *intersect(Node *q1, Node *q2) {
    if (q1->isLeaf) {
      return q1->val ? q1 : q2;
    }
    if (q2->isLeaf) {
      return q2->val ? q2 : q1;
    }
    auto tl = intersect(q1->topLeft, q2->topLeft);
    auto tr = intersect(q1->topRight, q2->topRight);
    auto bl = intersect(q1->bottomLeft, q2->bottomLeft);
    auto br = intersect(q1->bottomRight, q2->bottomRight);
    auto val = tl->val;
    if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
        val == tr->val && val == bl->val && val == br->val) {
      delete tl;
      delete tr;
      delete bl;
      delete br;
      return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
    }
    return new Node(true /*true or false doesn't matter, so false is ok*/,
                    false, tl, tr, bl, br);
  }
};
