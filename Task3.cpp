#include <iostream>
#include <vector>

using namespace std;
//DisplayArray Function
void displayArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    cout << "]\n";
}
//Merge sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    // Empty Array or Single array
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//Main Function
int main() {
    int n;
    cout << " Merge Sort\n";
    cout << "Enter number of student marks: ";
    cin >> n;

    vector<int> marks(n);
    if (n > 0) {
        cout << "Enter marks: ";
        for (int i = 0; i < n; i++) cin >> marks[i];
    }

    cout << "Original Array: ";
    displayArray(marks);
    mergeSort(marks, 0, n - 1);

    cout << "Sorted Array:   ";
    displayArray(marks);

    return 0;
}