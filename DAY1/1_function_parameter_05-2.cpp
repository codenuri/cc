// 1_function_parameter_05-2
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t sz)
{
	printf("new : %d\n", sz);
	return malloc(sz);
}

void good(const std::string& s)
{
}
// string_view : 크기가 작고, 복사 생성자가 하는일이 없습니다.
// => 복사의 오버헤드가 거의 없습니다.
// => primitive 타입 처럼 call by value 가 좋습니다.
void best(std::string_view s)
{
}



int main()
{
	std::string s = "to be or not to be";

	// 아래의 경우는 "const string&" 도 나쁘지 않습니다
//	good(s);
//	best(s);

	// 그런데, 아래 코드를 생각해 보세요
	std::cout << "==================" << std::endl;

	good("to be or not to be"); // 이순간 std::string 의 임시객체를 생성하게됩니다.
								// string 의 생성자가 "문자열을 힙에 복사"하게 됩니다.
								// 임시객체를 good() 에서 참조로 받게 됩니다.
//	best("to be or not to be"); // 임시객체 없습니다.
								// string_view 가 상수 메모리의 문자열을 직접 가르키게 됩니다.
}