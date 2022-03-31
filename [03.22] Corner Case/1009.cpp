//
// Created by s2soo on 2022-03-28.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int tc;
    cin >> tc;

    int a,b;
    int num;
    for (int i=0; i<tc; i++) {
        cin >> a >> b;

        // num 초기화
        num = 1;
        for (int j=0; j<b; j++) {
            num *= a;

            // 1의 자리만 필요함
            if (num > 10)
                num %= 10;
        }

        // num == 0이 될 수도 있음
        // 0번 컴퓨터가 아닌, 10번 컴퓨터가 처리해주는 것이므로 num값을 바꿔줘야 함
        if (num == 0)
            num = 10;

        // 출력
        cout << num << "\n";
    }

    return 0;
}

