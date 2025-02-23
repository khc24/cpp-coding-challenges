/*
문제 010 괄호 회전하기*
링크: https://school.programmers.co.kr/learn/courses/30/lessons/76502
: 다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

- (), [], {} 는 모두 올바른 괄호 문자열입니다.
- 만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, 
([]) 도 올바른 괄호 문자열입니다.
- 만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.

대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 
칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

제약 조건
- s의 길이는 1 이상 1,000 이하입니다.
*/

#include <string>
#include <stack>
#include <iostream>

using namespace std;


// 직접 풀이
int solution(string s)
{
    int answer = 0;
    int n = s.size();
    

    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        bool temp = true;
        for (int j = 0; j < n; j++)
        {
            if (s[(j + i) % n] == ']')
            {
                if (!st.empty())
                {
                    if (st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else
                {
                    temp = false;
                    break;
                }
            }
            else if (s[(j + i) % n] == '}')
            {
                if (!st.empty())
                {
                    if (st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else
                {
                    temp = false;
                    break;
                }
            }
            else if (s[(j + i) % n] == ')')
            {
                if (!st.empty())
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else
                {
                    temp = false;
                    break;
                }
            }
            else
            {

                st.push(s[(j + i) % n]);
            }

        }

        if (temp == true && st.empty())
        {
            answer += 1;
        }
    }

    return answer;
}


// 해설지 풀이: unordered_map 사용하여 if-else 문을 줄이고 가독성 향상
#include <unordered_map>

// ❶ 닫힌 괄호의 짝을 바로 확인할 수 있도록 맵 선언 
unordered_map<char, char> bracketPair = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

//❷현자 인자로 받은 문자열 기준 괄호짝이 맞는지 확인
bool isValid(string& s, int start) {
    stack<char> stk;
    unsigned int  sz = s.size();

    //❸ 문자열을 순회하면서
    for (int i = 0; i < sz; i++) {
        char ch = s[(start + i) % sz];
        //❹ ch가 닫힌 괄호 인경우
        if (bracketPair.count(ch)) {
            // ❺ 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린괄호가 아닌 경우 false 반환
            if (stk.empty() || stk.top() != bracketPair[ch]) return false;
            //❻ ch와 짝이 맞는 열린괄호일경우 해당 열린괄호를 제거
            stk.pop();
        }
        else {
            //❼ 열린 괄호일경우 스택이 푸시
            stk.push(ch);
        }
    }
    //❽스택이 비었으면 true를 반환(비었다는것은 괄호 짝이 맞다는 것을 의미)
    return stk.empty();
}

int solution_commantary(string s) {
    int answer = 0;
    int n = s.size();

    //❾ 문자열을 rotation하면서 괄호짝이 맞으면 answer를 1증가 시킴
    for (int i = 0; i < n; i++) {
        answer += isValid(s, i);
    }
    return answer;
}

// 아래 코드는 테스트 코드 입니다.

int main()
{
    cout << solution_commantary("[](){}") << endl; // 3
    cout << solution_commantary("}]()[{") << endl; // 2 
    cout << solution_commantary("[)(]") << endl;   // 0 
    cout << solution_commantary("}}}") << endl;    // 0   
    return 0;
}