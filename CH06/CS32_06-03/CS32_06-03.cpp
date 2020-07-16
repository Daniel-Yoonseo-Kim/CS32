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

bool checkEven(int input) {
  if (input % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
