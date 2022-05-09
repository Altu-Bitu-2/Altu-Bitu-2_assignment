//
// Created by s2soo on 2022-05-01.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited; // nxn의 나라, 인구이동 발생한 나라
queue<ci> countries; // 인구이동 발생 가능한 나라의 위치(좌표)


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) { // 연합의 크기만큼 반복
        int row = union_cord[i].first, col = union_cord[i].second; // 위치 저장
        board[row][col] = population; // 인구 수 저장
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); // 나라의 좌표 저장
    queue<ci> q; // 큐 생성
    q.push({cr, cc}); // 나라의 좌표 저장
    int sum = board[cr][cc], cnt = 1; // 초기화
    while (!q.empty()) { // 큐가 빌 때까지
        cr = q.front().first; // 나라의 위치(x축)
        cc = q.front().second; // 나라의 위치(y축)
        q.pop(); // 나라 제거

        for (int i = 0; i < 4; i++) { // 상하좌우 확인
            int nr = cr + dr[i]; // 좌우 확인
            int nc = cc + dc[i]; // 상하 확인
            // 주어진 범위에서 벗어나거나, 이미 방문한 나라라면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {
                continue; // pass
            }
            int diff = abs(board[nr][nc] - board[cr][cc]); // 두 나라의 인구 차이
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc}); // 인구 이동 발생한 나라의 위치 저장
                visited[nr][nc] = day; // 날짜 저장
                union_cord.push_back({nr, nc}); // 연합에 추가
                sum += board[nr][nc]; // 그 나라의 인구 수 추가
                cnt++; // 나라의 개수 증가
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true; // 이동 발생
    }
    return false; // 이동 발생 X
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) { // 무한 루프
        day++; // 날짜 증가
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) { // size 감소해 0이 되기 전까지
            int row = countries.front().first; // 나라의 위치(x축)
            int col = countries.front().second; // 나라의 위치(y축)
            countries.pop(); // 나라 제거
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue; // pass
            }
            visited[row][col] = day; // 탐색하지 않은 나라라면 날짜 저장
            if (bfs(n, l, r, row, col, day)) { // bfs 수행
                is_move = true; // 인구이동 발생
            }
        }
        if (!is_move) { // 인구이동 발생 안 했으면
            return day - 1; // 하루 감소해 return
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r;

    //입력
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0)); // 초기화
    visited.assign(n, vector<int>(n, 0)); // 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; // 인구수 입력
            countries.push({i, j}); // 나라 위치 저장
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0;
}