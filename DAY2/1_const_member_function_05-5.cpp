// 1_const_member_function_05-5
#include <vector>

int main()
{
	// ���� �̸��� const, non-const ��� �Լ��� ���ÿ� �����ϴ� ����
	// ���� ���� �ֽ��ϴ�.
	      std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	auto p1 = v1.begin();		// p1 �� std::vector<int>::iterator
	auto p2 = v2.begin();		// p2 �� std::vector<int>::const_iterator

	// �Ʒ� 2���� ������ ������
	*p1 = 10; // ok
	*p2 = 10; // error.
}