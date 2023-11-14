#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Node {
  Node(string data, Node* next_ptr = NULL) : data(data), next(next_ptr){}
  string data;
  Node* next;
};

class Queue{

private:
  int num_items;
  Node* head;
  Node* tail;

public:
  Queue(){head = NULL; tail = NULL; num_items = 0;}
  void push(string data);
  string pop();
  string front();
  bool empty();
  int size(){return num_items;}
};