// pr2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdarg.h"

int sumaDiap(int a, int b) {
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += i;
	}
	return sum;
}
long dobDiap(int a, int b) {
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum *= i;
	}
	return sum;
}
long double fact(int N)
{
	if (N < 0) // ���� ������������ ���� ������������� �����
		return 0; // ���������� ����
	if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
	else // �� ���� ��������� �������
		return N * fact(N - 1); // ������ ��������.
}
long double zadSix(int a, int b){
	double y = 0, sum = 0;
	for (int x = a; x <= b; x++) {
		y = (((x << 3) + (x << 1)) | x) ^ x;
		((int)y & 0x110) != 0 ? sum += y: sum += 0;
	}
	return sum;
}
int Sum(int first, ...){
	va_list ptr;
	// ��������� ����� �������� �� ���������
	va_start(ptr, first);
	// �������� ����� �������� �� ���������
	int
		sum = 0;
	for
		(;
	first;
	// ����� ������ [ ����� ��������� �� ������� ����
	first = va_arg(ptr, int))
		// �������� �������� ��������
	{
		sum += first;
		// ������ ���� �� ����
	}
	// ������� ����� �������� �� ���������
	va_end(ptr);
	// ��������� ���������
	return sum;
}
#define MAX(a, b) ((a) > (b))
int _tmain(int argc, _TCHAR* argv[])
{
	sumaDiap(10, 100);
	dobDiap(10, 100);
	fact(5);
	zadSix(10, 100);
	int a = 100,
		b = 200,
		c = 250;
	double z = 0.5,
		v = 0.25;
	c = MAX(a + b, c);
#if c == (a + b)
	return z;
#elif a == (c - b)
	return v;
#endif
	return 0;
}

