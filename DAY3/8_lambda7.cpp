// conversion function pointer
class CompilerGeneratedName
{
public:


};



int main()
{
	int(*f1)(int, int) = CompilerGeneratedName();






	// 람다 표현식은 함수 포인터에 담아도 됩니다.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx(); 
						// 임시객체


}