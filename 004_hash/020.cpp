/*
���� 020 �������� ���� ����*
��ũ: https://school.programmers.co.kr/learn/courses/30/lessons/42576
: ���� ���� �� �� �� ���� ������ �����ϰ� ��� ������ �������� �����Ͽ����ϴ�. �����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ���
�迭 completion�� ���� �� �Ϥ������� ���� ������ �̸��� ��ȯ�ϴ� solution() �Լ��� �ۼ��ϼ���.

���� ����
- ������ ��⿡ ������ ���� ���� 1�� �̻� 100,000�� �����Դϴ�.
- completion ���̴� participant ���̺��� 1 �۽��ϴ�.
- ������ �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
- ������ �߿��� ���������� ���� �� �ֽ��ϴ�.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hash;

    for (string s : participant)
    {
        if (hash.find(s) == hash.end())
        {
            hash[s] = 1;
        }
        else
        {
            hash[s] += 1;
        }
    }

    for (string s : completion)
    {
        hash[s] -= 1;
    }

    for (const auto& s : hash)
    {
        if (s.second == 1)
            answer = s.first;
    }


    return answer;
}


#include <iostream>

int main()
{
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl; // "leo"
    cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl; // "vinko"
    cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl; // "mislav"
    return 0;

}