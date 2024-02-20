#include <iostream>
using namespace std;

int merge(int arr[], int l, int m, int r) {
    int comparisons = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
        comparisons++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }

    return comparisons;
}

long long mergeSort(int arr[], int l, int r) {
    long long comparisons = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        comparisons += mergeSort(arr, l, m);
        comparisons += mergeSort(arr, m + 1, r);
        comparisons += merge(arr, l, m, r);
    }
    return comparisons;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long comparisons = mergeSort(arr, 0, n - 1);

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}


// --------insertion sort


#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i =i - 1;
        }
        arr[i + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}