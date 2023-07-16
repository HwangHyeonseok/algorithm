// #�׸���_Ȱ�� ���� ����(Activity Selection problem)
// �ð� �ʰ� : ������ �ٽ� Ǯ��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // n���� ������ �־�����.
    typedef pair<int, int> p;
    vector<p> time_table;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        time_table.push_back(make_pair(end, start));
    }

    sort(time_table.begin(), time_table.end(), greater<>());

    // �ʿ��� �ּ� ���ǽ� ��
    long long int lecture_room = 1;
    // ���� �ð��� ���� �ڿ� �ִ� ó�� �����ٺ��� �����ϱ� ����
    long long int cur_finish_time = time_table[0].second;
    long long int i = 0;
    time_table.erase(time_table.begin());

    while (time_table.size() != 0) {
        if (i + 1 > time_table.size()) {
            lecture_room++;
            i = 0;
            cur_finish_time = 10000000001; 
        }

        if (cur_finish_time >= time_table[i].first) {
            cur_finish_time = time_table[i].second;
            time_table.erase(time_table.begin() + i);
        }
        else {
            i++;
        }
    }

    cout << lecture_room;
    return 0;
}