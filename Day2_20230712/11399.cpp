// #�׸���

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    int answer= 0;
    vector<int> time;
    
    cin >> N;
// �ο��� ��ŭ �ִ´�.
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        time.push_back(t);
    }
    
    // ���� ����� ���� -> �������� ����
    sort(time.begin(), time.end());
    
    // �ּ� �ð� ���
    for(int j=0; j<N; j++) {
        answer = answer + (N-j) * (time[j]);
    }
    
    cout << answer;
    return 0;
}