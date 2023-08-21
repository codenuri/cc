#include <iostream>
#include <string>
#include <string_view>	// C++17
						// g++ �ҽ��̸�.cpp -std=c++17 �ʿ�

int main()
{
	std::string s = "to be or not to be";

	// #1. �Ʒ� 2���� �޸� �׸� �˾� �μ���
	std::string      ss1 = s; // ���� ����(���� �����ڿ��� �޸�(���ڿ�) ��ü�� ����)
	std::string_view sv1 = s; // sv1 �� s�� ���ڿ��� ���� ���
							  // "const char* + size(unsigned int)" �Դϴ�.
							  // ũ�Ⱑ ũ�� ���� Ÿ��

	// #2. �Ʒ� 2���� �޸� �׸��� ���� �ϴ°��� �ٽ� �Դϴ�.
	// => "string literal �� ���� �ʱ�ȭ �ϴ� ���"
	std::string      ss2 = "to be or not to be";
						// string �� �����ڰ� �� �޸� �Ҵ���
						// ��� �޸𸮿� �ִ� ���ڿ��� ���޸𸮷� ���� �Ѱ�
						// ��, ss2 �� �ڽŸ��� ���ڿ��� ���� �Ѱ�

	std::string_view sv2 = "to be or not to be"; // ����޸𸮿� �ִ� ���ڿ��� ����Ű�⸸ �Ѱ�
	// const char* p = "to be or not to be";	 // C����� ���ڵ��� �ǹ�.
	// unsigned int size						 // ���ڿ��� ���纻 ���� �ȵ�
}