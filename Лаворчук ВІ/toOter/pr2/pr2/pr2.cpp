// pr2.cpp: определяет точку входа для консольного приложения.
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
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return N * fact(N - 1); // делаем рекурсию.
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
	// створюємо змінну покажчик на аргументи
	va_start(ptr, first);
	// ініціюємо змінну покажчик на аргументи
	int
		sum = 0;
	for
		(;
	first;
	// умова виходу [ поява аргументу що дорівнюжє нулю
	first = va_arg(ptr, int))
		// отримуємо наступне значення
	{
		sum += first;
		// додаємо його до суми
	}
	// очищуємо змінну покажчик на аргументи
	va_end(ptr);
	// повертаємо результат
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

