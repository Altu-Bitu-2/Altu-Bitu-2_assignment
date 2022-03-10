//
// Created by s2soo on 2022-03-10.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int num;
    cin >> num;

    int* a;
    int* b;
    a = new int[num];
    b = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < num; i++) {
        cin >> b[i];
    }

    int sum = 0;
    sort(a, a + num);
    sort(b, b + num, compare);

    for (int i = 0; i < num; i++) {
        sum += a[i] * b[i];
    }

    cout << sum;
}