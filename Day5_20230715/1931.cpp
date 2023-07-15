// 다시 풀어보기!
// #pair 자료형 연습, #그리디_활동 선택 문제(Activity Selection problem)

// pair 자료형 연습 참고 reference : https://ya-ya.tistory.com/91

#include <iostream>
#include <vector> // pair 자료형은 utility 라이브러리를 include 해야하지만 vector에 이미 담겨져 있다.
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    typedef pair<int, int> p;
    vector<p> schdule;
    // 또는 vector<pair<int, int>> schdule; 처럼 사용도 가능
    int N; // 회의의 수
    
    // 입력 받기
    cin >> N;
    for(int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        schdule.push_back(make_pair(end, start));
    }

    // 종료 시작 순서대로 정렬
    sort(schdule.begin(), schdule.end());

    int time = schdule[0].first; // 종료 시간
    int answer = 1; // 가능한 최대 회의 개수

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