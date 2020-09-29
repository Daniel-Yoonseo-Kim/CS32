// "Copyright (2020) <User>"

#ifndef _NODE
#define _NODE

class Node {
 private:
  int   m_nCoefficient;
  int   m_nPower;
  Node* m_pNext;

 public:
  Node();
  Node(const int coeff, const int power);
  Node(const int coeff, const int power, Node* nextNodePtr);
  void  setVal(const int coeff, const int power);
  void  setNext(Node* nextNodePtr);
  int   getCoeff() const;
  int   getPower() const;
  Node* getNext() const;
};

#endif  // _NODE
