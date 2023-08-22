#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	~Buffer() { delete[] buff; }

	void useBuffer() { std::cout << "���� ���" << std::endl; }
};


class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//===================================
// ��� ����Ÿ�� �����ڸ� ��� Ŭ���� ���� ���� ȣ���ϰ� �Ϸ���!!!

// ��� ����Ÿ�� ���� ��� Ŭ������ ���弼��
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




