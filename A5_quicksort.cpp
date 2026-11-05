#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;

// Lomuto partition: last element is the pivot
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic: always uses last element as pivot
void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized: pick random pivot, move it to the end, then partition
void randomizedQuickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int r = low + rand() % (high - low + 1);
        swap(a[r], a[high]);
        int p = partition(a, low, high);
        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

void print(vector<int> &a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int &x : arr) cin >> x;

    vector<int> a = arr;
    comparisons = 0;
    quickSort(a, 0, n - 1);
    cout << "Deterministic: "; print(a);
    cout << "Comparisons: " << comparisons << "\n\n";

    vector<int> b = arr;
    comparisons = 0;
    randomizedQuickSort(b, 0, n - 1);
    cout << "Randomized: "; print(b);
    cout << "Comparisons: " << comparisons << "\n";
}
/*
Deterministic: Best/Avg O(n log n), Worst O(n^2) (already sorted input)
Randomized:    Expected O(n log n) for any input; worst case O(n^2) is very unlikely
Space: O(log n) recursion stack on average
*/
