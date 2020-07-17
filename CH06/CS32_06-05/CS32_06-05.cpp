// "Copyright [2020] <User>"

#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

int calcPostfix(string input);

int main() {
  string test1 = "234+*";
  string test2 = "243-*";
  string test3 = "253-/";

  cout << calcPostfix(test1) << endl;
  cout << calcPostfix(test2) << endl;
  cout << calcPostfix(test3) << endl;
}

int calcPostfix(string input) {
  stack<int> aStack;
  char ch;
  int  result;

  for (int i = 0; i < input.length(); i++) {
    ch = input[i];

    if (isdigit(ch)) {
      result = ch - '0';
    } else {
      int operand2 = aStack.top();
      aStack.pop();

      int operand1 = aStack.top();
      aStack.pop();

      switch (ch) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          result = operand1 / operand2;
          break;
      }
    }

    aStack.push(result);
  }

  return result;
}
