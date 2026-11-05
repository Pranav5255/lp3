#include <bits/stdc++.h>
using namespace std;

int calls = 0;

// Recursive: Time O(2^n), Space O(n) (recursion stack)
int fibRecursive(int n) {
    calls++;
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative: Time O(n), Space O(1)
int fibIterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive: " << fibRecursive(n) << " (function calls = " << calls << ")\n";
    cout << "Iterative: " << fibIterative(n) << "\n";
}
