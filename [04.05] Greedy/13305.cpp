//
// Created by s2soo on 2022-04-11.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100000];
int cost[100000];

int main(void){
    int n;
    long long total=0;
    long long c_now;

    cin >> n;

    for(int i=1; i<n; i++){
        cin >> dist[i];
    }
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }

    c_now = cost[0];
    total = c_now * dist[1];

    for(int i=1; i<n; i++){
        if(c_now < cost[i]){
            total += c_now * dist[i+1];
        }
        else{
            c_now = cost[i];
            total += c_now*dist[i+1];
        }
    }

    cout << total;
}