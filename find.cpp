#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> collection{ 1, 5, 3, 7, 8, 3, 8 };

    // Linear lookup on an unsorted collection from left to right.
    std::vector<int>::iterator it = std::find(std::begin(collection), std::end(collection), 7);

    std::cout << "Found the value in the collection using find: " << *it << '\n';

    // Linear lookup on an unsorted collection for a begin of a subset in a collection from the end to the begining, in a reverse pattern
    std::vector<int> subset{ 3, 8 };
    std::vector<int>::iterator it2 = std::find_end(std::begin(collection), std::end(collection), std::begin(subset), std::end(subset));  

    std::cout << "Found the value in the collection using find_end: " << *it2 << '\n';

    return 0;
}
