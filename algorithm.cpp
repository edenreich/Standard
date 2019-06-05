#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

template <typename T>
class Iterator {
public:
  void operator()(T t)
  {
    num++;
    sum += t;
  }

  int getSum() const
  {
    return sum;
  }

  int getSize() const
  {
    return num;
  }

  double getMean() const
  {
    return static_cast<double>(sum) / static_cast<double>(num);
  }

private:
  T sum { 0 };
  int num { 0 };
};

int main()
{
  std::vector<double> myVec { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
  auto vecInfo = std::for_each(myVec.begin(), myVec.end(), Iterator<double>());

  std::cout << vecInfo.getSum() << std::endl; // 49
  std::cout << vecInfo.getSize() << std::endl; // 9
  std::cout << vecInfo.getMean() << std::endl; // 5.5

  std::array<int, 100> myArr { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  auto arrInfo = std::for_each(myArr.begin(), myArr.end(), Iterator<int>());

  std::cout << arrInfo.getSum() << std::endl; // 55
  std::cout << arrInfo.getSize() << std::endl; // 100
  std::cout << arrInfo.getMean() << std::endl; // 0.55

  return 0;
}