/*
문제 007 방문 길이**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/49994
: 게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

	U: 위쪽으로 한 칸 가기
	D: 아래쪽으로 한 칸 가기
	R: 오른쪽으로 한 칸 가기
	L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.
예를 들어, "ULURRDLLU"로 명령했다면 1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.
8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다. 이때, 우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다. 
예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)
단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.예를 들어, "LULLLLLLU"로 명령했다면 1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다. 
다시 9번 명령어대로 움직입니다. 이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. 명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를
구하여 return 하는 solution 함수를 완성해 주세요.
*/

#include <vector>
#include <string>
#include <set>

using namespace std;


int solution(string dirs)
{
	pair<int, int> pos(0, 0);

	// 초기 set 저장 타입을 vector로 하여 동적 메모리 사용하며 pair<int, int> 보다 메모리 사용량 증가
	//set<vector<int>> s;

	set<pair<pair<int, int>, pair<int, int>>> s;

	for (char dir : dirs)
	{
		switch (dir)
		{
			case 'U':
			{
				if (pos.second < 5)
				{
					
					s.insert({ { pos.first, pos.second + 1 }, { pos.first, pos.second } });
					pos.second++;
				}
			} break;
			case 'D':
			{
				if (pos.second > -5)
				{
					s.insert({ { pos.first, pos.second	}, { pos.first, pos.second - 1} });
					pos.second--;
				}
			} break;
			case 'L':
			{
				if (pos.first > -5)
				{
					s.insert({ { pos.first, pos.second	}, { pos.first - 1, pos.second} });
					pos.first--;
				}
			} break;
			case 'R':
			{
				if (pos.first < 5)
				{
					s.insert({ { pos.first + 1, pos.second	}, { pos.first, pos.second} });
					pos.first++;
				}
			} break;
		}
	}
	return s.size();
}


//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
	cout << solution("ULURRDLLU") << endl; // 7
	cout << solution("LULLLLLLU") << endl; // 7 

	return 0;
}