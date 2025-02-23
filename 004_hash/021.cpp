﻿/*
영어 끝말잇기*
링크: https://school.programmers.co.kr/learn/courses/30/lessons/12981
: 1부터 n까지 번호가 붙어 있는 n명의 사람이 영어 끝말잇기를 합니다. 영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.
1. 1번부터 번호 순서대로 한 사람씩 단어를 말합니다.
2. 마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작합니다.
3. 앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
4. 이전에 등장했던 단어는 사용할 수 없습니다.
5. 한 글자인 단어는 인정되지 않습니다.

다음은 3명이 끝말잇기를 하는 상황을 나타냅니다.

tank → kick → know → wheel → land → dream → mother → robot → tank

위 끝말잇기는 다음과 같이 진행됩니다.

1번 사람이 자신의 첫 번째 차례에 tank를 말합니다.
2번 사람이 자신의 첫 번째 차례에 kick을 말합니다.
3번 사람이 자신의 첫 번째 차례에 know를 말합니다.
1번 사람이 자신의 두 번째 차례에 wheel을 말합니다.
(계속 진행)
끝말잇기를 계속 진행해 나가다 보면, 3번 사람이 자신의 세 번째 차례에 말한 tank 라는 단어는 이전에 등장했던 단어이므로 탈락하게 됩니다. 사람의 수 n과 
사람들이 순서대로 말한 단어 words 가 매개변수로 주어질 때, 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return 하도록 solution 함수를 완성해주세요.

제약 조건
- 끝말잇기에 참여하는 사람의 수 n은 2 이상 10 이하의 자연수입니다.
- words는 끝말잇기에 사용한 단어들이 순서대로 들어있는 배열이며, 길이는 n 이상 100 이하입니다.
- 단어의 길이는 2 이상 50 이하입니다.
- 모든 단어는 알파벳 소문자로만 이루어져 있습니다.
- 끝말잇기에 사용되는 단어의 뜻(의미)은 신경 쓰지 않으셔도 됩니다.
- 정답은 [ 번호, 차례 ] 형태로 return 해주세요.
- 만약 주어진 단어들로 탈락자가 생기지 않는다면, [0, 0]을 return 해주세요.
*/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


// 직접 풀이
vector<int> solution(int n, vector<string> words) {
	vector<int> answer{ 0, 0 };

	unordered_set<string> save_words;

	save_words.insert(words[0]);

	for (int i = 1; i < words.size(); i++)
	{
		if (words[i - 1].back() != words[i].front())
		{
			answer[0] = i % n + 1;
			answer[1] = i / n + 1;
			break;
		}
		else if (save_words.find(words[i]) == save_words.end())
		{
			save_words.insert(words[i]);
		}
		else
		{

			answer[0] = i % n + 1;
			answer[1] = i / n + 1;
			break;
		}
	}

	return answer;
}


// 해설지 풀이: 중복 검사 + 끝말잇기 규칙을 한 줄에서 검사, return을 바로 사용하여 불필요한 break 제거
vector<int> solution_commentary(int n, vector<string> words) {

	vector<int> answer(2, 0);
	unordered_set<string> usedWords;

	usedWords.insert(words[0]);

	//❶ 두 번째 단어부터 끝까지 반복
	for (int i = 1; i < words.size(); ++i) {
		//❷ 단어가 이미 사용되었거나, 끝말잇기 규칙에 맞지 않는 경우
		if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
			//❸ 플레이어 번호와 턴 번호 저장 후 바로 반환
			answer[0] = i % n + 1;
			answer[1] = i / n + 1;
			return answer;
		}
	}

	//❹ 중간에 탈락하는 플레이어가 없으면 [0, 0] 반환
	return answer;
}



//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" })); // 결과값 : 3 3
	print(solution(5, { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" })); // 결과값 : 0 0
	print(solution(2, { "hello", "one", "even", "never", "now", "world", "draw" })); // 결과값 : 1 3

	return 0;
}