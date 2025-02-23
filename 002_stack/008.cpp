/* 
문제 008 괄호 짝 맞추기**
: 소괄호는 짝을 맞춘 열린 괄호 '('와 닫힌 괄호')'로 구성합니다. 문제에서는 열린 괄호나 닫힌 괄호가 마구 뒤섞인 문자열 s를 줍니다.
이때 소괄호가 정상으로 열고 닫혔는지 판별하는 solution() 함수를 구현하세요. 만약 소괄호가 정상적을 열고 닫혔다면 true를, 그렇지
않다면 false를 반환하면 됩니다.

제약 조건
- 열린 괄호는 자신과 가장 가까운 닫힌 괄호를 만나면 상쇄
- 모든 괄호가 상쇄되어 더 이상 아무 괄호도 없어야만 정상으로 열고 닫혔다고 할 수 있다.
- 더 상쇄할 괄호가 없을 때까지 상쇄를 반복
*/

#include <string>
#include <stack>

using namespace std;


bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (char c : s)
    {
        if (c == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                
            }
            else
            {
                answer = false;
                return answer;
            }

        }
        else
        {
            st.push(c);
        }
    }

    return st.empty();
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>
int main()
{
    //(true를 출력하면 1 이고, false를 출력하면 0입니다.

    cout << solution("(())()") << endl;  // 1
    cout << solution("((())()") << endl; // 0 

    return 0;
}