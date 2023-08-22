#include <string>

class People1
{
	std::string name;
	int age;
public:
	People1(const std::string& s, int a) : name(s), age(a)  // good
	{	
	}
};

class People2
{
	std::string name;
	int age;
public:
	People2(const std::string& s, int a)	
	{										
		name = s;	// bad  
		age = a;
	}
};



int main()
{
	std::string s = "john";
	People1 p1(s, 20);
	People2 p2(s, 20);

	//-------------------------
	// 초기화 vs 대입
	// primitive type 인 경우는 대부분 유사.
	// user define type 의 경우는 초기화가 빠릅니다.

	int a = 0;	// 초기화, 선언과 동시에 값 넣기

	int b;
	b = 0;		// 대입. 선언후에 넣는 것


	std::string s1 = "hello";	// std::string s1("hello")
								// 즉, 인자가 한개인 생성자 호출 1회로 초기화

	std::string s2;	// 1. string 디폴트 생성자 호출
	s2 = "hello";	// 2. s2.operator=("hello"). 즉, 대입 연산자 호출
					// => 2회의 함수 호출로 값을 넣은 것
}