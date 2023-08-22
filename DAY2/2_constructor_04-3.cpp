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
// 멤버 데이타의 생성자를 기반 클래스 보다 먼저 호출하게 하려면!!!

// 멤버 데이타를 위한 기반 클래스를 만드세요
class PipeBuffer
{
protected:
	Buffer buf{ 1024 }; 
};

class PipeStream : public PipeBuffer, public Stream
{
public:
	PipeStream() : Stream(buf) {}

};

int main()
{
	PipeStream ps;
}




