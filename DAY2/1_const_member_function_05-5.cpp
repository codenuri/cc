// 1_const_member_function_05-5
#include <vector>

int main()
{
	// ���� �̸��� const, non-const ��� �Լ��� ���ÿ� �����ϴ� ����
	// ���� ���� �ֽ��ϴ�.

	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	auto p1 = v1.begin();
	auto p2 = v2.begin();

	// �Ʒ� 2���� ������ ������
	*p1 = 10;
	*p2 = 10;
}