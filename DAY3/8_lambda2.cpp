#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 1. �־��� �������� ù��° ������ "3"�� ã�ƶ�
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 2. �־��� �������� ù��° ������ "3�� ���"�� ã�ƶ� ?
//  auto ret2 = std::find_if(v.begin(), v.end(), �����Լ�);
	auto ret2 = std::find_if(v.begin(), v.end(), foo);

	// 3. �־��� �������� ù��° ������ "k�� ���"�� ã�ƶ� ?
	// => �� foo �� ��� �����ؾ� �ұ�� ?

	int k = 3; // ����ڰ� �Է��� ���̶�� ����!!

	auto ret3 = std::find_if(v.begin(), v.end(), foo);
}