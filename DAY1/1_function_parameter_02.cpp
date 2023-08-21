#include <iostream>
#include <string>

// ��� ����

// 1. in parameter : �Լ� �ȿ��� ���� �б⸸ �ϴ� ���
void f1(int n) { int s = n * n; }

// 2. out parameter : �Լ��ȿ��� ���� ����ִ� �Ķ����
void f2(int& n) { n = 100; }

// 3. in-out parameter 
void f3(int& n) { n = n + 1; }

// 4. forward parameter : ���� ���� ���ڸ� �ٸ� ���� �����ϴ� �Ķ����
template<typename T>
void f4(T&& n) { f2(n); }

// 5. retain(will-from-move) : ���� ���� ���ڸ� "����" �ϰ� �Ǵ� �Ķ� ����.
class People
{
	std::string name;
public:
	void set_name(const std::string& s)
	{
		name = s;
	}
};
