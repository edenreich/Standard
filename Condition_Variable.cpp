#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex m;
std::condition_variable condVar;

bool dataReady = false;

void doTheWork()
{
  std::cout << "Proccessing shared data.." << std::endl;
}

// Function is scoped to thread t1
void waitingForWork()
{
  std::cout << "Worker: waiting for work...\n";
  std::unique_lock<std::mutex> lck(m);

  // At this point the thread will wait for the signal from t2
  condVar.wait(lck, []{return dataReady;});
  
  // Once signal recieved, thread can start the work.
  doTheWork();
  std::cout << "Work done." << std::endl;
}

// Function is scoped to thread t2
void setDataReady()
{
  std::lock_guard<std::mutex> lck(m);
  dataReady = true;
  std::cout << "Sender: Data is ready.\n";
  
  // Sends a signal to the other thread.
  condVar.notify_one();
}

int main()
{
  std::thread t1(waitingForWork);
  std::thread t2(setDataReady);

  t1.join();
  t2.join();

  return 0;
}