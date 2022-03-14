//
// Created by s2soo on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> line(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> line[i];
    }

    sort(line.begin(), line.end(), greater<>());

    // sum 변수를 long long 으로 !
    // 처음에 int로 했는데 틀림
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (line[i] - i > 0)
            sum += line[i] - i;
    }

    cout << sum;

    return 0;
}