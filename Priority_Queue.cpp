#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main()
{
  std::priority_queue<int> myPriorityQueue;

  std::cout << "myPriorityQueue is empty? " << myPriorityQueue.empty() << std::endl;
  std::cout << "myPriorityQueue size is: " << myPriorityQueue.size() << std::endl;

  std::cout << "Pushing 3 integers into myPriorityQueue 3, 1 and 2" << std::endl;
  // Pushing the integers not in a particular order.
  myPriorityQueue.push(3);
  myPriorityQueue.push(1);
  myPriorityQueue.push(2);

  std::cout << "myPriorityQueue size is: " << myPriorityQueue.size() << std::endl;

  std::cout << "myPriorityQueue.top() output: " << myPriorityQueue.top() << std::endl;

  std::cout << "pop() integers from myPriorityQueue..." << std::endl;
  
  while ( !myPriorityQueue.empty() )
  {
    std::cout << "myPriorityQueue.top() output: " << myPriorityQueue.top() << std::endl;
    myPriorityQueue.pop();
  }// pop the integers in ascending order. Heighest integer goes out first.

  std::cout << "myPriorityQueue is empty? " << myPriorityQueue.empty() << std::endl;
  std::cout << "myPriorityQueue size is: " << myPriorityQueue.size() << std::endl;

  std::cout << "#########################################" << std::endl;

  std::priority_queue<
    std::string, 
    std::vector<std::string>,
    std::less<std::string> // std::greater will do the inverse order.
  > myPriorityQueue2;

  myPriorityQueue2.push("Test");
  myPriorityQueue2.push("Testtttt");
  myPriorityQueue2.push("Testtt");
  myPriorityQueue2.push("Testttt");
  myPriorityQueue2.push(".");

  while ( !myPriorityQueue2.empty() )
  {
    std::cout << "myPriorityQueue2.top() output: " << myPriorityQueue2.top() << std::endl;
    myPriorityQueue2.pop();
  }

  std::cout << "myPriorityQueue2 is empty? " << myPriorityQueue2.empty() << std::endl;
  std::cout << "myPriorityQueue2 size is: " << myPriorityQueue2.size() << std::endl;

  return 0;
}