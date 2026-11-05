#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;

    vector<int> wt(n), val(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    // dp[i][w] = best value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];                                   // don't take item i
            if (wt[i - 1] <= w)                                        // take item i (if it fits)
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    cout << "Maximum value: " << dp[n][W] << "\n";
}
// Time: O(n*W), Space: O(n*W)
