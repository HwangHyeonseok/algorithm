#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;
#define MAX_N 10 // 최대 맵 크기 10 * 10
int Graph[MAX_N][MAX_N];
int n; // 맵 크기

void dfs(int start_y, int start_x, int paint) {
    typedef pair<int, int> p;
    stack<p> s;
    // 상하좌우 이동을 위한 배열
    int move_x[4] = {0, 0, -1, 1};
    int move_y[4] = {-1, 1, 0, 0};
    
    // 첫 위치 스택에 push
    s.push(make_pair(start_y, start_x)); // s.push({start_y,start_x}); 도 가능

    while(!s.empty()) {
        // 1. 방문 처리 및 값 처리
        int cur_x = s.top().second;
        int cur_y = s.top().first;
        s.pop();
        
        if(Graph[cur_y][cur_x] != 0) continue;

        Graph[cur_y][cur_x] = paint;

        // 2. 주변 노드 탐색 (상하좌우)
        for(int next = 0; next < 4; next++) {
            int next_x = cur_x + move_x[next];
            int next_y = cur_y + move_y[next];

            // 이동이 가능할 조건 : 1) 이동이 가능한 영역이거나, 2) 이미 이동한 적이 없는 영역 3) 맵 범위 안
            if(Graph[next_y][next_x] != 0) // 1) 2)
                continue;
            if(next_x >= n || next_x < 0 || next_y >= n || next_y < 0) //3)
                continue;
            
            s.push(make_pair(next_y, next_x));
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n; 
    // 맵 정보 입력
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int condition; // 0 : 이동 가능, 1 : 벽(이동 불가)
            cin >> condition;
            Graph[i][j] = condition;
        }
    }
    
    // 시작 지점
    int start_x, start_y, paint;
    cin >> start_x >> start_y >> paint;
    
    dfs(start_y, start_x, paint);
    return 0;
}