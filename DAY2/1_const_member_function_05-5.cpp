// 1_const_member_function_05-5
#include <vector>

int main()
{
	// 동일 이름의 const, non-const 멤버 함수를 동시에 제공하는 경우는
	// 아주 많이 있습니다.
	      std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	auto p1 = v1.begin();		// p1 은 std::vector<int>::iterator
	auto p2 = v2.begin();		// p2 은 std::vector<int>::const_iterator

	// 아래 2줄을 생각해 보세요
	*p1 = 10; // ok
	*p2 = 10; // error.
}