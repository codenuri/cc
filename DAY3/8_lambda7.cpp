// conversion function pointer
class CompilerGeneratedName
{
public:
	auto operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 위해서 컴파일러가 만드는 클래스에는 아래 멤버가 
	// 있습니다.
	using F = int(*)(int, int);

//	operator F() { return &CompilerGeneratedName::operator(); }
					// => error
					// => 멤버 함수는 "this"가 추가되는 함수 입니다.
					// => 따라서 일반 함수 포인터에 멤버 함수 주소 담을수 없습니다

	// 함수 포인터로의 변환을 위해서 "operator()" 와 동일한 일을 하는 
	// static 멤버 함수가 필요
	static auto helper(int a, int b) { return a + b; }

	operator F() { return &CompilerGeneratedName::helper; }
};


int main()
{
	int(*f1)(int, int) = CompilerGeneratedName();
						// 임시객체.operator 함수포인터타입()




	// 람다 표현식은 함수 포인터에 담아도 됩니다.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx(); 
						// 임시객체


}