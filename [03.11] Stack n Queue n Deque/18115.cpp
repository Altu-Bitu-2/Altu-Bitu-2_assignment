//
// Created by s2soo on 2022-03-17.
//

#include <iostream>

using namespace std;

int N;
int a[1000001];
int cardOrder[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    int num = N;
    int idx1 = 0, idx2 = 1, idx3 = N - 1;
    for (int i = 0; i < N; i++) {
        if (a[i] == 1) {
            cardOrder[idx1] = num;
            if (cardOrder[idx1 + 1] == 0) idx1++;
            else idx1 = idx2 + 1;
        }
        else if (a[i] == 2) {
            if (cardOrder[idx1 + 1] == 0) idx2 = idx1 + 1;
            else idx2 += 1;
            cardOrder[idx2] = num;
        }
        else {
            cardOrder[idx3] = num;
            idx3--;
        }
        num--;
    }

    for (int i = 0; i < N; i++) cout << cardOrder[i] << ' ';

    return 0;
}