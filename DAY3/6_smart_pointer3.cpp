// R.11: Avoid calling new and delete explicitly
// R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
// E.6: Use RAII to prevent leaks

#include <iostream>
#include <memory>

int main()
{
	// 자원을 아래처럼 할당했는데..
	int* p = new int;				

	std::shared_ptr<int> sp1(p);									
	std::shared_ptr<int> sp2 = sp1;  
	std::shared_ptr<int> sp3(p);  

	// RAII : Resource Acquision Is Initialization
	int* p = new int;				
	std::shared_ptr<int> sp1(p);	

	std::shared_ptr<int> sp1(new int);	

	std::shared_ptr<int> sp1 = std::make_shared<int>(0); 
}
