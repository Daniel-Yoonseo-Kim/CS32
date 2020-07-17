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
        bPalindrome = false;
      }
      aStack.pop();
    } else {
      bPalindrome = false;
    }
  }

  if (!aStack.empty()) {
    bPalindrome = false;
  }

  return bPalindrome;
}

bool checkEven(int input) {
  return (input % 2 == 0)? true: false;
}
