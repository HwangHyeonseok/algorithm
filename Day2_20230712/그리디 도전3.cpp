//#�׸���
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    vector<vector<int>> cards(10000); // v[0].push_back
    vector<int> smaller;

    cin >> n >> m;
    // ī�� �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            cards[i].push_back(x);
        }
    }
    // ���� ���� ���ڰ� 0�ε����� ���Բ��Ѵ�.
    for (int j = 0; j < n; j++) {
        sort(cards[j].begin(), cards[j].end());
    }

    // �� ������ ���� ���� ���� ����(1�ε���)�� �߰��Ѵ�.
    for (int j = 0; j < n; j++) {
        smaller.push_back(cards[j][1]);
    }
    // ���� ���� �� ū �� ���
    sort(smaller.begin(), smaller.end());
    
    cout << smaller[0];

    return 0;

}