#include <iostream>
#include <vector>

int findMaxRecursive(const std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }
    int mid = (left + right) / 2;
    int maxLeft = findMaxRecursive(arr, left, mid);
    int maxRight = findMaxRecursive(arr, mid + 1, right);
    return std::max(maxLeft, maxRight);
}

int findMax(const std::vector<int>& arr) {
    return findMaxRecursive(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    std::cout << "Maximum element (Recursive): " << findMax(arr) << std::endl;
    return 0;
}
