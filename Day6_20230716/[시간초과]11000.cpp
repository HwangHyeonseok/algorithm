// #그리디_활동 선택 문제(Activity Selection problem)
// 시간 초과 : 다음에 다시 풀기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // n개의 수업이 주어진다.
    typedef pair<int, int> p;
    vector<p> time_table;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        time_table.push_back(make_pair(end, start));
    }

    sort(time_table.begin(), time_table.end(), greater<>());

    // 필요한 최소 강의실 수
    long long int lecture_room = 1;
    // 종료 시각이 가장 뒤에 있는 처음 스케줄부터 수행하기 시작
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