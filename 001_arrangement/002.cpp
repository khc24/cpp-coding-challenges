/*
���� 002 �迭 �����ϱ�**
: ���� �迭 lst�� �־����ϴ�. �迭�� �ߺ����� �����ϰ� �迭 �����͸� ������������ �����ؼ� ��ȯ�ϴ� solution() �Լ��� �����ϼ���.

���� ����
- lst�� ���̴� 2�̻� 1,000 �����Դϴ�.
- lst�� ��ʼ� ���� -100,000 �̻� 100,000 �����Դϴ�.
*/

#include <vector>
#include <algorithm> // sort, unique�� ���� ����
#include <set>

using namespace std;


vector<int> solution(vector<int> lst)
{
    // ��� 1 �ߺ��� ���� �������� ����, �ߺ� ����, ���� ����, �������� ���� 
    sort(lst.begin(), lst.end());
    lst.erase(unique(lst.begin(), lst.end()),lst.end());
    
    // vector ��ħ���� ���� ��� 1. reverse �Լ�
    reverse(lst.begin(), lst.end());

    // vector ��ħ���� ���� ��� 2. srot()
    sort(lst.begin(), lst.end(), greater<int>());

    // ��� 2 set() �̿��� �ߺ� ����, �������� ����
    set<int, greater<int>> s(lst.begin(), lst.end());
    vector<int> answer(s.begin(), s.end());


    return answer;
}


//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iostream>
#include <iterator>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
  
    print(solution({ 4, 2, 2, 1, 1, 3, 4 })); // 4 3 2 1  
    print(solution({ 2, 1, 1, 3, 2, 5, 4 })); // 5 4 3 2 1

    return 0;
}