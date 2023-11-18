#include "Stack.h"
using namespace std;
int main() {
  string expression;
  cout << "Enter a math expression with no spaces: ";
  cin >> expression;
  isBalanced(expression);
  if(isBalanced(expression)){
    cout << "\nYour expression in postfix: ";
    cout << infixToPostfix(expression);
  }
}
