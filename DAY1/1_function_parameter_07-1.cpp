#include <iostream>
#include <vector>


int main()
{
	std::vector<std::string> v;

	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	// vector �� push_back �� �ᱹ, ���ڷ� ���� ���� ���� 
	// ����(retain) �ϰ� �˴ϴ�. 
	// move�� �����ϱ� ���� push_back �Լ��� ������ 2�� �ֽ��ϴ�.
	v.push_back(s1);
	v.push_back(std::move(s2));

	// push_back ���� ���콺 ������ ��ư�� ������, 
	// "����"�� �̵��ؼ�
	// push_back() �Լ��� 2�� �ִ°� Ȯ���� ������.

}