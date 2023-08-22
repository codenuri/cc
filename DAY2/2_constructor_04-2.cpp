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
// Stream �� ��� ����� ���� �޾Ƽ� Pipe ����� �ϴ� Ŭ����!!
class PipeStream : public Stream
{
	Buffer buf{ 1024 };
public:
	// ��� Ŭ������ ����Ʈ �����ڰ� ������ �Ļ� Ŭ��������
	// ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� �մϴ�.
	PipeStream() : Stream( buf  ) {}	

	// �� �ڵ� ������ ã�ƺ�����
};

int main()
{
	PipeStream ps;
}




