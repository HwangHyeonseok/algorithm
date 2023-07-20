#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 10

int Graph[MAX_N][MAX_N];
int n;

struct Point {
    int pos_x;
    int pos_y;
    int distance; // 거리
};

int bfs(int start_x, int start_y, int target_x, int target_y) {
    // 이동 구현 상하좌우
    int move_x[4] = {0, 0, -1, 1};
    int move_y[4] = {-1, 1, 0,0 };
    
    queue<Point> locations; // 위치들을 담은 큐

    if(start_y == target_y && start_x == target_x) return 0; // 시작 위치부터 도착 위치와 같은 경우

    // 초기 위치 처리 - 방문처리 + push
    Graph[start_x][start_y] = 1;
    locations.push({start_x, start_y, 0});

    while(!locations.empty()) {
        int cur_x = locations.front().pos_x;
        int cur_y = locations.front().pos_y;
        int dist = locations.front().distance;

        locations.pop();
        
        // 목적지에 도달했는지 확인
        if(cur_x == target_x && cur_y == target_y)
            return dist;

        for(int next = 0; next < 4; next++) {
            int next_x = cur_x + move_x[next];
            int next_y = cur_y + move_y[next];
            // 다음 위치로 이동이 가능할 조건 1) 맵 범위 안쪽 2) 방문한 적이 없는 위치 3) 연결된 위치
            if(next_x >= n || next_x < 0 || next_y >=n || next_y <0) continue; // 1)
            if(Graph[next_x][next_y] != 0) continue; // 2)

            // 방문 처리 및 push
            Graph[next_x][next_y] = 1;
            locations.push({next_x, next_y, dist+1});
        }
    }
    return -1; // 비정상 (길을 찾을 수 없음)
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    // 맵 크기 입력
    cin >> n;
    // 맵의 정보 입력 (이동 가능 : 0, 벽(이동 불가) : 1)
    for(int i=0; i<n; i++) { // y
        for(int j=0; j<n; j++) { // x
            int condition;
            cin >> condition;
            Graph[i][j] = condition;
        }
    }
    int start_x, start_y; // 시작 위치 (x,y)
    int target_x, target_y; // 도착 위치 (x,y)
    int answer = 0; // 이동 횟수
    cin >> start_x >> start_y >> target_x >> target_y;
    
    answer = bfs(start_x, start_y, target_x, target_y);
    cout << answer;

    return 0;
}