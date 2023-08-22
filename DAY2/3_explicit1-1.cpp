// 3_explicit1-1
#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> v) {}

int main()
{
	// 아래 2줄의 코드는 되는게 좋은지 안되는 것이 좋은지 생각해 보세요
	f1("hello"); // 되는게 좋습니다. ok. 
	f2(10);		 // 안되는게 좋습니다. error

	// 의미
	// string 의 생성자는 explicit 가 아닙니다.
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok

	// vector(int) 생성자는 explicit 라는 의미
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error.
}