// unordered_set vs set ���� �̿� - �ߺ� ���� (�ð� ���⵵ ��� �ʿ�)

// ������ CD�� ����� �̹� ���ĵǾ� �����Ƿ� ���ĵ� ���Ե� set�� ���� �� �ʿ䰡 ����.
// ==> unordered_set�� �������.

#include <unordered_set>
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;  // �ִ� 100��

    while(1) {
        unordered_set<long long> CD; // 2��밡 �����Ƿ� long long
        int answer = 0;
        cin >> N >> M;

        if(N == 0 && M == 0) break;
        for(int i=0; i<N; i++) {
            long long x;
            cin >> x;
            CD.insert(x);
        }
        for(int i=0; i<M; i++) {
            long long x;
            cin >> x;
            if(CD.find(x) == CD.end()) continue; // ã�� ���� ���
            answer++;
        }
        // CD set ����
        //CD.clear();
        cout << answer << "\n";

    }
    
    return 0;
}



// �ߺ� ã�� - set ��� �� �־��� ��� O(log N ) �̹Ƿ�, log 100���̴�.
// ������� ��Ͽ� set 100������ �����ϰ�, �� ����� ��ȸ�ϸ鼭 100������ ã���� �������� �׽�Ʈ ���̽��� �����Ƿ�, �ð� �ʰ��� ���� ���̴�.

// #include <set>
// #include <iostream>

// using namespace std;

// int main(void) {
//     ios_base::sync_with_stdio(false); cin.tie(nullptr);
//     int N,M;  // �ִ� 100��

//     while(1) {
//         set<long long> CD; // 2��밡 �����Ƿ� long long
//         int answer = 0;
//         cin >> N >> M;

//         if(N == 0 && M == 0) break;
//         for(int i=0; i<N; i++) {
//             long long x;
//             cin >> x;
//             CD.insert(x);
//         }
//         for(int i=0; i<M; i++) {
//             long long x;
//             cin >> x;
//             if(CD.find(x) == CD.end()) continue; // ã�� ���� ���
//             answer++;
//         }
//         // CD set ����
//         //CD.clear();
//         cout << answer << "\n";

//     }
    
//     return 0;
// }