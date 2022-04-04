//
// Created by s2soo on 2022-04-04.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);

    for (int i=0; i<n; i++)
        cin >> arr[i];

    for (int i=0; i<n; i++) {
        dp[i] = 1;

        for (int j=0; j<i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j]+1)
                dp[i] = dp[j] + 1;
        }
    }

    int len = 0;
    for (int i=0; i<n; i++) {
        if (len < dp[i])
            len = dp[i];
    }

    cout << len;
    return 0;
}
