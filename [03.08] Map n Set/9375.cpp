//
// Created by s2soo on 2022-03-14.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    int num;
    string name, kind;

    while (tc--) {
        cin >> num;
        map<string, int> m;
        for (int i=0; i<num; i++) {
            cin >> name >> kind;
            if (m.find(kind) != m.end())
                m[kind]++;
            else
                m.insert({kind, 1});
        }

        int result = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            result *= (iter->second) + 1; // 여러 개 중 하나 pick + 안 입거나
        }

        result--; // 알몸 제외
        cout << result << "\n";
    }

    return 0;
}
