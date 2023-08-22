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

int main()
{
	// 아래 2줄은 아무 문제 없습니다.
	Buffer buff(1024);		// 버퍼를 만들어서
	Stream stream(buff);	// Stream 생성자에서 사용
}




