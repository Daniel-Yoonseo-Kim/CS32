// "Copyright (2020) <User>"

#include "Node.h"

Node::Node() : m_nCoefficient(0), m_nPower(0), m_pNext(nullptr) {
}

Node::Node(const int coeff, const int power) :
      m_nCoefficient(coeff), m_nPower(power), m_pNext(nullptr) {
}

Node::Node(const int coeff, const int power, Node* nextNodePtr) :
      m_nCoefficient(coeff), m_nPower(power), m_pNext(nextNodePtr) {
}

void Node::setVal(const int coeff, const int power) {
  m_nCoefficient = coeff;
  m_nPower       = power;
}

void Node::setNext(Node* nextNodePtr) {
  m_pNext = nextNodePtr;
}

int Node::getCoeff() const {
  return m_nCoefficient;
}

int Node::getPower() const {
  return m_nPower;
}

Node* Node::getNext() const {
  return m_pNext;
}
