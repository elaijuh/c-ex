#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	printf("size of char: %lu\n", sizeof(char));
	printf("range of char: %d-%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("size of unsigned char: %lu\n", sizeof(unsigned char));
	printf("range of unsigned char: %d-%d\n", 0, UCHAR_MAX);
	printf("size of short: %lu\n", sizeof(short));
	printf("range of short: %d-%d\n", SHRT_MIN, SHRT_MAX);
	printf("size of unsigned short: %lu\n", sizeof(unsigned short));
	printf("range of unsigned short: %d-%d\n", 0, USHRT_MAX);
	printf("size of int: %lu\n", sizeof(int));
	printf("range of int: %d-%d\n", INT_MIN, INT_MAX);
	printf("size of unsigned int: %lu\n", sizeof(unsigned int));
	printf("range of unsigned int: %d-%ud\n", 0u, UINT_MAX);
	printf("size of long: %lu\n", sizeof(long));
	printf("range of long: %ld-%ld\n", LONG_MIN, LONG_MAX);
	printf("size of unsigned long: %lu\n", sizeof(unsigned long));
	printf("range of unsigned long: %lu-%lu\n", 0ul, ULONG_MAX);
	printf("size of long long: %lu\n", sizeof(long long));
	printf("range of long long: %lld-%lld\n", LLONG_MIN, LLONG_MAX);
	printf("size of unsigned long long: %lu\n", sizeof(unsigned long long));
	printf("range of unsigned long long: %llu-%llu\n", 0ull, ULLONG_MAX);
	printf("size of float: %lu\n", sizeof(float));
	printf("size of double: %lu\n", sizeof(double));
	printf("size of long double: %lu\n", sizeof(long double));

	return 0;
}
