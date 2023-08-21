#include <iostream>
#include <string>

// retain-parameter 
// => ���ڷ� ���� ���� ���� �ٽ� "��� ����Ÿ�� ����" �ϴ� ���.

// 1. �ᱹ ���ڿ��� ��ü ���������� "����" �ϰ� �˴ϴ�.
// => string_view ������� �ʰ�, const std::string& ����ϸ� �˴ϴ�.

// 2. std::move() �� ���޵Ǵ� �͵� �����ϴ� ���� �����ϴ�.

class Person
{
	std::string name;
public:
//	void set_name(const std::string& n) { name = n; } // �� �ڵ�� �׻� "����"
//	void set_name(const std::string& n) { name = std::move(n); } 
											// �� �ڵ嵵 �׻� "����"
											// ��� ��ü�� "�̵� �ɼ� ����" ��� Ư¡
											 
	// �ٽ� : ���ڸ� retain �ϴ� �Լ��� ���� "2��"�� ����� ���� �����ϴ�.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	Person p;

	std::string s = "to be or not to be";

	p.set_name(s);		// s�� ���ڿ��� ������ ����� �ǵ�
						// s�� ��� ��밡��

	p.set_name(std::move(s));	// s�� �ڿ��� �̵��� ����� �ǵ�
								// ��, s�� �ڿ� �ս��ϰ� �� �̻� ����Ҽ� ����
								// �޸� ���簡 �����Ƿ� ������.

}