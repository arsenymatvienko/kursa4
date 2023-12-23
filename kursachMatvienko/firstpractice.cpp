#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main1()
{
	SetConsoleCP(CP_UTF8); // Setting the input encoding
    SetConsoleOutputCP(CP_UTF8); // Setting the output encoding
	for (; ; )
	{
		setlocale(LC_ALL, "RU");
		HANDLE COLOR = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(COLOR, 15);

		cout << "Введите номер задания:\n";
		cout << "1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.\n";
		cout << "2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.\n";
		cout << "3) Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.\n";

		int vvod;
		cin >> vvod;

		if (vvod == 1) {
			cout
				<< "int: " << sizeof(int) << '\n' <<
				"short int: " << sizeof(short int) << '\n' <<
				"float: " << sizeof(float) << '\n' <<
				"double: " << sizeof(double) << '\n' <<
				"long double: " << sizeof(long double) << '\n' <<
				"char: " << sizeof(char) << '\n' <<
				"bool: " << sizeof(bool) << '\n';
			_getch();


		}

		if (vvod == 2) {
			cout << "Введите целое число\n";
			int a;
			cin >> a;
			int order = sizeof(int) * 8 - 1;
			int mask = 1 << order;
			for (int i = 0; i <= order; i++) {
				cout << ((a & mask) ? 1 : 0);
				mask = mask >> 1;
				if (!i || (i + 1) % 8 == 0)
				{
					cout << ' ';
				}
			}
			// идз
			cout << "\n" << "Введите на сколько сдвинуть биты вправо\n";
			int n;
			cin >> n;
			a >>= n;
			order = sizeof(int) * 8 - 1;
			mask = 1 << order;
			for (int i = 0; i <= order; i++) {
				cout << ((a & mask) ? 1 : 0);
				mask = mask >> 1;
				if (!i || (i + 1) % 8 == 0) {
					cout << ' ';
				}
			}
			_getch();
		}

		if (vvod == 3) {
			cout << "Введите целое число\n";
			int a;
			cin >> a;
			int order = sizeof(int) * 8 - 1;
			int mask = 1 << order;
			for (int i = 0; i <= order; i++) {
				cout << ((a & mask) ? 1 : 0);
				mask = mask >> 1;
				if (!i || (i + 1) % 8 == 0)
				{
					cout << ' ';
				}
			}
			union {
				int integerA = 127;
				float floatB;
			};
			cout << "\n";
			// идз
			cout << "\n" << "Введите на сколько сдвинуть биты вправо\n";
			int n;
			cin >> n;
			a >>= n;
			order = sizeof(int) * 8 - 1;
			mask = 1 << order;
			for (int i = 0; i <= order; i++) {
				cout << ((a & mask) ? 1 : 0);
				mask = mask >> 1;
				if (!i || (i + 1) % 8 == 0) {
					cout << ' ';
				}
			}
			_getch();

		}

		if (vvod >= 4) {
			HANDLE COLOR = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(COLOR, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Доступно только три задания!!!\n";
			_getch();

		}

	}
	_getch();

}
