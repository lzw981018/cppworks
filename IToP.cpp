/* 中缀表达式转后缀表达式 */
/* 并计算 */
#include "stack.h"
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string infixToPostfix(const string &);


int main() {
  cout << "请输入中缀表达式:";
  string iString;
  cin >> iString;
  string pString = infixToPostfix(iString);
  cout << pString;
  return 0;
}

string infixToPostfix(const string & iString) {
  stack token;
  string result;
  char i;
  for (string::size_type tmp = 0; tmp != iString.size(); tmp++) {
    i = iString[tmp];
    if (isalnum(i)) {
      result += i;
    } else if (i == '(' || token.empty() || token.top() == '(') {
      token.push(i);
    } else if (i == ')') {
      char out;
      while ((out = token.pop()) != '(')
        result += out;
    } else if (i == '+' || i == '-') {
      while (token.top() != '(' && !token.empty())
        result += token.pop();
      token.push(i);
    } else if (i == '*' || i == '/') {
      while ((token.top() == '*' || token.top() == '/') && !token.empty()) {
        result += token.pop();
      }
      token.push(i);
    }
    if (tmp == iString.size() - 1) {
      while (!token.empty())
        result += token.pop();
    }
  }

  return result;
}