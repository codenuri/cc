#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Person
{
	std::string name;
	std::string address;
	std::array<int, 32> data;
public:
	// 주의 1. 아래 함수는 인자로 전달받은 것을 멤버에 보관(retain)
	//         하지 않고, 함수 내부적으로만 사용 합니다.
	//         "in parameter" 입니다.
	//		   string_view 가 최선, 
	//         C++17 이전이면 const std::string& 만 만들면 됩니다.
	//		   move 생각하지 마세요.
//	void print_msg(const std::string& msg)
	void print_msg(std::string_view msg)  // C++17 이후 최선 
	{
		std::cout << msg << std::endl;
	}

	// 주의 2. retain 이 되더라도, move 의 효과가 없는 타입은 move를 고려하지 마세요
	// => primitive type
	// => 자원을 힙에 할당하지 않는 타입들..
	// => std::array 등.
	void set_data(const std::array<int, 32>& d)
	{
		// 아래 코드는 분명히 멤버에 보관(retain) 하지만
		// const std::array 는 move 효과 없습니다.		
		data = d;
	}
	// move 버전 의 setter 를 지원할 필요 없습니다.
	// 아래 코드는 만드지 마세요
	void set_data(std::array<int, 32>&& d)
	{
		data = std::move(d);
	}
};

// int n1 = 10;
// int n2 = std::move(n1); // 에러는 아니지만,
						// move 효과는 전혀 없습니다.
						// int n2 = n1 과 완전히 동일
// Point p1(1, 2);
// Point p2 = std::move(p1); // move 효과 없습니다.


int main()
{
	Person p;

	std::string s = "to be or no to be";
	std::array<int, 32> arr = { 0 };

	p.print_msg(s);
	p.set_data(arr);
}