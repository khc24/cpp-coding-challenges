/* 
���� 008 ��ȣ ¦ ���߱�**
: �Ұ�ȣ�� ¦�� ���� ���� ��ȣ '('�� ���� ��ȣ')'�� �����մϴ�. ���������� ���� ��ȣ�� ���� ��ȣ�� ���� �ڼ��� ���ڿ� s�� �ݴϴ�.
�̶� �Ұ�ȣ�� �������� ���� �������� �Ǻ��ϴ� solution() �Լ��� �����ϼ���. ���� �Ұ�ȣ�� �������� ���� �����ٸ� true��, �׷���
�ʴٸ� false�� ��ȯ�ϸ� �˴ϴ�.

���� ����
- ���� ��ȣ�� �ڽŰ� ���� ����� ���� ��ȣ�� ������ ���
- ��� ��ȣ�� ���Ǿ� �� �̻� �ƹ� ��ȣ�� ����߸� �������� ���� �����ٰ� �� �� �ִ�.
- �� ����� ��ȣ�� ���� ������ ��⸦ �ݺ�
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


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iostream>
int main()
{
    //(true�� ����ϸ� 1 �̰�, false�� ����ϸ� 0�Դϴ�.

    cout << solution("(())()") << endl;  // 1
    cout << solution("((())()") << endl; // 0 

    return 0;
}