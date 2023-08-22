// 3_explicit1-1
#include <string>
#include <vector>

void f1(std::string s) {}
void f2(std::vector<int> v) {}

int main()
{
	// 아래 2줄의 코드는 되는게 좋은지 안되는 것이 좋은지 생각해 보세요
	f1("hello");
	f2(10);
}