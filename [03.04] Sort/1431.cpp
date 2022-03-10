//
// Created by s2soo on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();

    int sumA = 0, sumB = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9')
            sumA += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] >= '0' && b[i] <= '9')
            sumB += b[i] - '0';
    }

    if (sumA != sumB)
        return sumA < sumB;

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<string> serial(N);
    for (int i = 0; i < N; i++) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << serial[i] << "\n";
    }
    return 0;
}