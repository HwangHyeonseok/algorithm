// https://www.acmicpc.net/problem/1783

// 그리디 + 구현
// N과 M의 범위가 매우 크다. ==> 시간복잡도는 O(1)이어야 한다.
// 병든 나이트는 무조건 오른쪽으로 움직인다는 것을 이용한다.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;
    int answer = 1;

    cin >> N >> M;

    // 위 아래 상관 없음
    if(N >= 3) {
        if(M >= 6) answer = M - 2;
        else if(M == 4 || M == 5) answer = 4;
        else if(M == 3) answer = 3;
        else if(M == 2) answer = 2;
        else if(M <= 1) answer = 1;
    }

    // 위 아래도 신경을 써야함
    if( N == 2) {
        if(M >= 7) answer = 4;
        else if(M >= 5) answer = 3;
        else if(M >= 3) answer = 2;
        else answer = 1;
    }
    if (N == 1) answer = 1;

    cout << answer;
    return 0;
}