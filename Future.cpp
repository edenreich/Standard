#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
  // Instead of this...
  // (using shared variable between main thread and child thread).
  int res;

  std::cout << "Starting thread normally..." << std::endl;
  
  std::thread t([&] {
    
    std::cout << "Processing data...\n";

    // Processing some data for example timeout 5 seconds
    std::this_thread::sleep_for(5s);
    
    res = 2000+11; 
  });
  
  std::cout << "Doing some other work meanwhile..." << std::endl;

  t.join();
  
  std::cout << "The value of res is: " << res << std::endl;

  // ##########################################################

  // Could be also done using futures and promises.
  // (using a channel between sender (Promise) and the reciever (Future))
  std::cout << "Starting thread using async task..." << std::endl;
  
  auto future = std::async([] { 
    // Processing some data for example timeout 5 seconds
    std::cout << "Processing data...\n";
    std::this_thread::sleep_for(5s);

    return 2000+11; 
  });
  
  std::cout << "Doing some other work meanwhile..." << std::endl;
  
  std::cout << "Promise is resolved with: " << future.get() << std::endl;
  
  std::cout << "Continuing execution.." << std::endl;
  
  return 0;
}