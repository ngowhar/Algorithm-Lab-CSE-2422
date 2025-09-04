#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i<n; i++) {cout<<arr[i] <<" ";}
    cout<<endl;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binSearch(arr, n, key);
    if (result != -1) cout << "Element found at index " << result << endl;
    else cout << "Element not found" << endl;

    return 0;
}


