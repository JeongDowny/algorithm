#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<char> bracket;
    vector<string> input;
    bool isEqual = true;

    while (true) { // 온점이 입력될 떄까지 getline으로 입력받기
        getline(cin, str);
        if (str == ".")
            break;
        input.push_back(str);
    }

    for (int i = 0; i < input.size(); i++) { // 입력된 줄의 수만큼 반복
        str = input[i];
        for (int j = 0; j < str.length(); j++) { // 줄의 길이만큼 반복
            if (str[j] == '(' || str[j] == '[') { // 입력이 (, [ 이면 stack에 push
                bracket.push(str[j]);
            } else if (str[j] == ')' || str[j] == ']') {
                if (!bracket.empty()) { // 입력이 ), ] 이고 bracket이 비어 있지 않으면 top 값과 비교, 쌍을 이루면 pop, 아니면 불균형
                    if (str[j] == ')' && bracket.top() == '(')
                        bracket.pop();
                    else if (str[j] == ']' && bracket.top() == '[')
                        bracket.pop();
                    else
                        isEqual = false;
                } else // 입력이 ), ] 이고 bracket이 비어 있으면 불균형
                    isEqual = false;
            }
        }
        if (bracket.empty() && isEqual) { // bracket 이 비어 있고 isEqual이면 yes 출력
            cout << "yes" << endl;
        } else { // bracket이 비어있지 않거나 isEqual이 아니면 no 출력, bracket 초기화
            cout << "no" << endl;
            while (!bracket.empty())
                bracket.pop();
            isEqual = true;
        }
    }
    return 0;
}