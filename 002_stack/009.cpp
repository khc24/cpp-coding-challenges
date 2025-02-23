 /*
 문제 009 10진수를 2진수로 변환하기*
 : 10진수 decimal을 입력받아 2진수로 변환해서 문자열 형태로 반환하는 solution() 함수를 구현하라.
 */

#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;


// 직접 풀이
string solution(int decimal)
{
    string answer;
    stack<char> st;
    int temp_value;

    while (decimal != 1)
    {
        //cout <<  static_cast<char>(decimal % 2 + '0') << endl;
        st.push(static_cast<char>(decimal % 2 + '0'));
        decimal /= 2;
        //cout << decimal << endl;
    }

    st.push('1');

    while (!st.empty())
    {
        //cout << st.top() << endl;
        answer.push_back(st.top());
        st.pop();
    }

    return answer;
}

// 해설지 풀이: decimal 값이 0인 겨우 처리
string solution_commentary(int decimal) {
    //❶입력 값이  0인 경우 바로 처리
    if (decimal == 0) return "0";

    stack<int> stack;
    while (decimal > 0) {
        //❷ 2로 나눈 나머지를 스택에 삽입
        stack.push(decimal % 2);
        decimal /= 2;
    }

    string binary = "";
    while (!stack.empty()) {
        //❸ 스택에서 차례대로 top()에 해당되는 값을 binary에 추가
        binary += to_string(stack.top());
        stack.pop();
    }
    return binary;
}

//아래 코드는 테스트 코드 입니다.
//#include <iostream>
int main()
{
    cout << solution(10) << endl;       // 1010
    cout << solution(27) << endl;       // 11011 
    cout << solution(12345) << endl;    // 11000000111001 

    return 0;
}