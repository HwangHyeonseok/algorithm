// #그리디
// 전략 : N 개의 로프가 있을 때, 각 로프가 버틸 수 있는 중량을 정렬하고나서
// 가장 적은 무게를 버틸 수 있는 로프에 N을 곱하고 그 다음으로 버틸 수 있는 무게에 N-1, .... 을 모두 구하여
// 가장 큰 값을 출력하면 된다.

// 예를 들어, 3개의 로프가 있고, 각각 1, 15, 10 의 하중을 버틸 수 있다고 할 때,
// 로프 별 버틸 수 있는 하중을 오름차순으로 정렬하고 (1,10,15)
// N, N-1, N-2.... 을 곱해줄 때 가장 큰 값이 되는 것을 구하면 된다.
// 이 문제에서 1*3 = 3, 10*2 = 20, 15*1 = 15 이므로,
// 로프가 버틸 수 있는 최대의 중량은 20 이다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> w; // 각 로프가 버틸 수 있는 중량 (입력)
    vector<int> answer;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int weight;
        cin >> weight;
        w.push_back(weight);
    }

    // 정렬하여 N, N-1, N-2, N-3 ... 을 곱해주는 과정
    sort(w.begin(), w.end()); // 1 10 15
    
    for(int i=0; i<w.size(); i++) {
        answer.push_back(w[i]*(w.size()-i));
    }

    // 이제 감내 가능한 무게 중 가장 큰 것을 출력
    sort(answer.begin(), answer.end(), greater<>());
    
    cout << answer[0];

    return 0;
}