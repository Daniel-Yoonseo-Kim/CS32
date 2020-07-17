//  "Copyright [2020] <User>"

#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

bool checkPalindrome(string input);
bool checkEven(int input);

int main() {
  string test1 = "hello";
  string test2 = "abcba";
  string test3 = "banana";
  string test4 = "abccba";

  cout << checkPalindrome(test1) << endl;
  cout << checkPalindrome(test2) << endl;
  cout << checkPalindrome(test3) << endl;
  cout << checkPalindrome(test4) << endl;
}

// KTJ, _ is only for class's member variable, m_strXXXX.
// isXXX is obly for function name, not variable.
/*
bool checkPalindrome(string input) {
  bool bPalindrome = true;
  stack<char> aStack;
  int nStrLength = input.length();
  int nMidVal    = nStrLength / 2;
  int i = 0;

  while (i < nMidVal) {
    aStack.push(input[i]);
    i++;
  }
  if (!checkEven(nStrLength)) {
    i++;
  }

  while (bPalindrome && i < nStrLength) {
    if (!aStack.empty()) {
      char stackTop = aStack.top();
      if (stackTop == input[i]) {
        i++;
      } else {
        isPalindrome = false;
      }
      aStack.pop();
    } else {
      isPalindrome = false;
    }
  }

  if (!aStack.empty()) {
    bPalindrome = false;
  }

  return bPalindrome;
}
*/

bool checkPalindrome(string input) {
  stack<char> aStack;
  int  n_strLength = input.length();
  int  i           = 0;
  char ch;
  bool isPalindrome = true;
  int  n_midVal     = n_strLength / 2;

  while (i < n_midVal) {
    ch = input[i];
    aStack.push(ch);
    i++;
  }

  if (!checkEven(n_strLength)) {
    i++;
  }

  while (isPalindrome && i < n_strLength) {
    if (!aStack.empty()) {
      char stackTop = aStack.top();
      aStack.pop();
      ch = input[i];

      if (stackTop == ch) {
        i++;
      } else {
        isPalindrome = false;
      }
    } else {
      isPalindrome = false;
    }
  }

  if (isPalindrome && aStack.empty()) {
    return true;
  } else {
    return false;
  }
}

// KTJ
/*
bool checkEven(int input) {
  return (input % 2 == 0)? true: false;
}
*/

bool checkEven(int input) {
  if (input % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
