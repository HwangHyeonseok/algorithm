// Set Ȱ�� - �ߺ��� �����Ͽ� ����

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    int answer = 0;
    set<string> members;
    cin >> N;

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        if(s == "ENTER") {
            answer += members.size();
            set<string>::iterator iter;
            members.clear(); // ��ü ����
            continue;
        }
        members.insert(s);
    }

    answer += members.size();

    cout << answer;

    return 0;
}