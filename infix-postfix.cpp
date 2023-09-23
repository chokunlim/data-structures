#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
      if (c == '^') {
         return 3;
      } else if (c == '/' || c == '*') {
         return 2;
      } else if (c == '+' || c == '-') {
         return 1;
      } else {
         return 0;
      }
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int main() 
{

      stack<char> operatorStack;
      string postFix = "";

      string s;
      cin >> s;

      for (char c : s) {
         if (isOperand(c)) {
            postFix += c;
         } else if (c == '(') {
            operatorStack.push(c);
         } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postFix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); 
        } else {
         if (operatorStack.empty()) {
               operatorStack.push(c);
            } else {
               while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top())) {
                  postFix += operatorStack.top();
                  operatorStack.pop();
               }
               operatorStack.push(c);
            }
         }
      }
       
      while (!operatorStack.empty()) {
         postFix += operatorStack.top();
         operatorStack.pop();
      }

      cout << postFix << endl;
    
      return 0;
}
