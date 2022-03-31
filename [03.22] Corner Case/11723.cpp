//
// Created by s2soo on 2022-03-28.
//

#include <iostream>
#include <set>

using namespace std;

// 집합에 있는지 없는지만 판단하면 되므로 집합 구현할 필요 X ,,
// check만 해주면 됨 !

//set<int> s;
bool flag[21] = {false};


void add (int x) {
    //s.insert(x);
    flag[x] = true;
}

void remove (int x) {
    //s.erase(x);
    flag[x] = false;
}

int check (int x) {
    /*
    if (s.find(x) != s.end())
        return 1;
    else
        return 0;
    */
    if (flag[x])
        return 1;
    else
        return 0;
}

void toggle (int x) {
    /*
    if (s.find(x) != s.end())
        s.erase(x);
    else
        s.insert(x);
    */
    if (flag[x]) {
        //s.erase(x);
        flag[x] = false;
    }
    else {
        //s.insert(x);
        flag[x] = true;
    }
}

void all() {
    //s.clear();
    for (int i=1; i<=20; i++) {
        //s.insert(i);
        flag[i] = true;
    }
}

void empty() {
    //s.clear();
    fill_n(flag, 21, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int M;
    cin >> M;

    string cal;
    int num;
    for (int i=0; i<M; i++) {
        cin >> cal;

        if (cal == "add") {
            cin >> num;
            add(num);
        }
        else if (cal == "remove") {
            cin >> num;
            remove(num);
        }
        else if (cal == "check") {
            cin >> num;
            cout << check(num) << "\n";
        }
        else if (cal == "toggle") {
            cin >> num;
            toggle(num);
        }
        else if (cal == "all")
            all();
        else if (cal == "empty")
            empty();

        /*
        for (auto iter = s.begin(); iter != s.end(); iter++)
            cout << *iter << " ";
        cout << "\n";
        */
    }

    return 0;
}