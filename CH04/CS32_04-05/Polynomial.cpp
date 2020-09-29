// "Copyright (2020) <User>"

#include <iostream>
#include "Polynomial.h"

using std::cout;
using std::endl;

Polynomial::Polynomial() : m_pHeadPtr(nullptr), m_nMonomialCount(0) {
}

Polynomial::Polynomial(const Polynomial& aPoly) {
  m_nMonomialCount   = aPoly.m_nMonomialCount;
  Node* origChainPtr = aPoly.m_pHeadPtr;

  if (origChainPtr == nullptr) {
    m_pHeadPtr = nullptr;
  } else {
    m_pHeadPtr = new Node();
    m_pHeadPtr->setVal(origChainPtr->getCoeff(), origChainPtr->getPower());

    Node* newChainPtr = m_pHeadPtr;
    while (origChainPtr->getNext() != nullptr) {
      origChainPtr  = origChainPtr->getNext();
      int nextCoeff = origChainPtr->getCoeff();
      int nextPower = origChainPtr->getPower();
      Node* newNodePtr = new Node(nextCoeff, nextPower);
      newChainPtr->setNext(newNodePtr);
      newChainPtr = newChainPtr->getNext();
    }

    newChainPtr->setNext(nullptr);
  }
}

Polynomial::~Polynomial() {
  clear();
}

Node* Polynomial::getPointerTo(const int targetPower) const {
  bool  found  = false;
  Node* curPtr = m_pHeadPtr;

  while (!found && (curPtr != nullptr)) {
    if (targetPower == curPtr->getPower()) {
      found = true;
    } else {
      curPtr = curPtr->getNext();
    }
  }

  if (!found) {
    return nullptr;
  } else {
    return curPtr;
  }
}

bool Polynomial::contain(const int power) const {
  return (getPointerTo(power) != nullptr);
}

bool Polynomial::addTerm(const int newCoeff, const int newPower) {
  Node* curPtr  = m_pHeadPtr;
  int   counter = 0;

  while (curPtr != nullptr && counter < m_nMonomialCount) {
    if (newPower == curPtr->getPower()) {
      return false;
    }

    counter++;
    curPtr = curPtr->getNext();
  }

  Node* newNodePtr = new Node();
  newNodePtr->setVal(newCoeff, newPower);
  newNodePtr->setNext(m_pHeadPtr);
  m_pHeadPtr = newNodePtr;
  m_nMonomialCount++;

  return true;
}

Polynomial operator+(const Polynomial left, const Polynomial right) {
  Polynomial sum = Polynomial();
  Node* leftCurPtr   = left.m_pHeadPtr;
  Node* rightCurPtr  = right.m_pHeadPtr;
  int   leftCounter  = 0;
  int   rightCounter = 0;

  while (leftCurPtr != nullptr && leftCounter < left.m_nMonomialCount) {
    Node* newNodePtr = new Node();
    int   sumCoeff;

    if (right.contain(leftCurPtr->getPower())) {
      sumCoeff = leftCurPtr->getCoeff() +
                 (right.getPointerTo(leftCurPtr->getPower())->getCoeff());
    } else {
      sumCoeff = leftCurPtr->getCoeff();
    }

    newNodePtr->setVal(sumCoeff, leftCurPtr->getPower());
    newNodePtr->setNext(sum.m_pHeadPtr);
    sum.m_pHeadPtr = newNodePtr;
    sum.m_nMonomialCount++;

    leftCounter++;
    leftCurPtr = leftCurPtr->getNext();
  }

  while (rightCurPtr != nullptr && rightCounter < right.m_nMonomialCount) {
    if (!(left.contain(rightCurPtr->getPower()))) {
      Node* newNodePtr = new Node();

      newNodePtr->setVal(rightCurPtr->getCoeff(), rightCurPtr->getPower());
      newNodePtr->setNext(sum.m_pHeadPtr);
      sum.m_pHeadPtr = newNodePtr;
      sum.m_nMonomialCount++;
    }
    rightCounter++;
    rightCurPtr = rightCurPtr->getNext();
  }

  return sum;
}

void Polynomial::printPolynomial() const {
  Node* curPtr  = m_pHeadPtr;
  int   counter = 0;

  while (curPtr != nullptr && counter < m_nMonomialCount) {
    cout << curPtr->getCoeff() << "x^" << curPtr->getPower() << " ";

    counter++;
    curPtr = curPtr->getNext();
  }

  cout << endl << "End of Polynomial." << endl;
}

void Polynomial::clear() {
  while (m_pHeadPtr != nullptr) {
    Node* nodeToDeletePtr = m_pHeadPtr;
    m_pHeadPtr = m_pHeadPtr->getNext();

    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
  }

  m_nMonomialCount = 0;
}
