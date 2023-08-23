#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0;	// "data=0" 의 초기화는 결국 컴파일러가 생성자로 옮기게 됩니다.
					// 따라서, 이코드 때문에 생성자가 trivial 하지 않게됩니다.
public:
	//	virtual void foo() {} // 가상함수가 있으면 생성자가 하는일이 있음

//	Test() {}	      // 사용자가 생성자를 제공하면 trivial 이 아닙니다.

	Test() = default; // 컴파일러가 만들면 trivial 이 될수 있습니다.
					  // (단, 다른 조건도 만족해야)
};

int main()
{
	// trivial 여부를 조사하는 방법
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << std::boolalpha << b << std::endl;
}