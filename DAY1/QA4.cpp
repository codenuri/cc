#include <iostream>

class Object
{
public:
	Object() {}

	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&)      { std::cout << "move" << std::endl; }
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o1);
}
