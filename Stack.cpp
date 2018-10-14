#include <iostream>
#include <stack>

int main()
{
  // LIFO principle - Last In First Out
  std::stack<int> myStack;

  std::cout << "myStack is empty? " << myStack.empty() << std::endl;
  std::cout << "myStack size: " << myStack.size() << std::endl;
  
  std::cout << "Pushing 3 integers into the queue..." << std::endl;
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  std::cout << "myStack size: " << myStack.size() << std::endl;
  
  std::cout << "myStack.top() output: " << myStack.top() << std::endl;

  while ( !myStack.empty() )
  {
    std::cout << "myStack.top() output: " << myStack.top() << std::endl;
    myStack.pop();
  } 

  std::cout << "myStack is empty? " << myStack.empty() << std::endl;
  std::cout << "myStack size: " << myStack.size() << std::endl;
}
