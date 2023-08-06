// ���� - ���ڿ� �Ľ� (�迭 �̿�) + ���ڿ� ��

// �����ձ�� �ܾ �ߺ����� �ʰ� �ܾ��� �� �� ���ڿ� �̾ ���ϴ� �����Դϴ�. �����ձ� ����� �ܾ���� ������ �̷�����ϴ�. 
// �ùٸ� �����ձ� ����� �� �ܾ��� ������ ���ڰ� ���� �ܾ��� ù �����̸�, 
// �ܾ �ߺ��Ǿ ��Ÿ���� �� �˴ϴ�.

// �����ձ� ����� �־����µ�, �ϳ��� ����� ��?���� ������ ä�� ���ɴϴ�. 
// ��?���� �� �� �ִ� ���ڿ����� �ĺ��� �־��� ��, �ùٸ� �����ձ� ����� ����� ��?���� �� ���ڿ��� ����ϼ���.

// ------------------------------------ Ǯ�� --------------------------
// ?�� �� �� �ִ� �ܾ� ���� : 
// 1) ? �ٷ� �տ� �ִ� ���ڿ��� �� ���ڷ� �����ؾ� �Ѵ�.
// 2) ? �ٷ� �ڿ� �ִ� ���ڿ��� ù ���ڷ� ������ �Ѵ�.

// ���� ?�� ù ���ڿ��� ���� ���, 2)�� �����ϸ� �ȴ�.
// ���� ?�� �� ���ڿ��� ���� ���, 1)�� �����ϸ� �ȴ�.

// 3) �ߺ��� �ܾ�� ������� �ʴ´�.

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // �����ձ� ����� ����
    int M; // �ĺ� �ܾ��� ����
    vector<string> v;
    vector<string> answers;

    int question_index = 0; // "?" ���ڿ��� ��� index ��ȣ

    // �Է�
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

        bool answer = true; // answer�� true�� ����

        // ������ ���� �˻��Ѵ�.
        // 1) ? �ٷ� �տ� �ִ� ���ڿ��� �� ���ڷ� �����ؾ� �Ѵ�.
        // 2) ? �ٷ� �ڿ� �ִ� ���ڿ��� ù ���ڷ� ������ �Ѵ�.
        // 3) �ߺ��� �ܾ�� ������� �ʴ´�.
        if (question_index == 0) { // ���� ���� ��쿡�� 1),3)�� ������.
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

        else if (question_index == N - 1) { // ���� ���� ��쿡�� 2),3)�� ������.
            // 2)
            char last_char = v[question_index - 1][v[question_index - 1].length() - 1];
            if (input[0] != last_char) answer = false;

            // 3)
            for (int i = 0; i < N; i++) {
                if (v[i] == input) answer = false;
            }

        }
        else { // �߰��� �ִ� ��� 1),2),3) ��� ������.
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

        // ���� answer == true�̸�, ������ ����Ѵ�.
        if (answer == true) {
            answers.push_back(input);
        }
    }

    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}
