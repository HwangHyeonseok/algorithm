// ���� + 1���� �迭 (�迭 �ε����� Ȱ���� �� ����)

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 101 // N�� �ִ� 100

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;
    int BasketNum[MAX_N];
    fill(&BasketNum[0], &BasketNum[MAX_N], 0);

    cin >> N >> M;

    for(int i=0; i< M; i++) {
        int start,end,change;
        cin >> start >> end >> change;
        for(int j=start-1; j<=end-1; j++) {
            BasketNum[j] = change;
        }
    }

    for(int i=0; i<N; i++) {
        cout << BasketNum[i] << " ";
    }
    return 0;
}