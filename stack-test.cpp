#include <iostream>
#include "stack.h"

int main(){

  Stack<int> tester;
  // adding random numbers to stack
  tester.push(2);
  tester.push(4);
  tester.push(6);
  tester.push(9);
  tester.push(11);
  tester.push(0);

  // will go until all of the stack is empty 
  std::cout << "Size of stack: " << tester.size() << std::endl;
  std::cout << tester.top() << std::endl;
  tester.pop();
  std::cout << tester.top() << std::endl;
  tester.pop();
  std::cout << tester.top() << std::endl;
  tester.pop();
  std::cout << tester.top() << std::endl;
  tester.pop();
  std::cout << tester.top() << std::endl;
  tester.pop();
  std::cout << tester.top() << std::endl;
  tester.pop();
   // stack should be empty now
  return 0;
}