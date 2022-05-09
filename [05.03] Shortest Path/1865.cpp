//
// Created by s2soo on 2022-05-09.
//

#include <iostream>
#include <vector>

#define MAX 10000000

using namespace std;

struct road {
    int S, E, T;
};

bool possible(int N, vector<road> v) {
    vector<int> dist(N + 1, MAX);

    int s, e, t;
    dist[1] = 0;

    // 총 노드의 수 만큼 반복
    for (int i = 1; i < N; i++) {

        // 각 노드 계산
        for (int j = 0; j < v.size(); j++) {
            s = v[j].S;
            e = v[j].E;
            t = v[j].T;

            if (dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;
        }
    }

    // 각 노드 계산
    for (int i = 0; i < v.size(); i++) {
        s = v[i].S;
        e = v[i].E;
        t = v[i].T;

        if (dist[e] > dist[s] + t)
            return true;
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TC;
    cin >> TC;

    int N, M, W;
    int s, e, t;

    for (int i = 0; i < TC; i++) {

        cin >> N >> M >> W;
        vector<road> v;

        // 도로 정보
        for (int j = 0; j < M; j++) {
            cin >> s >> e >> t;
            v.push_back({ s,e,t });
            // 도로는 양방향이므로
            v.push_back({ e,s,t });
        }

        // 웜홀 정보
        for (int j = 0; j < W; j++) {
            cin >> s >> e >> t;
            // 웜홀은 시간이 거꾸로 흐르므로 t 대신 -t
            v.push_back({ s,e,-t });
        }

        if (possible(N, v))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;

}