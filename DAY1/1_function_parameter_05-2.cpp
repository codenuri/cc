// 1_function_parameter_05-2
#include <iostream>
#include <string>
#include <string_view>

void good(const std::string& s)
{
}



void best(std::string_view s)
{
}



int main()
{
	std::string s = "to be or not to be";

	// �Ʒ��� ���� "const string&" �� ������ �ʽ��ϴ�
	good(s);
	best(s);

	// �׷���, �Ʒ� �ڵ带 ������ ������
	good("to be or not to be");
	best("to be or not to be");
}