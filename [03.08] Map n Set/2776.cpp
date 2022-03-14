//
// Created by s2soo on 2022-03-14.
//

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, n, m, input, num;
    cin >> T;

    while (T--) {
        cin >> n;
        unordered_set<int> s;
        for (int i=0; i<n; i++) {
            cin >> input;
            s.insert(input);
        }

        cin >> m;
        for (int i=0; i<m; i++) {
            cin >> num;
            if (s.find(num) != s.end())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
    }

    return 0;
}