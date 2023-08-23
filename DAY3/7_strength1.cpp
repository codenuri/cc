// F.4: If a function might have to be evaluated at compile time, declare it constexpr
//
// F.5: If a function is very small and time - critical, declare it inline

// [[nodiscard]] : ���� ���� �����ϸ� ��� �߻��� �޶�. C++17

template<typename T>
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
// �Լ��� ����ð��� �߿��ϸ� inline ���� ������.
template<typename T>
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
// �Լ��� ������ �ð��� ���갡���ϰ� �Ϸ��� constexpr �� �ٿ���!
template<typename T>
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	int ret1 = max1(1, 2); // ����ð��� �Լ� ȣ��
						   // call max1

	int ret2 = max2(1, 2); // max2�� ���� �ڵ带 �̰��� ġȯ
						   // mov eax, 1
						   // add eax, 2
						   // mov ret2, eax

	constexpr int ret3 = max3(1, 2); // "1+2" �� ������ �ð��� ����
									 // mov ret3, 3

	int ret4 = max3(1, 2); // ������ �Ҷ� ��������, ����ð������� �����Ϸ��� ���� �ٸ�
						   // ��κ� ������ �ð�
}



