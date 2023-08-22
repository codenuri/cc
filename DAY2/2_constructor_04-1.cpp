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
public:
	PipeStream() {}	// PipeStream() : Stream() {} <= 컴파일러가 이렇게 변경했는데
												// Stream 에 디폴트생성자가 없다
};


int main()
{
	PipeStream ps;
}




