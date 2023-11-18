#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOpen(char ch);
bool isClosed(char ch);
bool isBalanced(string expression);
int getPrecedence(char op);
string infixToPostfix(const string& infix);