#include <iostream>
#include <tuple>

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// C++ ǥ�ؿ� "convenient function template" �� ����ϴ� �ڵ��
	// ����� ���� �ֽ��ϴ�.
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4); // t2�� ���� t1�� ���� �մϴ�

}