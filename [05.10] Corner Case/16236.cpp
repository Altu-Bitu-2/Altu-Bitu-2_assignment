//
// Created by s2soo on 2022-05-17.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    // 상 하 좌 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF; // 최대값으로 설정
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; // 상어의 현재 위치는 거리가 1 + 방문했음
    q.push(shark); // 상어의 현재 위치 삽입
    while (!q.empty()) { // 큐가 빌 때까지 반복
        int row = q.front().first; // 상어의 현재 위치의 x값
        int col = q.front().second; // 상어의 현재 위치의 y값
        q.pop(); // 큐 제거

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue; // 다음 단계로
        }
        // 상하좌우 4번 반복
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i]; // 가로 증감
            int nc = col + dc[i]; // 세로 증감
            // 범위를 벗어나거나, 이미 방문했거나, 물고기가 상어 크기보다 크다면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue; // pass
            }

            // 아니라면
            dist[nr][nc] = dist[row][col] + 1; // 현재 위치보다 거리가 1 더 큼
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); // 현재 먹을 수 있는 물고기 위치 추가
                min_dist = dist[nr][nc]; // 최소 거리로 설정
                continue; // 다음 단계로
            }
            q.push({nr, nc}); // 해당 위치 큐에 삽입입
        }
   }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; // 최소 거리와 결과 반환
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) { // 첫 번째 값 기준으로 비교
            return p1.first < p2.first;
        }
        // 첫 번째 값이 같으면 두 번째 값 기준으로 비교
        return p1.second < p2.second;
    });
    return {min_dist - 1, list[0]}; // 결과 반환
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; // 초기화
    while (true) { // 무한 루프
        pair<int, ci> result = nextPos(n, size, shark, board); // 다음 위치
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; // 반복문 종료
        }
        ans += result.first; // 먹을 수 있는 물고기 있으면 시간 증가
        cnt++; // 먹은 물고기 개수도 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0; // 초기화
            size++; // 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; // 방문했음
        shark = result.second; // 다음 위치가 현 위치
    }
    return ans; // 시간 반환
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n; // 공간의 크기
    pair<int, int> shark_pos; // 상어의 현재 위치

    //입력
    cin >> n; // 공간의 크기 입력
    vector<vector<int>> board(n, vector<int>(n)); // 공간
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; // 공간의 상태 입력
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j); // 상어의 위치 저장
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}