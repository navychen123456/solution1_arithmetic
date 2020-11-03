#include <stdio.h>
#include <Windows.h>
#include "add.h"
#include "sub.h"
//除法调用动态实现
#include "div.h"

float div(float x, float y, int *z)
{
	if (y == 0)
	{
		*z = 0;
		return 0;
	}
	else
	{
		return x / y;
	}

}

float get_multi(float x, float y)
{
	HMODULE hmod = LoadLibrary("multiplication.dll");
	typedef float(*LoadProc)(float a, float b);
	LoadProc Load_proc = (LoadProc)GetProcAddress(hmod, "multi");
	return Load_proc(x, y);
}

int main()
{
	float a, b;
	int d = 1;
	int *c=NULL;
	c = &d;
	scanf("%f%f", &a, &b);
	printf("a+b= %.3f\n", add(a, b));
	printf("a-b= %.3f\n", sub(a, b));
	//
	float iRet = get_multi(a, b);
	printf("a*b= %.3f\n", iRet);

	if (div(a, b, c)==0 && *c==0)
		printf("除数不能为0\n");
	else
	{
		printf("a/b= %.3f\n", div(a, b, c));
	}

	system("pause");

	return 0;
}