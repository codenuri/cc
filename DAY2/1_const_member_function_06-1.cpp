// 1_const_member_functin_06-1

// explicit object parameter 문법을 만든 이유
// 1. deducing this!!
// 2. 그외 다양한 장점이 있습니다.
class Test
{
public:
	// C++98 ~ C++20 스타일
	void f1()       {} // void f1(Test* this) 
	void f1() const {} // void f1(const Test* this) 

	// C++23 새로운 문법으로 위 코드처럼 2개 만들기!
	// => 핵심 : const 키워드가 함수 () 뒤가 아닌, 함수 인자로 놓이게 됩니다.
	void f2(this Test&       self) {}
	void f2(this const Test& self) {}

	// 핵심 : const 가 인자에 포함되게 되었습니다.
	// => template 을 사용하면 위 2개 함수가 자동 생성됩니다
	template<typename T>
	void f3(this T& self) {}
};

int main()
{
	Test t;
	const Test ct;

	t.f3();		// f3(this Test&)       즉, f3() 생성
	ct.f3();    // f3(this const Test&) 즉, f3() const 생성

}