//
// Created by s2soo on 2022-03-17.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    stack<int> s[7];

    int n, p;
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> n >> p;

        if (s[n].empty()) {
            s[n].push(p);
            count++;
        }

        else {

            while (!s[n].empty() && s[n].top() > p) {
                s[n].pop();
                count++;
            }

            if (s[n].empty() || s[n].top() != p) {
                s[n].push(p);
                count++;
            }
        }
    }

    cout << count;
}