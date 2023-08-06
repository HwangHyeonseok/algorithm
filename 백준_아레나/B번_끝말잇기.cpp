// 구현 - 문자열 파싱 (배열 이용) + 문자열 비교

// 끝말잇기는 단어를 중복하지 않고 단어의 맨 끝 글자에 이어서 말하는 놀이입니다. 끝말잇기 기록은 단어들의 나열로 이루어집니다. 
// 올바른 끝말잇기 기록은 각 단어의 마지막 글자가 다음 단어의 첫 글자이며, 
// 단어가 중복되어서 나타나면 안 됩니다.

// 끝말잇기 기록이 주어지는데, 하나의 기록은 “?”로 가려진 채로 들어옵니다. 
// “?”에 들어갈 수 있는 문자열들의 후보가 주어질 때, 올바른 끝말잇기 기록을 만드는 “?”에 들어갈 문자열을 출력하세요.

// ------------------------------------ 풀이 --------------------------
// ?에 들어갈 수 있는 단어 기준 : 
// 1) ? 바로 앞에 있던 문자열의 끝 글자로 시작해야 한다.
// 2) ? 바로 뒤에 있던 문자열의 첫 글자로 끝나야 한다.

// 만약 ?가 첫 문자열로 나온 경우, 2)만 충족하면 된다.
// 만약 ?가 끝 문자열로 나온 경우, 1)만 충족하면 된다.

// 3) 중복된 단어는 허용하지 않는다.

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // 끝말잇기 기록의 길이
    int M; // 후보 단어의 개수
    vector<string> v;
    vector<string> answers;

    int question_index = 0; // "?" 문자열이 담긴 index 번호

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "?") {
            question_index = i;
        }
        v.push_back(input);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        string input;
        cin >> input;

        bool answer = true; // answer가 true면 정답

        // 적합한 답을 검사한다.
        // 1) ? 바로 앞에 있던 문자열의 끝 글자로 시작해야 한다.
        // 2) ? 바로 뒤에 있던 문자열의 첫 글자로 끝나야 한다.
        // 3) 중복된 단어는 허용하지 않는다.
        if (question_index == 0) { // 제일 앞인 경우에는 1),3)만 따진다.
            if (N >= 2) {
                // 1)
                char first_char = v[question_index + 1][0];
                if (input[input.length() - 1] != first_char) answer = false;

                // 3)
                for (int i = 0; i < N; i++) {
                    if (v[i] == input) answer = false;
                }
            }
        }

        else if (question_index == N - 1) { // 제일 뒤인 경우에는 2),3)만 따진다.
            // 2)
            char last_char = v[question_index - 1][v[question_index - 1].length() - 1];
            if (input[0] != last_char) answer = false;

            // 3)
            for (int i = 0; i < N; i++) {
                if (v[i] == input) answer = false;
            }

        }
        else { // 중간에 있는 경우 1),2),3) 모두 따진다.
            // 1)
            char first_char = v[question_index + 1][0];
            if (input[input.length() - 1] != first_char) answer = false;

            // 2)
            char last_char = v[question_index - 1][v[question_index - 1].length() - 1];
            if (input[0] != last_char) answer = false;

            // 3)
            for (int i = 0; i < N; i++) {
                if (v[i] == input) answer = false;
            }
        }

        // 만약 answer == true이면, 정답을 출력한다.
        if (answer == true) {
            answers.push_back(input);
        }
    }

    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}
