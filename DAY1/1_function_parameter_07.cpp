#include <iostream>
#include <string>

// retain-parameter 
// => 인자로 전달 받은 것을 다시 "멤버 데이타에 보관" 하는 경우.

// 1. 결국 문자열을 객체 내부적으로 "보관" 하게 됩니다.
// => string_view 사용하지 않고, const std::string& 사용하면 됩니다.

// 2. std::move() 로 전달되는 것도 지원하는 것이 좋습니다.

class Person
{
	std::string name;
public:
//	void set_name(const std::string& n) { name = n; } // 이 코드는 항상 "복사"
//	void set_name(const std::string& n) { name = std::move(n); } 
											// 이 코드도 항상 "복사"
											// 상수 객체는 "이동 될수 없다" 라는 특징
											 
	// 핵심 : 인자를 retain 하는 함수의 경우는 "2개"를 만드는 것이 좋습니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	Person p;

	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	p.set_name(s1);		// s의 문자열을 복사해 가라는 의도
						// s는 계속 사용가능

	p.set_name(std::move(s2));	// s의 자원을 이동해 가라는 의도
								// 즉, s는 자원 손실하고 더 이상 사용할수 없다
								// 메모리 복사가 없으므로 빠르다.
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}