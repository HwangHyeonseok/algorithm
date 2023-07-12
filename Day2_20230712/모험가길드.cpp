//# �׸���

// �������� ���� ������� �迭�ؼ� ���� ����.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> gongpo;

    int people;
    cin >> people;
    int answer = 0;

    for(int i=0; i<people; i++) {
        int x;
        cin >> x;
        gongpo.push_back(x);
    }
    // �������� ����
    sort(gongpo.begin(), gongpo.end(), greater<>());
    
    // 3 2 2 2 2 1 �� ��� 3�� ���� �׷� ���ְ� �� ���� �ε��� + 3 ���ش�.
    int index = 0;
    while(people > 0) {
        people -= gongpo[index];
        index += gongpo[index];
        answer++;
    }
    
    cout << answer;

    return 0;
}