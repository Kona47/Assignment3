#include "Queue.h"

void Queue::push(string data){
  Node* newNode = new Node(data);
  if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    tail->next = newNode;
    tail = newNode;
  }
  num_items++; 
}

string Queue::pop(){
  if(head == NULL){
    return "Queue Empty\n";
  }
  else{
    string temp = head->data;
    head = head->next;
    num_items--;
    return temp;
  }
}

string Queue::front(){
  return head->data;
}

bool Queue::empty(){
  if(num_items == 0)
    return true;
  return false;
}
