#include <string>

class People1
{
	std::string name;
	int age;
public:
	// �Ʒ� �ڵ��
	// 1. string name(s) �� �ʱ�ȭ �Ȱ�. 
	// => ��, 1ȸ�� �Լ� ȣ��
	People1(const std::string& s, int a) : name(s), age(a)  // good
	{	
	}
};

class People2
{
	std::string name;
	int age;
public:	
	// �Ʒ� �ڵ�� 
	// 1. string name �� ���ؼ� ����Ʈ ������ ȣ����
	// 2. name.operator=(s) �� ���� ������
	// ��, 2ȸ�� �Լ� ȣ��
										 // �����Ϸ��� �߰��� �ڵ�
	People2(const std::string& s, int a) //	: name()  <= name�� ����Ʈ ������ȣ��
	{										
		name = s;	// bad  
		age = a;
	}
};

// People2 p2(�̸�,2); // �̼����� ������ ȣ���� ������ ���ô�.
	


int main()
{
	std::string s = "john";
	People1 p1(s, 20);
	People2 p2(s, 20);

	//-------------------------
	// �ʱ�ȭ vs ����
	// primitive type �� ���� ��κ� ����.
	// user define type �� ���� �ʱ�ȭ�� �����ϴ�.
	/*
	int a = 0;	// �ʱ�ȭ, ����� ���ÿ� �� �ֱ�

	int b;
	b = 0;		// ����. �����Ŀ� �ִ� ��


	std::string s1 = "hello";	// std::string s1("hello")
								// ��, ���ڰ� �Ѱ��� ������ ȣ�� 1ȸ�� �ʱ�ȭ

	std::string s2;	// 1. string ����Ʈ ������ ȣ��
	s2 = "hello";	// 2. s2.operator=("hello"). ��, ���� ������ ȣ��
					// => 2ȸ�� �Լ� ȣ��� ���� ���� ��
	*/
}