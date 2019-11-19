#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<int> collection1 { 1, 2, 3, 4, 5, 6 };
    std::vector<int> collection2 { 1, 2, 4, 3, 5, 6, 7 };
    std::vector<int> intersectedCollection;

    std::sort(std::begin(collection1), std::end(collection1));
    std::sort(std::begin(collection2), std::end(collection2));

    std::set_intersection(std::begin(collection1), std::end(collection1), std::begin(collection2), std::end(collection2), std::back_inserter(intersectedCollection));

    std::cout << "After merge: " << '\n';
    
    for (auto const & el : intersectedCollection)
    {
        std::cout << el << ' ';
    }
    
    // Output: 1 2 3 4 5 6

    return 0;
}
