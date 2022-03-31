//
// Created by s2soo on 2022-03-31.
//

#include <iostream>
#include <vector>

using namespace std;

int getRank(vector<int> v, int n, int new_score, int p) {
    int result = -1;

    // 등수 계산
    vector<int> rank;
    bool flag = false; // 동점 발생 시 true
    for (int i=0; i<n; i++) {
        if (v[i] > new_score)
            continue;

        if (v[i] == new_score) {
            flag = true;
            // index랑 등수는 1 차이가 나므로 보정
            rank.push_back(i+1); // index 저장용
            continue;
        }

        if (v[i] < new_score) {
            // index랑 등수는 1 차이가 나므로 보정
            rank.push_back(i+1);
            break;
        }
    }

    // 점수판에 있는 점수가 다 new_score보다 크면
    if (rank.empty())
        return -1;

    // 동점 발생 시 첫 index가 등수
    if (flag)
        result = rank.front();
    // 동점이 없을 땐 마지막에 저장된 index가 등수
    else
        result = rank.back();

    // 등수가 p보다 크면 점수판에 못 들어감
    // 등수==p이나 동점 아닌 경우는 p등이 되므로, 동점 있을 때만 조건 적용
    if (flag && result >= p)
        result = -1;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, new_score, p;
    vector<int> v(55, 0); // 점수판에 있는 점수 저장
    cin >> n >> new_score >> p;

    if (n > 0) {
        for (int i=0; i<n; i++)
            cin >> v[i];

        cout << getRank(v, n, new_score, p);
    }
    // n==0: 점수판에 점수 없을 때
    else
        cout << 1;

    return 0;
}