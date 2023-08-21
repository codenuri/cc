#include <iostream>
#include <vector>
#include <span> // C++20.  g++ 소스.cpp -std=c++20

// std::string_view : "문자(char)"타입의 연속된 메모리에 대한 "view"
// std::span	    : "임의타입(T)"의    연속된 메모리에 대한 "view"

// vector 
// 인자로 전달된 vector 를 읽기만 하려고 합니다.
//void foo( std::vector<int> v ) // worst
//void foo(const std::vector<int>& v) // best, until C++17,
void foo(std::span<int> sp)  // C++20 부터는 이코드가 best
{
	int n = sp[0];
	std::cout << sp.size() << std::endl; // 
}

int main()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	foo(v);

	int x[5]{ 1,2,3,4,5 };
	foo(x); // ??
}