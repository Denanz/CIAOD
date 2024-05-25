#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxIterative(const vector<int>& arr) {
    int maxElement = arr[0];
    for (int element : arr) {
        if (element > maxElement) {
            maxElement = element;
        }
    }
    return maxElement;
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    cout << "Maximum element (Iterative): " << findMaxIterative(arr) << endl;
    return 0;
}
