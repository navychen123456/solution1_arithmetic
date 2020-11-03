#include <stdio.h>
#include <Windows.h>
#include "add.h"
#include "sub.h"
//除法调用动态实现
#include "div.h"

void div(float x, float y)
{
	if (y == 0)
	{
		printf("除数不能为0\n");
	}
	else
	{
		printf("a/b= %.3f\n", x / y);
	}

}

int main()
{
	float a, b;
	scanf("%f%f", &a, &b);
	printf("a+b= %.3f\n", add(a, b));
	printf("a-b= %.3f\n", sub(a, b));
	//
	HMODULE hmod = LoadLibrary("multiplication.dll");
	typedef float(*LoadProc)(float x, float y);
	LoadProc Load_proc = (LoadProc)GetProcAddress(hmod, "multi");
	float iRet = Load_proc(a, b);
	printf("a*b= %.3f\n", iRet);

	div(a, b);

	system("pause");

	return 0;
}