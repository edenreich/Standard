#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
 
int main()
{
    std::vector<int> collection{ 3, 2, 4, 1, 5, 9 };
 
    std::cout << "collection: ";
    for (auto const & el : collection) 
    {
        std::cout << el << ' ';
    }
    std::cout << '\n';
 
    // Sort the element in a way that the higher size comes first
    std::make_heap(collection.begin(), collection.end());
 
    std::cout << "Collection after make_heap: ";
    for (auto const & el : collection) 
    {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    // Displaying the maximum element of the heap 
    std::cout << "The maximum element of heap is: "; 
    std::cout << collection.front() << std::endl;

    std::pop_heap(collection.begin(), collection.end());
 
    // Bring the highest size of the collection to the end
    std::cout << "Collection after pop_heap: ";
    for (auto const & el : collection)
    {
        std::cout << el << ' ';
    }
    std::cout << '\n';

}