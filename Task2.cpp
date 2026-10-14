#include <iostream>
#include <vector>

using namespace std;

// inputSortedIDs Function
void inputSortedIDs(vector<int>& arr, int n) {
    cout << "Enter " << n << " sorted student IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Check for Sorting
bool isSorted(const vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// BinarySearch
int binarySearch(const vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        //Mid value calculation
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1;
}

int main() {
    int n, target;
    cout << " Binary Search\n";
    cout << "Enter total number of registered IDs: ";
    cin >> n;

    // For Empty array
    if (n <= 0) {
        cout << "Result: Not found\n";
        return 0;
    }

    vector<int> arr(n);
    inputSortedIDs(arr, n);

    if (!isSorted(arr, n)) {
        cout << "Error: Input array is not sorted! Binary search requires sorted data.\n";
        return 0;
    }

    cout << "Enter target ID to search: ";
    cin >> target;

    int index = binarySearch(arr, 0, n - 1, target);
    
    if (index != -1) {
        cout << "Result: Found at index " << index << "\n";
    } else {
        cout << "Result: Not found\n";
    }

    return 0;
}