// �ٽ� Ǯ���!
// #pair �ڷ��� ����, #�׸���_Ȱ�� ���� ����(Activity Selection problem)

// pair �ڷ��� ���� ���� reference : https://ya-ya.tistory.com/91

#include <iostream>
#include <vector> // pair �ڷ����� utility ���̺귯���� include �ؾ������� vector�� �̹� ����� �ִ�.
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    typedef pair<int, int> p;
    vector<p> schdule;
    // �Ǵ� vector<pair<int, int>> schdule; ó�� ��뵵 ����
    int N; // ȸ���� ��
    
    // �Է� �ޱ�
    cin >> N;
    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        schdule.push_back(make_pair(end, start));
    }

    // ���� ���� ������� ����
    sort(schdule.begin(), schdule.end());

    int time = schdule[0].first; // ���� �ð�
    int answer = 1; // ������ �ִ� ȸ�� ����

    for(int i=1; i<schdule.size(); i++) {
        if(time > schdule[i].second) {
            continue;
        }
        time = schdule[i].first;
        answer++;  
    }
    
    cout << answer;
    return 0;
}