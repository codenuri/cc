// R.11: Avoid calling new and delete explicitly
// R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
// E.6: Use RAII to prevent leaks

#include <iostream>
#include <memory>

int main()
{
	// 자원을 아래처럼 할당했는데..
	int* p = new int;				

	// 자원 관리를 위해 메모리 주소를 스마트 포인터에 전달
	std::shared_ptr<int> sp1(p);									
	std::shared_ptr<int> sp2 = sp1;  // ok. 참조 계수는 2 

	std::shared_ptr<int> sp3(p);	// ?? 버그 발생.
									// 한개 자원에 대한 관리 객체가 2개 생성됨
						// 원인 1. 직접 new 를 해서 raw pointer에 담았기 때문
						//      2. 자원 과 관리객체가 따라 할당되기 때문



	// RAII : Resource Acquision Is Initialization
	int* p = new int;				// bad, 진짜 포인터 사용, new 사용
	std::shared_ptr<int> sp1(p);	// bad, raw pointer 로 초기화

	std::shared_ptr<int> sp1(new int);	// 위 코드 보다는 좋지만,
										// 객체와 관리객체라 분리됨.

	std::shared_ptr<int> sp1 = std::make_shared<int>(0);  //ok.. 가장 좋은 코드
							// 자원의 할당은 자원관리(스마트포인터)가 만들어질때!!
}
