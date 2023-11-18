#include "Stack.h"
using namespace std;
int main() {
  string expression;
  cout << "Enter a math expression: ";
  cin >> expression;
  isBalanced(expression);
  if(isBalanced(expression)){
    cout << "\nYour expression in postfix: ";
    cout << infixToPostfix(expression);
  }
}
