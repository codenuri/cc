// 1_function_parameter_05-2
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t sz)
{
	printf("new : %d\n", sz);
	return malloc(sz);
}

void good(const std::string& s)
{
}
// string_view : ũ�Ⱑ �۰�, ���� �����ڰ� �ϴ����� �����ϴ�.
// => ������ ������尡 ���� �����ϴ�.
// => primitive Ÿ�� ó�� call by value �� �����ϴ�.
void best(std::string_view s)
{
}



int main()
{
	std::string s = "to be or not to be";

	// �Ʒ��� ���� "const string&" �� ������ �ʽ��ϴ�
//	good(s);
//	best(s);

	// �׷���, �Ʒ� �ڵ带 ������ ������
	std::cout << "==================" << std::endl;

	good("to be or not to be"); // �̼��� std::string �� �ӽð�ü�� �����ϰԵ˴ϴ�.
								// string �� �����ڰ� "���ڿ��� ���� ����"�ϰ� �˴ϴ�.
								// �ӽð�ü�� good() ���� ������ �ް� �˴ϴ�.
//	best("to be or not to be"); // �ӽð�ü �����ϴ�.
								// string_view �� ��� �޸��� ���ڿ��� ���� ����Ű�� �˴ϴ�.
}