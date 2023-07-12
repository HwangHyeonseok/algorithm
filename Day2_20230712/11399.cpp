// #그리디

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
// 인원수 만큼 넣는다.
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        time.push_back(t);
    }
    
    // 작은 순대로 정렬 -> 내림차순 정렬
    sort(time.begin(), time.end());
    
    // 최소 시간 계산
    for(int j=0; j<N; j++) {
        answer = answer + (N-j) * (time[j]);
    }
    
    cout << answer;
    return 0;
}