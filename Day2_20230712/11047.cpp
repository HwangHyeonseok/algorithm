// #�׸���
// ������ �ִ� ���� 10���� / ��ġ�� �� 4200

// �̶� �ʿ��� ������ ������ �ּڰ�?

// ������ ��ġ�� ����.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // ������ �ִ� ���� ����
    int sum; // ������ �ִ� ������ ��
    vector<int> money; // ���� ������ ��´�.
    int answer = 0; // ������ ����

// ù ��°�� �Է�
    cin >> N >> sum;
// ������ �Է¹޴´�.
    for(int i=0; i<N; i++) {
        int PER; // ���� ����
        cin >> PER;
        money.push_back(PER);
    }
    // ���� ������� sort (��������?) 1000 -> 500 -> 300 ...
    sort(money.begin(), money.end(), greater<>());

// ���� ū ������ ���� �����鼭 ������ ������ ���Ѵ�.
    for(int j=0; j<money.size(); j++) {

    // ���� �� �Һ� �� ������ ����
        while(sum >= money[j]) {
           sum = sum - money[j];
            answer++;
        }
    }

    cout << answer;
    return 0;
}