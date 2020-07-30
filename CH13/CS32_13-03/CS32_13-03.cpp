// "Copyright [2020] <User>"

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;

bool isPalindrome(string inputStr);
void printResult(string isPalindrome);

int main() {
  string test1 = "Hello";
  string test2 = "abcba";

  printResult(test1);
  printResult(test2);
}

bool isPalindrome(string inputStr) {
  queue<char> aQueue;
  stack<char> aStack;
  int length = inputStr.length();

  for (int i = 0; i < length; i++) {
    char nextChar = inputStr[i];
    aQueue.push(nextChar);
    aStack.push(nextChar);
  }

  bool charactersEqual = true;
  while (!aQueue.empty() && charactersEqual) {
    char queueFront = aQueue.front();
    char stackTop   = aStack.top();

    if (queueFront == stackTop) {
      aQueue.pop();
      aStack.pop();
    } else {
      charactersEqual = false;
    }
  }

  return charactersEqual;
}

void printResult(string inputStr) {
  if (isPalindrome(inputStr)) {
    cout << inputStr << " is a palindrome." << endl;
  } else {
    cout << inputStr << " is not a palindrome." << endl;
  }
}
