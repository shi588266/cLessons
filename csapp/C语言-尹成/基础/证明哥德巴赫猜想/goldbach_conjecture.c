/**
 * 哥德巴赫猜想:任何大于4的偶数都能拆分成两个质数之和
 */
#include<stdio.h>
typedef unsigned long long int ull;
/**
 * 判断一个数数是否是质数
 * 返回值:0代表非质数,1代表质数
 */
int isPrime(ull a) {
	if (a <= 2)
	{
		return 1;
	} else {
		int i;
		for (i = 2; i < a; ++i)
		{
			// 质数只能被1和它自身整除
			if (a%i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}

/**
 * 测试是否是质数
 * @param argc [description]
 * @param argv [description]
 */
void main1(int argc, char const *argv[])
{
	/* code */
	int a;
	printf("请输入一个正整数\n");
	scanf("%lld", &a);
	int test = isPrime(a);
	if (test == 0)
	{
		printf("%lld不是质数\n", a);
	} else {
		printf("%lld是质数\n", a);
	}
}


/**
 * 判断是否是偶数
 */
int isEven(ull a) {
	if (a%2 == 0)
	{
		return 1;
	} else {
		return 0;
	}
}

/**
 * 测试是否是偶数
 * @param argc [description]
 * @param argv [description]
 */
void main2(int argc, char const *argv[])
{
	/* code */
	int a;
	printf("请输入一个正整数\n");
	scanf("%lld", &a);
	int test = isEven(a);
	if (test == 0)
	{
		printf("%lld不是偶数\n", a);
	} else {
		printf("%lld是偶数\n", a);
	}
}


/**
 * 给定一个大于4的偶数拆分成两个质数之和
 */
int getPrime(ull a) {
	if (a <= 4)
	{
		printf("请输入大于4的数\n");
		return 0;
	}
	if (!isEven(a))
	{
		printf("请输入偶数\n");
		return 0;
	}
	int i;
	for (i = 0; i < a; ++i)
	{
		if (isPrime(i) && isPrime(a-i))
		{
			printf("%lld=%lld+%lld\n", a, i, a-i);
			return 1;
		}
	}
	
}

/**
 * 测试
 * @param argc [description]
 * @param argv [description]
 */
void main(int argc, char const *argv[])
{
	int a;
	while (1) {
		printf("请输入一个大于4正整数\n");
		scanf("%lld", &a);
		int res = getPrime(a);
		if (res)
		{
			break;
		}
	}
	
}