/*
문제 020 완주하지 못한 선수*
링크: https://school.programmers.co.kr/learn/courses/30/lessons/42576
: 많은 선수 중 단 한 명의 선수를 제외하고 모든 선수가 마라톤을 완주하였습니다. 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴
배열 completion이 있을 때 완ㅇ주하지 못한 선수의 이름을 반환하는 solution() 함수를 작성하세요.

제약 조건
- 마라톤 경기에 참여한 선수 수는 1명 이상 100,000명 이하입니다.
- completion 길이는 participant 길이보다 1 작습니다.
- 참가자 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
- 참가자 중에는 동명이인이 있을 수 있습니다.
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