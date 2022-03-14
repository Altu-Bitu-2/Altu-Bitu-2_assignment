//
// Created by s2soo on 2022-03-10.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, m, s, q, T, c;
    cin >> h >> m >> s;
    cin >> q;

    int time;
    time = h * 3600 + m * 60 + s;
    for (int i = 0; i < q; i++) {
        cin >> T;

        if (T == 1) {
            cin >> c;
            time = (time + c) % 86400;
        }
        else if (T == 2) {
            cin >> c;
            time = (time - c) % 86400;
            while (time < 0)
                time += 86400;
        }
        else if (T == 3) {
            s = time % 60;
            m = (time / 60) % 60;
            h = time / 3600;

            cout << h << " " << m << " " << s << "\n";
        }
    }
    return 0;
}