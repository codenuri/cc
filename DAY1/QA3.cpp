// QA3
#include <string>
#include <iostream>

// ������ gcc������ std::string ���翡 ���� copy on write�� ����
// => C++98 ����
// => C++11���� ����Ǿ����ϴ�.

// C++98
// 1. ���ڿ��� �׻� ���� ����

// C++11
// 1. ���̰� ���� ���ڿ��� ��ü ��ü(����)�� ����
//    => ���̰� ��(���� 16��) �̻��� ���ڿ��� ���� ����

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "to be or not to be";

	std::cout << &s1 << std::endl;				// ��ü �ּ�
	std::cout << (void*)s1.data() << std::endl;	// ���ڿ� ���� �ּ�

	std::cout << &s2 << std::endl;				// ���� �޸� �ּ�
	std::cout << (void*)s2.data() << std::endl;	// �� �޸� �ּ�

	//-------------------------
	std::string s3 = s2; // C++98. reference counting, copy on write 
						 //        ��, ���ڿ� ���� ��� ���
						 // C++11. ���� ����, ���ڿ� ��ü�� ���ο� �޸𸮷� ����

	std::cout << (void*)s2.data() << std::endl;
	std::cout << (void*)s3.data() << std::endl;
}




