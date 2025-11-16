#include <iostream>
using namespace std;

void selectionSort(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (finish[j] < finish[minIndex])
                minIndex = j;
        }

        int temp = finish[minIndex];
        finish[minIndex] = finish[i];
        finish[i] = temp;

        temp = start[minIndex];
        start[minIndex] = start[i];
        start[i] = temp;
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[n], finish[n];

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << "Enter finish times: ";
    for (int i = 0; i < n; i++) cin >> finish[i];

    selectionSort(start, finish, n);

    cout << "\nActivities after sorting by finish time:\n";
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i
             << " -> Start: " << start[i]
             << ", Finish: " << finish[i] << endl;
    }

    cout << "\nSelected Activities:\n";
    int count = 1;
    cout << "Activity 0 (Start: " << start[0] << ", Finish: " << finish[0] << ")" << endl;

    int lastFinish = finish[0];

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "Activity " << i << " (Start: " << start[i] << ", Finish: " << finish[i] << ")" << endl;
            count++;
            lastFinish = finish[i];
        }
    }

    cout << "\nTotal activities selected: " << count << endl;

    return 0;
}
