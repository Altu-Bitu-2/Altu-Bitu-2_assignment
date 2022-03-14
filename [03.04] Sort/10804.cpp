//
// Created by s2soo on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void shuffle(int a, int b) {
    reverse(card.begin() + a - 1, card.begin() + b);
}

int main() {

    int a, b;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        shuffle(a, b);
    }

    for (int i = 0; i < 20; i++) {
        cout << card[i] << " ";
    }
    return 0;
}