#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
double exp() {
	char s[20];
	cin >> s;
	switch(s[0]) {
		case '+':
			return exp() + exp(); //递归调用，求出自身包含的波兰式
		case '-':
			return exp() - exp();
		case '*':
			return exp() * exp();
		case '/':
			return exp() / exp();
		default:
			return atof(s); //将char转换成对应的浮点数
			break;
	}
}
int main() {
	printf("%lf",exp());
	return 0;
}