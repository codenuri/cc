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
	Buffer buf{ 1024 }; // ���⿡ �ʱ�ȭ �ڵ带 ����
						// �����Ϸ��� ���ؼ�, �ʱ�ȭ ����Ʈ ��ġ�� �Ű� ���� �˴ϴ�.
public:
	// ��� Ŭ������ ����Ʈ �����ڰ� ������ �Ļ� Ŭ��������
	// ��� Ŭ���� �����ڸ� ��������� ȣ���ؾ� �մϴ�.
	PipeStream() : Stream( buf ) {}

	// �� �ڵ� ������ ã�ƺ�����
	// 1. Stream �� �����ڰ� ���� ȣ��, �ʱ�ȭ���� ���� buf ���
	// 2. buf �ʱ�ȭ!!!!
	 
	// �ٽ� : ��� Ŭ������ �Ļ� Ŭ���� ����� �ǵ����̸� ������ ������(���� �ʱ�ȭ��!!)
};

int main()
{
	PipeStream ps;
}




