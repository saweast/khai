// pr1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//частина 1
	//ініціалізуємо декілька змінних
	int q = 5,
		w = 10,
		e = 15;
	double a = 1.25,
		s = 2.5,
		d = 5;
	char z = 'a';
	//пишемо декілька виразів
	q++;
	q--;
	q += w + e - q;
	q -= w + e - q;
	a *= d * q / s;
	a /= (q >> 1) + (w << 3);
	e++;
	e--;
	a = (a < d) ? s : d;
	q %= e;
	q &= e;
	q ^= e;
	q |= e;
	sizeof(a);
	//частина 2
	d = 0;
	s = 0;
	for (int i = -64; i <= 64; i++) {
		d = (((i << 3) + (i << 1)) | i) ^ i;
		((int)d & 0x110) != 0 ? s += d : s += 0;
	}
	return 0;
}

