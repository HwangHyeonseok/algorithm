// 시작점이 여러 개인 1차원에서의 BFS

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 200001 // 음수 쪽으로 이동해서 목적지까지 최단거리로 도착하는 경우는 없음. 그러나, 99,999 * 2을 해서 -1을 할 수도 있으므로 최대 20만으로 잡고 한다.
int minimum_arrive[MAX_N]; // 각 위치로 도착하는데 최단 거리 (default : 0)

void bfs(int start, int finish) {
    queue<int> q;
    fill(&minimum_arrive[0], &minimum_arrive[MAX_N], -1);

    q.push(start);
    minimum_arrive[start] = 0;


    while(!q.empty()) {
        int cur = q.front(); // cur : 현재 위치
        int dx[3] = {cur-1, cur+1, cur*2};
        if(cur == finish) { // 목표 지점 도착 시
            cout << minimum_arrive[cur];
            return;
        }
        q.pop();

        for(int i=0; i<3; i++) {
            int next = dx[i];
            if(minimum_arrive[next] != -1) continue; // 이미 방문한 노드인지 검사
            if(next < 0 || next > 100000) continue; // 0보다 작은 경우로 가서 최소 방문 거리 수가 나올 수 없음
            // 10만을 넘기는 경우에도 최소 방문 거리 수가 나올 수 없음. 차라리 -1을 하고 *2를 하는 것이 더 방문 거리 수가 적게 나오기 때문
            
            q.push(next);
            minimum_arrive[next] = minimum_arrive[cur] + 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int start, finish; // 시작 위치와 끝 위치
    cin >> start >> finish; 
    
    bfs(start, finish);

    return 0;
}