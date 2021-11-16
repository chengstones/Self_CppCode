#include <iostream>
#include <climits>
using namespace std;

/*
signed char is 1 bytes.
signed int is 4 bytes.
signed short is 2 bytes.
signed long is 4 bytes.
signed long long is 8 bytes.

Maxinum values and Mininum values:
signed char : -128 -- 127
signed int : 2147483647 -- -2147483648
signed short : -32768 -- 32767
signed long : -2147483648 -- 2147483647
signed long long : -9223372036854775808 -- 9223372036854775807
*/

int main(void)
{
	cout << "signed char is " << sizeof(char) << " bytes." << endl;
	cout << "signed int is " << sizeof(int) << " bytes." << endl;
	cout << "signed short is " << sizeof(short) << " bytes." << endl;
	cout << "signed long is " << sizeof(long) << " bytes." << endl;
	cout << "signed long long is " << sizeof(long long) << " bytes." << endl << endl;

        //下面宏都是climits头文件中所定义，可打开改头文件观察
	cout << "Maxinum values and Mininum values: " << endl;
	cout << "signed char : " << SCHAR_MIN << " -- " << SCHAR_MAX << endl;
	cout << "signed int : " << INT_MAX << " -- "<< INT_MIN <<  endl;
	cout << "signed short : " << SHRT_MIN << " -- " << SHRT_MAX << endl;
	cout << "signed long : " << LONG_MIN << " -- " << LONG_MAX << endl;
	cout << "signed long long : " << LLONG_MIN << " -- " << LLONG_MAX << endl;
	return 0;
}

