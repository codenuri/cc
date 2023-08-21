#include <iostream>
#include <vector>
#include <span> // C++20.  g++ �ҽ�.cpp -std=c++20

// std::string_view : "����(char)"Ÿ���� ���ӵ� �޸𸮿� ���� "view"
// std::span	    : "����Ÿ��(T)"��    ���ӵ� �޸𸮿� ���� "view"

// vector 
// ���ڷ� ���޵� vector �� �б⸸ �Ϸ��� �մϴ�.
//void foo( std::vector<int> v ) // worst
//void foo(const std::vector<int>& v) // best, until C++17,
void foo(std::span<int> sp)  // C++20 ���ʹ� ���ڵ尡 best
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