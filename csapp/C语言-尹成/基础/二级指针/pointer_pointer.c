#include <stdio.h>
double db1 = 3.00;
double db2 = 3.1415;


/**
 * 如果想要通过改变形参达到让实参也改变的目的,形参y也可以传递指针的地址,
 * 然后通过改变指针里地址的指向来改变实参
 * 这种方式改变的是指针的指向,让指针指向了变量db2的地址
 */
void changepp(double **pp) {
	*pp = &db2;
}
//这种方式改变的是指针指向的变量, 指针指向的仍旧是变量db1的地址, 但是变量db1的值变了
void changeppval(double **pp) {
	**pp = db2;
}

/**
 * 如果想要通过改变形参达到让实参也改变的目的,形参可以传递数据的地址(指针),
 * 然后通过改变指针指向的值来改变实参
 */
void changep(double *pp) {
	*pp = db2;
}


//函数的形式参数除了数组意外都会,传入的任何数据都会新建一个变量接收传入的值
void change(double *p) {
	p = &db2; // 这里的p与传入的p在内存中不是同一个地址	
}

void main(int argc, char const *argv[])
{
	double *p = &db1;
	printf("db1=%f\n", *p);		//db1=3.000000 
	change(p);
	printf("*=%f\n", *p);		//db1=3.000000 

	changep(p);
	printf("*=%f\n", *p);		//db1=3.141500 

	/**
	 * **pp是二级指针, 指向指针p的地址
	 * *pp = p 		对二级指针用※就得到指针p的地址,就是一个16进制常量
	 * **p = *p 	对二级指针用※※就得到指针p指向的变量值
	 */
	double **pp = &p;
	changepp(pp);
	printf("*p=%f\n", *p);		//db1=3.141500 
	changeppval(pp);
	printf("*p=%f\n", *p);		//db1=3.141500 
	printf("db1=%f\n", db1);		//db1=3.141500 
}