#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};


class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//===================================
// Stream 의 모든 기능을 물려 받아서 Pipe 통신을 하는 클래스!!
class PipeStream : public Stream
{
	Buffer buf{ 1024 }; // 여기에 초기화 코드를 만들어도
						// 컴파일러에 의해서, 초기화 리스트 위치로 옮겨 놓게 됩니다.
public:
	// 기반 클래스에 디폴트 생성자가 없으면 파생 클래스에서
	// 기반 클래스 생성자를 명시적으로 호출해야 합니다.
	PipeStream() : Stream( buf ) {}

	// 위 코드 문제점 찾아보세요
	// 1. Stream 의 생성자가 먼저 호출, 초기화되지 않은 buf 사용
	// 2. buf 초기화!!!!
	 
	// 핵심 : 기반 클래스의 파생 클래스 멤버를 되도록이면 보내지 마세요(아직 초기화전!!)
};

int main()
{
	PipeStream ps;
}




