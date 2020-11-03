#include <stdio.h>
#include <Windows.h>
#include "add.h"
#include "sub.h"
//�������ö�̬ʵ��
#include "div.h"

float div(float x, float y)
{
		return x / y;
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

	if (b == 0)
	{
		printf("��������Ϊ0\n");
		return 0;
	}
	else
	{
		printf("a/b= %.3f\n", div(a, b));
	}

	system("pause");

	return 0;
}