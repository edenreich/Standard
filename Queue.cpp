#include <iostream>
#include <queue>

int main()
{
  // FIFO principle - First In First Out
  std::queue<int> myQueue;

  std::cout << "myQueue is empty? " << myQueue.empty() << std::endl;
  std::cout << "myQueue size: " << myQueue.size() << std::endl;
  
  std::cout << "Pushing 3 integers into the queue..." << std::endl;
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  std::cout << "myQueue size: " << myQueue.size() << std::endl;
  
  std::cout << "myQueue.back() output: " << myQueue.back() << std::endl;
  std::cout << "myQueue.front() output: " << myQueue.front() << std::endl;

  while ( !myQueue.empty() )
  {
    std::cout << "myQueue.back() output: " << myQueue.back() << std::endl;
    std::cout << "myQueue.front() output: " << myQueue.front() << std::endl;
    myQueue.pop();
  } 

  std::cout << "myQueue is empty? " << myQueue.empty() << std::endl;
  std::cout << "myQueue size: " << myQueue.size() << std::endl;
}
