// �������� ���� ���� 1���������� BFS

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 200001 // ���� ������ �̵��ؼ� ���������� �ִܰŸ��� �����ϴ� ���� ����. �׷���, 99,999 * 2�� �ؼ� -1�� �� ���� �����Ƿ� �ִ� 20������ ��� �Ѵ�.
int minimum_arrive[MAX_N]; // �� ��ġ�� �����ϴµ� �ִ� �Ÿ� (default : 0)

void bfs(int start, int finish) {
    queue<int> q;
    fill(&minimum_arrive[0], &minimum_arrive[MAX_N], -1);

    q.push(start);
    minimum_arrive[start] = 0;


    while(!q.empty()) {
        int cur = q.front(); // cur : ���� ��ġ
        int dx[3] = {cur-1, cur+1, cur*2};
        if(cur == finish) { // ��ǥ ���� ���� ��
            cout << minimum_arrive[cur];
            return;
        }
        q.pop();

        for(int i=0; i<3; i++) {
            int next = dx[i];
            if(minimum_arrive[next] != -1) continue; // �̹� �湮�� ������� �˻�
            if(next < 0 || next > 100000) continue; // 0���� ���� ���� ���� �ּ� �湮 �Ÿ� ���� ���� �� ����
            // 10���� �ѱ�� ��쿡�� �ּ� �湮 �Ÿ� ���� ���� �� ����. ���� -1�� �ϰ� *2�� �ϴ� ���� �� �湮 �Ÿ� ���� ���� ������ ����
            
            q.push(next);
            minimum_arrive[next] = minimum_arrive[cur] + 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int start, finish; // ���� ��ġ�� �� ��ġ
    cin >> start >> finish; 
    
    bfs(start, finish);

    return 0;
}