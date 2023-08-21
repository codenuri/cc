#include <iostream>
#include <string>

// in-parameter 
// #3. std::string 

// call by value
// => string ��ü ��ü�� ����ǰ�
// => string �� ���� �����ڿ��� ���ڿ��� ����
void f1(std::string s) // worst
{
}

// call by const reference
// good ������, C++17 ���ʹ� "best" �� �ƴմϴ�.
void f2(const std::string& s)
{
}

int main()
{
	std::string s = "to be or not to be";

	f1(s);
	f2(s);
}