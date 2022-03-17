//
// Created by s2soo on 2022-03-17.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i=1; i<=n; i++)
        q.push(i);

    cout << "<";

    int data;
    vector<int> v;
    while (!q.empty()) {
        for (int i=0; i<k-1; i++) {
            data = q.front();
            q.pop();
            q.push(data);
        }
        v.push_back(q.front());
        q.pop();
    }

    for (int i=0; i<n; i++) {
        cout << v[i];
        if (i != n - 1)
            cout << ", ";
        else
            cout << ">";
    }
    return 0;
}