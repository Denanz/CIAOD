#include <iostream>
#include <vector>
#include <algorithm>

int findMaxIterative(const std::vector<int>& arr) {
    int maxElement = arr[0];
    for (int element : arr) {
        if (element > maxElement) {
            maxElement = element;
        }
    }
    return maxElement;
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    std::cout << "Maximum element (Iterative): " << findMaxIterative(arr) << std::endl;
    return 0;
}
