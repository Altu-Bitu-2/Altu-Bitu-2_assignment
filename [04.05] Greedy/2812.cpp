//
// Created by s2soo on 2022-04-11.
//

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string str;
    stack<char> st;
    cin >> n >> k >> str;

    int cnt = k;
    for (int i = 0; i < str.length(); i++) {
        while (!st.empty() && st.top() - '0' < str[i] - '0' && k > 0) {
            st.pop();
            k--;
        }
        st.push(str[i]);
    }
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n - cnt; i++)
        cout << ans[i];
    return 0;
}