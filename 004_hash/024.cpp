﻿/*
문제 024 오픈 채팅방**
링크: https://school.programmers.co.kr/learn/courses/30/lessons/42888
: 카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.
신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다.
채팅방에 누군가 들어오면 다음 메시지가 출력된다.

"[닉네임]님이 들어왔습니다."
채팅방에서 누군가 나가면 다음 메시지가 출력된다.

"[닉네임]님이 나갔습니다."
채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.

채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.
채팅방에서 닉네임을 변경한다.
닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.

예를 들어, 채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.

"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.

"Muzi님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Muzi님이 나갔습니다."

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."
"Prodo님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."

채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 이제, 
채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."
"Ryan님이 들어왔습니다."
"Prodo님이 나갔습니다."
"Prodo님이 들어왔습니다."

채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 
모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

제약 조건
- 모든 유저는 [유저 아이디]로 구분한다.
- [유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")
- [유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")
- [유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")
- 첫 단어는 Enter, Leave, Change 중 하나이다.
- 각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.
- 유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.
- 유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.
- 채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


// 직접 풀이
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> user_ids;
    unordered_map<string, string> um;

    for (int i = 0; i < record.size(); i++)
    {
        istringstream ss(record[i]);
        string word;
        vector<string> words;
        words.reserve(3);


        while (ss >> word)
        {
            words.push_back(word);
        }

        if (words[0] == "Enter")
        {
            user_ids.push_back(words[1]);
            answer.push_back("님이 들어왔습니다.");
            um[words[1]] = words[2];

        }
        else if (words[0] == "Leave")
        {
            user_ids.push_back(words[1]);
            answer.push_back("님이 나갔습니다.");
        }
        else
        {
            um[words[1]] = words[2];
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        answer[i] = um[user_ids[i]] + answer[i];
    }

    return answer;
}


// 해설지 풀이 : 불필요한 user_ids 제거하고, answer 데이터 수정 없이 한 번에 완성
vector<string> solution_commentary(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> uid;

    for (const auto& line : record) {
        //❶ 각 record에 대해서,  cmd에는 명령어를 저장하고  id에는 닉네임을 저장
        stringstream ss(line);
        string cmd, id, nickname;
        ss >> cmd >> id;
        //❷ 명령어가 Enter 혹은 Change일 경우 nickname에 닉네임을 저장
        if (cmd != "Leave") {
            ss >> nickname;
            uid[id] = nickname;
        }
    }

    for (const auto& line : record) {
        stringstream ss(line);
        string cmd, id;
        ss >> cmd >> id;
        //❸ Enter 및 Change 명령어의 경우 최종 닉네임과 정해진 문자열을 answer에 추가
        if (cmd == "Enter") {
            answer.push_back(uid[id] + "님이 들어왔습니다.");
        }
        else if (cmd == "Leave") {
            answer.push_back(uid[id] + "님이 나갔습니다.");
        }
        // "Change"는 메시지 생성에 영향을 주지 않으므로 무시
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
void print(vector<string> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan" }));
    // Prodo님이 들어왔습니다. Ryan님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다.    

    return 0;
}