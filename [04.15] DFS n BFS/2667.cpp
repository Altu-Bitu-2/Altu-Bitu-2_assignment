//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//단지 내 집 개수 탐색하는 bfs
int bfs(int n, int r, int c, vector<vector<bool>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;

    //큐 초기화
    q.push({r, c}); // 집의 좌표 저장
    board[r][c] = false; // 방문 했으므로 false로 바꿔주기
    int cnt = 1; // 개수 초기화
    while (!q.empty()) { // q가 빌 때까지
        int cr = q.front().first; // 집의 x 좌표
        int cc = q.front().second; // 집의 y 좌표
        q.pop(); // 방문했으므로 제거

        // 상하좌우 확인
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; // 좌우 확인
            int nc = cc + dc[i]; // 상하 확인
            // 주어진 범위를 벗어났거나, 이미 방문한 집이라면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) {
                continue; // pass
            }
            q.push({nr, nc}); // 아니라면 q에 집의 좌표 삽입
            board[nr][nc] = false; // 방문했으므로 false로
            cnt++; // 집 개수 증가
        }
    }
    return cnt; // 개수 반환
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>> &board) {
    vector<int> complex; // 단지 내 집 개수 저장 배열
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) { // 집이 있는 곳이면
                int cnt = bfs(n, i, j, board); // 단지 내 집 개수 구하기
                complex.push_back(cnt); // 각 단지 내 집 개수 저장
            }
        }
    }
    return complex; // 배열 반환
}

/**
 * [단지 번호 붙이기] - bfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    int n;
    string s;

    //입력
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false)); // 지도
    for (int i = 0; i < n; i++) {
        cin >> s; // 문자열로 입력 받음
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0'; // 숫자로 저장
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board);
    sort(ans.begin(), ans.end()); // 정렬

    //출력
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}