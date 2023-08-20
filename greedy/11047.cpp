// https://www.acmicpc.net/problem/11047

// �׸��� �˰��� Ȱ�� 
// ��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���) ���� i �� 2�� ��쿡 Ai�� Ai-1�� ��� ���� ������ �׸��� �˰��� ����
// ������ ū ������ ���ִ� ���� ������ ���� �ּҰ� �� �� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // ������ ���� 
    int target_money; // ���� ��ġ�� ��
    vector<int> coins; // ȭ�� ���� (��, 1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���)
    int answer = 0;

    cin >> N >> target_money;

    for(int i=0; i<N; i++) {
        int coin_type;
        cin >> coin_type;
        coins.push_back(coin_type);
    }

    sort(coins.begin(), coins.end(), greater<>()); // �������� ����

    for (int coin : coins) {
        while(target_money >= coin) {
            target_money -= coin;
            answer++;
        }
    }

    cout << answer;

    return 0;
}
