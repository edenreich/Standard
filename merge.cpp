#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main(int argc, char const *argv[])
{
    std::vector<int> collection1 { 1, 2, 3, 4, 5, 6 };
    std::vector<int> collection2 { 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> mergedCollection(collection1.size() + collection2.size());

    std::merge(std::begin(collection1), std::end(collection1), std::begin(collection2), std::end(collection2), std::begin(mergedCollection));

    std::cout << "After merge: " << '\n';
    
    for (auto const & el : mergedCollection)
    {
        std::cout << el << ' ';
    }
    
    // Output: 1 1 2 2 3 3 4 4 5 5 6 6 7

    return 0;
}
