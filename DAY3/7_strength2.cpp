#include <string>
#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	auto ret1 = max1(s1, s2); // ret1 �ᱹ s2�� ���纻 �Դϴ�.

	const std::string& ret2 = max1(s1, s2);
							  // ret2 �� s2�� ���� �Դϴ�.
	//=====================================
	// �� ������ �ٽ� - 2���� ���ڰ� �ӽð�ü(rvalue) �϶�
	// �Ʒ� ó�� �޴� ret3�� �����ұ�� ?
	const std::string& ret3 = max1(std::string("AAA"),
								   std::string("BBB"));

	// ���⼭ ret3�� ����ص� �ɱ�� ?
	// => ���� ����ϸ� �ȵ˴ϴ�
	// => �ӽð�ü�� "������ const &" �� ���ؼ��� ���� ������ �˴ϴ�.
	// cppreference.com ���� "std::max" ã�� ������. 
	// => �Լ� ���(����, ��ȯŸ��) ����, �߰��뿡 Note ������
}



