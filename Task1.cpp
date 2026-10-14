#include <iostream>
#include <vector>

using namespace std;

// Reads student Ids into the array
void inputIDs(vector<int>& arr, int n) {
    cout << "Enter " << n << " student IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Returns the index of the first occurrence of target 
int linearSearch(const vector<int>& arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return immediately when target is found
        }
    }
    return -1; // Target not present
}

// Displays the result
void displayResult(int index) {
    if (index != -1) {
        cout << "Result: Found at index " << index << "\n";
    } else {
        cout << "Result: ID is not registered (Not found)\n";
    }
}

int main() {
    int n, target;
    cout << " Linear Search\n";
    cout << "Enter total number of student IDs: ";
    cin >> n;

    // Handle empty array case
    if (n <= 0) {
        displayResult(-1);
        return 0;
    }

    vector<int> arr(n);
    inputIDs(arr, n);

    cout << "Enter target ID to search: ";
    cin >> target;

    int index = linearSearch(arr, n, target);
    displayResult(index);

    return 0;
}