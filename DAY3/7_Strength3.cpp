#include <string>
#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// STL �� ���� ��ӹ޴� ���� ���� �ʽ��ϴ�. ���������� ������� ������
// ����, �׽�Ʈ��
class String : public std::string
{
public:
	using std::string::basic_string; // ������ ���

	~String() { std::cout << "~String" << std::endl; }
};

int main()
{
	const String& ret3 = max1(String("AAA"),String("BBB"));

	std::cout << "-------------" << std::endl;
}



