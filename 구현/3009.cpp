// 구현 + 규칙 찾기
// 모든 수가 두 번씩 나와야 한다.

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 1001 // 최대 좌표 수 : 1000
int pointx[MAX_N];
int pointy[MAX_N];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //memset(&point[0], &point[MAX_N], 0);
    
    for(int i=0; i<3; i++) {
        int x, y;
        cin >> x >> y;
        pointx[x]++;
        pointy[y]++;
    }

    for(int i=0; i<MAX_N; i++) {
        if(pointx[i] == 1)
            cout << i << " ";
    }

    for(int i=0; i<MAX_N; i++) {
        if(pointy[i] == 1)
            cout << i;
    }

    return 0;
}