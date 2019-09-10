#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char* addBinary(char* a, char* b)
{
	char *c = NULL;//字符串指针，malloc内存
	int size_a = strlen(a);
	int size_b = strlen(b);
	int size_max = size_a > size_b ? size_a : size_b;
	int size_min = size_a < size_b ? size_a : size_b;
	int i;
	int j;
	char *a_ptr;
	char *b_ptr;
	char *c_ptr;
	int flag=0;//flag用来标记进位

	c = (char *)malloc(sizeof(char) * size_max + 2*sizeof(char));//动态内存
	*(c + size_max) = 0;//给c的最后两个字节赋结束符\0（一个用来接让字符串边长的进位，一个用来存放结束符）
	*(c + size_max+1) = 0;

	a_ptr = a + size_a - 1;//a_ptr指向a最后一个元素
	b_ptr = b + size_b - 1;//b_ptr指向b最后一个元素
	c_ptr = c + size_max - 1;//c_ptr指向c最后一个元素

//	printf("*a_ptr=%c\n", *a_ptr);
//	printf("*b_ptr=%c\n", *b_ptr);
	//对齐输出
	if (size_a < size_b)
	{
		for (i = 0; i < abs(size_a - size_b); i++)
		{
			printf(" ");
		}
		puts(a);
		puts(b);
	}
	else
	{
		puts(a);
		for (i = 0; i < abs(size_a - size_b); i++)
		{
			printf(" ");
		}
		puts(b);
	}
	
	//复制较长字符串，便于让差值保持原状
	if (size_a > size_b)
	{
		for (i = 0; i < size_a; i++)
		{
			*(c + i) = *(a + i);
		}
	}
	else
	{
		for (i = 0; i < size_b; i++)
		{
			*(c + i) = *(b + i);
		}
	}
//相加
	for (i = 0; i < size_min; i++)
	{
		*c_ptr = *a_ptr + *b_ptr;
		a_ptr--;
		b_ptr--;
		c_ptr--;
	}
	c_ptr = c + size_max - 1;//指针归位
	//去掉字符导致的ascii重复运算
	for (i = 0; i < size_min; i++)
	{
		*c_ptr = *c_ptr -48;
		c_ptr--;
	}
	c_ptr = c + size_max - 1;//指针归位
	//进位
	flag = 0;//注意flag是int
	for (i = 0; i < size_max; i++)
	{
		*c_ptr = *c_ptr + flag;
		if (*c_ptr == '3')
		{
			flag = 1;
			*c_ptr = '1';
			c_ptr--;
		}
		else if (*c_ptr == '2')
		{
			flag = 1;
			*c_ptr = '0';
			c_ptr--;
		}
		else if (*c_ptr == '1')
		{
			flag = 0;
			*c_ptr = '1';
			c_ptr--;
		}
		else if (*c_ptr == '0')
		{
			flag = 0;
			*c_ptr = '0';
			c_ptr--;
		}
	}
	//如果循环结束后flag=1，说明还有进位，应在最前面添加1
	if (flag == 1)
	{
		c_ptr = c + size_max;//指针指向最后一个字节
		for (i = 0; i < size_max; i++)
		{
			*c_ptr = *(c_ptr - 1);//后移一位
			c_ptr--;
		}
		*(c_ptr + 0) = '1';
	}
	return c;
}
int main()
{
	char *c;
	c=addBinary("1010", "1011");
	printf("结果：\n");
	puts(c);
}

