//
// Created by s2soo on 2022-05-31.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0;

//입력받은 보드에서의 최댓값 구하기
int getMaxBlock(matrix &board) {
    int max_block = 0; //초기화
    for (int i = 0; i < n; i++) { //nxn번 반복
        for (int j = 0; j < n; j++) { //보드판 전체를 순회
            max_block = max(max_block, board[i][j]); //보드판을 돌면서 최대값인 블럭 구하기
        }
    }
    return max_block; //최댓값 반환
}

//Transpose matrix 구하는 함수
matrix transposeMatrix(matrix &board) {
    matrix board_t(n, vector<int>(n, 0)); //새로운 보드판 생성
    for (int i = 0; i < n; i++) { //nxn번 반복
        for (int j = 0; j < n; j++) { //nxn번 반복
            board_t[i][j] = board[j][i]; //행과 열의 위치를 바꿔 저장
        }
    }
    return board_t; //transpose matrix 반환
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) { //행의 개수 n만큼 반복
        int idx = 0; //인덱스 초기화
        int prev = 0; //전의 값 초기화
        for (int i = 0; i < n; i++) { //열의 개수 n만큼 반복
            if (!board[i][j]) { //블록이 존재하지 않는다면
                continue; //넘어간다
            }
            if (board[i][j] == prev) { //블록이 전의 값(=위의 값)과 같다면
                temp[idx - 1][j] *= 2; //위부터 합쳐주므로 위의 칸의 값 두 배
                prev = 0; //해당 칸은 비워짐
            } else { //같지 않다면
                temp[idx++][j] = board[i][j]; //해당 칸은 그대로 채워줌
                prev = board[i][j]; //현재 값이 전의 값(=위 칸의 값)이 됨
            }
        }
    }
    return temp; //새롭게 만든 보드 반환
}

//백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { //이동횟수가 5번이면 종료
        ans = max(ans, getMaxBlock(board)); //현재까지의 최댓값과 새로 구한 값 중 최댓값 결정
        return; //종료
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board);
    //상
    backtracking(cnt + 1, upMove(board)); //원래 배열에서 상으로 움직임
    //하
    reverse(board.begin(), board.end()); //원래 배열 뒤집음
    backtracking(cnt + 1, upMove(board)); //뒤집은 배열 상으로 움직임
    //좌
    backtracking(cnt + 1, upMove(board_t)); //Transpose matrix를 상으로 움직임
    //우
    reverse(board_t.begin(), board_t.end()); //Transpose matrix를 뒤집음
    backtracking(cnt + 1, upMove(board_t)); //뒤집은 배열을 상으로 움직임
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력
    cin >> n;
    matrix board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    backtracking(0, board);

    //출력
    cout << ans;
    return 0;
}