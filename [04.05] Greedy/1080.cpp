//
// Created by s2soo on 2022-04-11.
//

#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, int m, vector<vector<char>> mat_a, vector<vector<char>> mat_b) {
    int result = 0;

    // 연산의 크기: 3x3 행렬
    for (int i=0; i<=n-3; i++) {
        for (int j=0; j<=m-3; j++) {

            // 두 행렬의 (i, j)번째 위치의 원소가 다르면 변환
            if (mat_a[i][j] != mat_b[i][j]) {
                // 변환: 0->1, 1->0
                for (int k=i; k<i+3; k++) {
                    for (int l=j; l<j+3; l++) {
                        if (mat_a[k][l] == '1')
                            mat_a[k][l] = '0';
                        else
                            mat_a[k][l] = '1';
                    }
                }
                result++;
            }

        }
    }

    // 두 행렬이 다르면 -1 반환
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat_a[i][j] != mat_b[i][j])
                return -1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix_a(n, vector<char>(m));
    vector<vector<char>> matrix_b(n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cin >> matrix_a[i][j];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cin >> matrix_b[i][j];
    }

    cout << Solve(n, m, matrix_a, matrix_b);

    return 0;
}