#include <cstdio>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

#define SIZE 3
int main() {

	mt19937 gen(time(0));
	uniform_int_distribution<> uid(1, 3);
	uniform_int_distribution<> uid2(1, 9);
	long long n = SIZE;

	long long array[n][n];
	long long result[n][n];
	long long result_2[n-1][n-1];

	long long x = uid(gen); //столбец
	cout << "columns: " << x << endl;
	long long y = uid(gen); //строка
	cout << "row: " << y << endl;

	cout << "\narray:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = uid2(gen);
			cout<<array[i][j]<<" ";
		}
		cout<<"\n";
	}


	long long *ptr_array = &array[0][0];
	long long *ptr_result = &result[0][0];
	long long *ptr_result_2 = &result_2[0][0];

	__asm__(
			"push %%rbx"				"\n\t"
			"push %%rsp"				"\n\t"
			"push %%rbp"				"\n\t"
			//инициализация указателей регистры
			"mov %[ptr_array], %%rsi" 	"\n\t" // A
			"mov %[ptr_result], %%rdi" 	"\n\t" // B

			"mov $0, %%rcx"				"\n\t" // 0
			"mov %[n], %%rax"			"\n\t" // n = 3
			"mov %[n], %%rcx"			"\n\t" // n = 3
			"mul %%rax"					"\n\t" // n = 9
			"sub %%rcx, %%rax"			"\n\t"
			"mov %%rax, %%rcx" 			"\n\t" // n = 6
			"push %%rcx"				"\n\t"


			"mov $0, %%rbx"				"\n\t"
			"mov %[y], %%rbx"			"\n\t" // rbx = 2

			"LOOPERY:" 					"\n\t"

			"cmp $1, %%rbx"				"\n\t" // 1 = rbx то переход
			"jne SWAPFUNC"				"\n\t"
			"mov %[n], %%rax"			"\n\t" // rax = 3
			"movq $8, %%rdx"			"\n\t"
			"mul %%rdx"					"\n\t"
			"add %%rax, %%rsi"			"\n\t" // смешение rsi = 4 + 3

			"SWAPFUNC:" 				"\n\t"
			"push %%rcx"				"\n\t"
			"movq %[n], %%rcx"			"\n\t" //"mov %[n], %%rcx"
			"SWAP3:"					"\n\t"
			"mov (%%rsi),%%rax"			"\n\t" // замена
			"mov %%rax,(%%rdi)"			"\n\t"
			"add $8, %%rdi"				"\n\t"
			"add $8, %%rsi"				"\n\t"
			"loop SWAP3"				"\n\t"

			"pop %%rcx"					"\n\t"
			"dec %%rbx"					"\n\t"
			"loop LOOPERY"				"\n\t"

			//теперь ||||||||||||||||||

			"mov %[ptr_result], %%rsi" 	"\n\t" // A
			"mov %[ptr_result_2], %%rdi" "\n\t" // B
			"mov %[x], %%rcx"			"\n\t" // rcx = 2
			"dec %%rcx"					"\n\t"
			"mov %%rcx, %%rbx"			"\n\t"
			"cmp $0, %%rbx"				"\n\t"
			"je AFTER"					"\n\t"

			"SWAPFIRST:"				"\n\t"
			"mov (%%rsi),%%rax"			"\n\t"
			"mov %%rax,(%%rdi)"			"\n\t"
			"add $8, %%rdi"				"\n\t"
			"add $8, %%rsi"				"\n\t"
			"loop SWAPFIRST"			"\n\t"
			"AFTER:"					"\n\t"

			"movq $0, %%rax"			"\n\t"
			"mov %[n], %%rax"			"\n\t" // n = 3
			"mov %[n], %%rcx"			"\n\t" // n = 3
			"mul %%rax"					"\n\t" // n = 9
			"sub %%rcx, %%rax"			"\n\t"
			"mov %[x], %%rcx"			"\n\t" // rcx = 2
			"dec %%rcx"					"\n\t"
			"sub %%rcx, %%rax"			"\n\t"
			"mov %%rax, %%rcx" 			"\n\t" // n = 5
			"dec %%rcx"					"\n\t" // n = 4

			"LOOPERX:" 					"\n\t" //второй цикл (по x)
			"movq $0, %%rax"			"\n\t"
			"movq $8, %%rax"			"\n\t"
			"add %%rax, %%rsi"			"\n\t"

			"push %%rcx"				"\n\t"

			"movq $2, %%rcx"			"\n\t" // переписать
			"SWAP2:"					"\n\t"
			"mov (%%rsi),%%rax"			"\n\t"
			"mov %%rax,(%%rdi)"			"\n\t"
			"add $8, %%rdi"				"\n\t"
			"add $8, %%rsi"				"\n\t"
			"loop SWAP2"				"\n\t"

			"pop %%rcx"					"\n\t"
			"dec %%rbx"					"\n\t"
			"loop LOOPERX"				"\n\t"

			"pop %%rbx"					"\n\t"
			"end_asm:" 					"\n\t"
			: // выходные параметры
			:[ptr_array]"m"(ptr_array),[ptr_result]"m"(ptr_result),[n]"m"(n),[y]"m"(y),[x]"m"(x),[ptr_result_2]"m"(ptr_result_2) // входные параметры
			:"%rax", "%rbx", "%rcx"	// разрушаемые регистры
	);

	cout<<"\nresult:\n";
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
			cout<<result_2[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
