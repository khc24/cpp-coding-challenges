/*
문제 011 짝지어 제거하기*
링크: https://school.programmers.co.kr/learn/courses/30/lessons/12973
: 짝지어 제거하기는, 알파벳 소문자로 이루어진 문자열을 가지고 시작합니다. 먼저 문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾습니다. 
그다음, 그 둘을 제거한 뒤, 앞뒤로 문자열을 이어 붙입니다. 이 과정을 반복해서 문자열을 모두 제거한다면 짝지어 제거하기가 종료됩니다. 
문자열 S가 주어졌을 때, 짝지어 제거하기를 성공적으로 수행할 수 있는지 반환하는 함수를 완성해 주세요. 성공적으로 수행할 수 있으면 1을, 
아닐 경우 0을 리턴해주면 됩니다.
예를 들어, 문자열 S = baabaa 라면

b aa baa → bb aa → aa →

의 순서로 문자열을 모두 제거할 수 있으므로 1을 반환합니다.

제약 조건
- 문자열의 길이 : 1,000,000이하의 자연수
- 문자열은 모두 소문자로 이루어져 있습니다.
*/

#include <stack>
#include <string>

using namespace std;


// 직접 풀이:
int solution(string s)
{
	int n = s.size();
	stack<char> st;

	for (char c : s)
	{
		if (st.empty())
		{
			st.push(c);
		}
		else
		{
			if (st.top() == c)
			{
				st.pop();
			}
			else
			{
				st.push(c);
			}
		}
	}

	int answer = 0;
	if (st.empty()) answer = 1;

	return answer;
}

// 해설지 풀이: 반화 값 처리 최적화(return st.empty(); 사용), 코드 간결화
int solution_commentary(string s)
{
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		//❶스택이 비었거나 현재문자와같은 문자가 아닌 경우 푸시
		if (st.empty() || st.top() != s[i]) st.push(s[i]);
		//❷ 현재문자와 스택의 가장 최근 문자가 같은 경우 팝
		else st.pop();
	}


	//❸ 현재 스택이 비었거나, 문자열의 짝이 맞다는 의미이므로 true반환, 아니면 false 반환
	return st.empty();
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
	cout << solution("baabaa") << endl; // 1
	cout << solution("cdcd") << endl;   // 0 
	return 0;
}