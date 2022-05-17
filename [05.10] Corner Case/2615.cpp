//
// Created by s2soo on 2022-05-17.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    // 범위가 유효하고, 돌의 색이 같으면 true 반환
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
}

// 가능한 모든 배치에 대해 오목 여부 확인
bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1};
    int dc[4] = {1, 0, 1, 1};

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) {
        return false; // 이어지는 돌이 있으면 false 반환
    }

    int cnt = 0; // 초기화
    //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
    while (cnt < 6 && promising(r, c, stone, board)) {
        cnt++; // 개수 증가
        r += dr[d]; // 위치 이동
        c += dc[d]; // 위치 이동
    }
    return cnt == 5; // 오목 완성이 됐는지
}

// 누군가 이겼는지 확인
bool isEnd(int r, int c, vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) {
            return true;
        }
    }
    return false;
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // 바둑판

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j]; // 바둑판 상태 입력
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) { //돌이 없음
                continue; // 다음 단계로
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                // 이긴 바둑알 종류와 가장 왼쪽에 위치한 바둑알의 좌표 출력
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}