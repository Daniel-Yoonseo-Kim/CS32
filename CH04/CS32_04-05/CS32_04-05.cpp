// "Copyright (2020) <User>"

#include "Node.h"
#include "Polynomial.h"

int main() {
  Polynomial p1;
  Polynomial p2;

  p1.addTerm(1, 1);
  p1.addTerm(2, 2);
  p1.addTerm(3, 3);
  p1.addTerm(4, 4);

  p2.addTerm(3, 1);
  p2.addTerm(4, 2);
  p2.addTerm(5, 3);
  p2.addTerm(7, 5);

  p1.printPolynomial();
  p2.printPolynomial();

  Polynomial p3 = (p1 + p2);
  p3.printPolynomial();

  return 0;
}
