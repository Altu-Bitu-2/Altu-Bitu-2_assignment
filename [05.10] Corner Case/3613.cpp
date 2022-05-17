//
// Created by s2soo on 2022-05-17.
//

#include <iostream>

using namespace std;

// 입력된 변수명이 C++ 형식인지 판단
bool isCpp(string str) { //c++ 형식인가?
    for (int i = 0; i < str.size(); i++) { // 변수명 글자수만큼 반복
        if (isupper(str[i])) { //대문자가 있으면 안됨
            return false; // C++ 형식 아니므로 false 반환
        }
        //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) {
            return false; // C++ 형식 아니므로 false 반환
        }
    }
    return true; // 다 해당 안 되면 C++ 형식이므로 true 반환
}

// 입력된 변수명이 Java 형식인지 판단
bool isJava(string str) { //java 형식인가?
    //첫 글자가 대문자거나, '_'가 있으면 안됨
    return !isupper(str[0]) && str.find('_') == string::npos;
}

//java 형식을 c++로
string toCpp(string str) {
    string result; // c++ 형식으로 바꾼 최종 결과
    for (int i = 0; i < str.size(); i++) { // 변수명 글자수만큼 반복
        if (isupper(str[i])) { //대문자라면 앞에 '_' 삽입
            result += '_'; // '_' 삽입
        }
        result += tolower(str[i]); //소문자로 바꿔서 넣기
    }
    return result; // 결과 반환
}

//c++ 형식을 java로
string toJava(string str) {
    string result; // Java 형식으로 바꾼 최종 결과
    for (int i = 0; i < str.size(); i++) { // 변수명 글자수만큼 반복
        if (str[i] == '_') { //'_' 라면 그 다음 글자를 대문자로 바꿔서 삽입
            result += toupper(str[i + 1]); // 대문자로 바꿔서 삽입
            i++; // '_' 빠지면서 글자수 하나 줄었으므로 i를 증가
            continue; // 그 다음 글자 대문자로 바꿨으므로 다음 반복으로
        }
        result += str[i]; //나머지 글자는 그냥 삽입
    }
    return result;
}

/**
 * [Java vs C++]
 *
 * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 * 2. "Error!"인 경우 (C++)
 *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
 *    2-2. 언더바('_')가 연속해서 등장하는 변수
 *    2-3. 대문자가 등장하는 변수
 * 3. "Error!"인 경우 (Java)
 *    3-1. 대문자로 시작하는 변수
 *    3-2. 언더바('_')가 등장하는 변수
 */

int main() {
    string str; // 변수명

    cin >> str; // 변수명 입력
    bool is_cpp = isCpp(str); // 입력된 변수명이 C++ 형식인지
    bool is_java = isJava(str); // 입력된 변수명이 Java 형식인지

    if (is_cpp && is_java) { //두 형식에 모두 부합하면 그냥 출력
        cout << str; // 그냥 출력
    } else if (is_cpp) { //c++ 형식이라면 java로 바꿔서 출력
        cout << toJava(str); // Java 형식으로 바꿔서 출력
    } else if (is_java) { //java 형식이라면 c++로 바꿔서 출력
        cout << toCpp(str); // C++ 형식으로 바꿔서 출력
    } else { //둘 다 아니라면 에러
        cout << "Error!"; // 에러 출력
    }
    return 0;
}