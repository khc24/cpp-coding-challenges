/*
���� 007 �湮 ����**
��ũ: https://school.programmers.co.kr/learn/courses/30/lessons/49994
: ���� ĳ���͸� 4���� ��ɾ ���� �����̷� �մϴ�. ��ɾ�� ������ �����ϴ�.

	U: �������� �� ĭ ����
	D: �Ʒ������� �� ĭ ����
	R: ���������� �� ĭ ����
	L: �������� �� ĭ ����

ĳ���ʹ� ��ǥ����� (0, 0) ��ġ���� �����մϴ�. ��ǥ����� ���� ���� ��(-5, 5), ���� �Ʒ�(-5, -5), ������ ��(5, 5), ������ �Ʒ�(5, -5)�� �̷���� �ֽ��ϴ�.
���� ���, "ULURRDLLU"�� ����ߴٸ� 1�� ��ɾ���� 7�� ��ɾ���� ������ ���� �����Դϴ�.
8�� ��ɾ���� 9�� ��ɾ���� ������ ���� �����Դϴ�. �̶�, �츮�� ���� ĳ���Ͱ� ������ �� �� ĳ���Ͱ� ó�� �ɾ ���� ���̸� ���Ϸ��� �մϴ�. 
���� ��� ���� ���ÿ��� ���� ĳ���Ͱ� ������ ���̴� 9������, ĳ���Ͱ� ó�� �ɾ ���� ���̴� 7�� �˴ϴ�. (8, 9�� ��ɾ�� ������ ���� 2, 3�� ��ɾ�� �̹� ���� �� ���Դϴ�)
��, ��ǥ����� ��踦 �Ѿ�� ��ɾ�� �����մϴ�.���� ���, "LULLLLLLU"�� ����ߴٸ� 1�� ��ɾ���� 6�� ��ɾ��� ������ ��, 7, 8�� ��ɾ�� �����մϴ�. 
�ٽ� 9�� ��ɾ��� �����Դϴ�. �̶� ĳ���Ͱ� ó�� �ɾ ���� ���̴� 7�� �˴ϴ�. ��ɾ �Ű����� dirs�� �־��� ��, ���� ĳ���Ͱ� ó�� �ɾ ���� ���̸�
���Ͽ� return �ϴ� solution �Լ��� �ϼ��� �ּ���.
*/

#include <vector>
#include <string>
#include <set>

using namespace std;


int solution(string dirs)
{
	pair<int, int> pos(0, 0);

	// �ʱ� set ���� Ÿ���� vector�� �Ͽ� ���� �޸� ����ϸ� pair<int, int> ���� �޸� ��뷮 ����
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


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iostream>

int main()
{
	cout << solution("ULURRDLLU") << endl; // 7
	cout << solution("LULLLLLLU") << endl; // 7 

	return 0;
}