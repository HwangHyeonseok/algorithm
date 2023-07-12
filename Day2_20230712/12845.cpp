// #�׸���
// Ǯ�� ���̵�� : �������� �����Ͽ� ������ ���� ���� ī�带 ���� �ռ��ϸ� ���� ī�� �� ���� ���� ��带 ȹ���� �� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm> // ���� ���

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int gold = 0; // ȹ���� ���� ���
    vector<int> cards_level; // ī����� ������ ��Ƴ��� �迭
    int n; // ī���� ����

// ī�� ���� �Է¹ޱ� + ī�� ������ŭ ī���� ���� �Է¹ޱ�
    cin >> n;
    for(int i=0; i<n; i++) {
        int level;
        cin >> level;
        cards_level.push_back(level);
    }
    
    // ī�� ������ �������� ����
    sort(cards_level.begin(), cards_level.end(), greater<>());
    
    // ī�� �� ���� �ռ� �� �ռ��� ī���� ������ �ռ��� �� ���� ī�� �� ū ������ �ռ��ȴ�.
    // ��, �ռ��� ���ο� ī��� �׻� cards_level[0] �� ������ �����ٴ� ���� �̿��Ѵ�.
    for(int i=0; i<n-1; i++) {
        gold = gold + cards_level[0]+cards_level[i+1];
    }
    
    cout << gold;
    return 0;
}