// 3_explicit1-1
#include <string>
#include <vector>

void f1(std::string s) {}
void f2(std::vector<int> v) {}

int main()
{
	// �Ʒ� 2���� �ڵ�� �Ǵ°� ������ �ȵǴ� ���� ������ ������ ������
	f1("hello");
	f2(10);
}