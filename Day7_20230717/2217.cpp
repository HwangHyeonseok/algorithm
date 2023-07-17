// #�׸���
// ���� : N ���� ������ ���� ��, �� ������ ��ƿ �� �ִ� �߷��� �����ϰ���
// ���� ���� ���Ը� ��ƿ �� �ִ� ������ N�� ���ϰ� �� �������� ��ƿ �� �ִ� ���Կ� N-1, .... �� ��� ���Ͽ�
// ���� ū ���� ����ϸ� �ȴ�.

// ���� ���, 3���� ������ �ְ�, ���� 1, 15, 10 �� ������ ��ƿ �� �ִٰ� �� ��,
// ���� �� ��ƿ �� �ִ� ������ ������������ �����ϰ� (1,10,15)
// N, N-1, N-2.... �� ������ �� ���� ū ���� �Ǵ� ���� ���ϸ� �ȴ�.
// �� �������� 1*3 = 3, 10*2 = 20, 15*1 = 15 �̹Ƿ�,
// ������ ��ƿ �� �ִ� �ִ��� �߷��� 20 �̴�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> w; // �� ������ ��ƿ �� �ִ� �߷� (�Է�)
    vector<int> answer;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int weight;
        cin >> weight;
        w.push_back(weight);
    }

    // �����Ͽ� N, N-1, N-2, N-3 ... �� �����ִ� ����
    sort(w.begin(), w.end()); // 1 10 15
    
    for(int i=0; i<w.size(); i++) {
        answer.push_back(w[i]*(w.size()-i));
    }

    // ���� ���� ������ ���� �� ���� ū ���� ���
    sort(answer.begin(), answer.end(), greater<>());
    
    cout << answer[0];

    return 0;
}