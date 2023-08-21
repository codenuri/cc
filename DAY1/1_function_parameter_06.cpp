#include <iostream>
#include <vector>

// in parameter 
// #4. iterator

// => ��κ��� �ݺ����� ũ��� "������ �Ѱ� ũ��" ���� �Դϴ�.
// => ���� �������� ������嵵 ���� �����ϴ�
// => ��, ������ ������ �����ϸ� �˴ϴ�.
// "call by value"

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