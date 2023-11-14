#include "Queue.h"

int main() {
  Queue Line;
  Line.push("Kona");
  cout << Line.front() << endl;
  Line.push("Jeff");
  if(Line.empty() == 0){
    cout << "False" << endl;
  }
  else
    cout << "True" << endl;
  cout << Line.size() << endl;
  cout << Line.pop() << endl;
  cout << Line.front() << endl;
  
}