#include <iostream>
#include <vector>

// in parameter 
// #4. iterator

// => 대부분의 반복자의 크기는 "포인터 한개 크기" 정도 입니다.
// => 복사 생성자의 오버헤드도 거의 없습니다
// => 즉, 포인터 정도로 생각하면 됩니다.
// "call by value"

// 항상 표준 라이브러리(STL) 은 인자를 어떻게 받을까 를 참고 하세요
// => cppreference.com 에서 std::find() 찾아 보세요

template<typename T>
auto sum(T first, T last) 
{
	typename std::iterator_traits<T>::value_type s{};

	while (first != last)
		s += *first++;

	return s;
}

int main()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	int s = sum(v.begin(), v.end());

	std::cout << s << std::endl; // 5
}