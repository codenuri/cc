// 1_function_parameter_07-4 => 7번 복사

#include <iostream>
#include <string>

class Person
{
	std::string name;
public:
	// move 를 지원하는 setter 만들기

	// 방법 1. 동일한 이름의 2개의 함수 제공
//	void set_name(const std::string& n) { name = n;	}
//	void set_name(std::string&& n)      { name = std::move(n); }

	
	// 방법 2. T&& 를 사용하면 위 2개 버전을 자동 생성가능합니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것을 찾으세요
	//	name = n;					// 1. 항상 복사 생성자 사용
	//	name = std::move(n);		// 2. 항상 이동 생성자 호출
		name = std::forword<T>(n);	// 3. set_name() 인자로 lvalue 를 보냈는지
									//						rvalue 를 보냈는지에 따라
									//					다른 캐스팅!!!
									// ==> 정답!!
	}

	// 인자가 한개인 setter는 "방법1"이 좋습니다.
	// => STL 내부도 모두 "방법1" 사용
};


int main()
{
	Person p;

	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	p.set_name(s1);		
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; 
}

