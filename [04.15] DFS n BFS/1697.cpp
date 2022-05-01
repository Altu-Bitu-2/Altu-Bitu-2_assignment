//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0);  // 방문 체크 & 시간 저장
    queue<int> q; //큐에 좌표값 저장
    int ans = 0; // 초기화

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n); // 시작 노드 q에 삽입
    while (!q.empty()) { // q가 빌 때까지 반복
        int x = q.front(); // 현재 좌표
        q.pop(); // 방문했으므로 제거

        if (x == k) { // 수빈이가 동생을 만났다면
            ans = check[x] - 1; // 만났으므로 시간 하나 감소
            break; // 반복 중지
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        // 범위 체크
        for (int i = 0; i < 3; i++) {
            // 좌표값이 유효하고, 아직 방문하지 않은 곳이라면
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {
                check[child[i]] = check[x] + 1; // 시간 증가
                q.push(child[i]); // q에 삽입
            }
        }
    }
    return ans; // 값 반환
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}