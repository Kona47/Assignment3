#include "Stack.h"
using namespace std;

const string OPEN = "({[";
const string CLOSE = ")}]";
//finds if char is an open parenthesis
bool isOpen(char ch){
  return OPEN.find(ch)!= string::npos; 
}
// finds if char is a closed parenthesis
bool isClosed(char ch){
  return CLOSE.find(ch)!= string::npos; 
}
//Function to return true/false if the expression is balanced
bool isBalanced(string expression){
  stack<char> parenthesis;
  bool balanced = true;
  string::const_iterator iter = expression.begin();
  //iterate through expression till the end or till not balanced
  while(balanced && (iter != expression.end())){
    char ch = *iter;
    //if open parenthesis, push to stack
    if(isOpen(ch))
      parenthesis.push(ch);
    //if closed, check stack for matching parenthesis
    else if(isClosed(ch)){
      if(parenthesis.empty())
        balanced = false;
      else{
        char top = parenthesis.top();
        parenthesis.pop();
        balanced = OPEN.find(top) == CLOSE.find(ch);
      }
    }
    iter++;
  }
  //Tell user it is invalid if the parenthesis arent balance
  if(!balanced || !parenthesis.empty()){
    cout << "\nThe expression is Invalid.\n";
  }
  return balanced && parenthesis.empty();
}
//Used in the infix to postix function to create precedence for order of ops.
int getPrecedence(char op){
    if (op == '*' || op == '/' || op == '%') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}
//Function to convert infix to postfix
string infixToPostfix(const string& infix) {
  stack<char> operatorStack;
  string postfix;
  // Iterate through the infix expression
  for (char ch : infix) {
      // If the character is an operand, add it to the postfix string
      if (isalnum(ch)) {
        postfix += ch;
      } 
      // If the character is an operator, pop operators from the stack and add them to the postfix string
      else if (isOpen(ch)) {
        operatorStack.push(ch);
      } 
      // If the character is a closed parenthesis, pop operators from the stack and add them to the postfix string
      else if (isClosed(ch)) {
        while (!operatorStack.empty() && !isOpen(operatorStack.top())) {
          postfix += operatorStack.top();
          operatorStack.pop();
            }
            operatorStack.pop();
      } 
      // If the character is an operator, pop operators from the stack and add them to the postfix string
      else{
        while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(ch)) {
          postfix += operatorStack.top();
          operatorStack.pop();
        }
        operatorStack.push(ch);
        }
    }
    // Pop remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
  return postfix;
}