
// Con.1 : By default, make objects immutable => ���!
// Con.2 : By default, make member functions const => �ٽ� !!
// Con.3 : By default, pass pointers and references to consts

int main()
{
	// max �� �б⸸ �Ѵٸ�
//	int max = 10;		// bad.  ���� ���ٴ� 
//	const int max = 10; // good. ����� �����ϴ�.
	constexpr int max = 10; // good. �ʱⰪ�� ������ �ð��� �˼� �ִٸ�
							// const ���ٴ� constexpr ����

	// ���� ���� ����� ����
	// 1. ��Ƽ �����忡 ����
	// 2. �����Ϸ� ����ȭ�� �ξ� �ߵ˴ϴ�
	// 3. ����� �迭�̳� ���ø� ���ڷε� ��밡�� �մϴ�.
	int arr[max];

	// ���� ����, ����� �����ϴ�.
	// �׷���, C/C++ ����Ʈ�� ����!
	int n1 = 0;       // R/W ����
	const int n2 = 0; // R

	// �Լ������, Rust ���� ����Ʈ�� ����Դϴ�.
	// Rust �ڵ�
//	let n1 = 0;     // R
//	let mut n2 = 0; // R/W
}









// github.com/codenuri/cc ����

// DAY2.zip �����ø� �˴ϴ�.

// ����Ǯ��, vs ����, ���� ����


