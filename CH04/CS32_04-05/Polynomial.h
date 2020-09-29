// "Copyright (2020) <User>"

#ifndef _POLYNOMIAL
#define _POLYNOMIAL

#include "Node.h"

class Polynomial {
 public:
  Polynomial();
  Polynomial(const Polynomial& aPoly);
  virtual ~Polynomial();
  bool    addTerm(const int newCoeff, const int newPower);
  friend Polynomial operator+(const Polynomial left, const Polynomial right);
  void    printPolynomial() const;

 private:
  Node* m_pHeadPtr;
  int   m_nMonomialCount;
  Node* getPointerTo(const int targetPower) const;
  bool  contain(const int power) const;
  void  clear();
};

#endif  // _POLYNOMIAL
