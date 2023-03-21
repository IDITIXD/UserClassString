#include <iostream>
using namespace std;
#include <cctype>
class STROKA
{     							//характеристики
	char* str; 	//адрес динамической строки
	int N;		//длина строки
	char ch; 	//символ
public:						//методы
	STROKA();			//пустая строка
	~STROKA(); 			//деструктор 
	friend  void COP(STROKA& ob);   	//дружественная функция
	void show();//метод вывода
};
STROKA::STROKA()
{
	str = new char[N];
	cin >> str;
	N = strlen(str);
};
STROKA::~STROKA()
{ };

void STROKA::show()//метод вывода
{
	for (int i = 0; i < N; i++) cout << str[i];
};

void COP(STROKA& ob)//дружественная функция
{
	int n = 0;
	for (int i = 0; i < strlen(ob.str); i++) {
		if (ob.str[i] > '9' || ob.str[i] < '0') {
			ob.str[n] = ob.str[i];
			n++;
		};
	};
	ob.N = n;
};

int main()
{
	setlocale(LC_ALL, NULL);
	STROKA STROK;
	cout << "direct" << "\n" << "\n";
	COP(STROK);
	STROK.show();
	cout << "\n" << "\n" << "indirect" << "\n" << "\n";
	STROKA* p_STROK;
	p_STROK = &STROK;
	p_STROK->show();
}

