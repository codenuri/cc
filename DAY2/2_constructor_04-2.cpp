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
	Buffer buf{ 1024 };
public:
	// 기반 클래스에 디폴트 생성자가 없으면 파생 클래스에서
	// 기반 클래스 생성자를 명시적으로 호출해야 합니다.
	PipeStream() : Stream( buf  ) {}	

	// 위 코드 문제점 찾아보세요
};

int main()
{
	PipeStream ps;
}




