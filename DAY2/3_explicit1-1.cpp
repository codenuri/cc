// 3_explicit1-1
#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> v) {}

int main()
{
	// �Ʒ� 2���� �ڵ�� �Ǵ°� ������ �ȵǴ� ���� ������ ������ ������
	f1("hello"); // �Ǵ°� �����ϴ�. ok. 
	f2(10);		 // �ȵǴ°� �����ϴ�. error

	// �ǹ�
	// string �� �����ڴ� explicit �� �ƴմϴ�.
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok

	// vector(int) �����ڴ� explicit ��� �ǹ�
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error.
}