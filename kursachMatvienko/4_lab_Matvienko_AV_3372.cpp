// привет! как  дЕла? чТО  дЕЛаЛ сЕгОдНя? я оТДЫхал.

//привет! как  дЕла???? сегоднЯ я уВИДЕЛ, чТо ВеРхушки    дерЕвЬев шевЕЛИлись, вот  это   да!!!! ИзгИБаЛись в   стОрону дОРоги,,,,, точно  кЛанялись отъезжающим. 

#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


unsigned getStrLen(char* S)
{
    unsigned L = 0;
    while (S[L]) ++L;
    return L;
}

int main4()
{
	SetConsoleCP(CP_UTF8); // Setting the input encoding
    SetConsoleOutputCP(CP_UTF8); // Setting the output encoding

    char vvod[1000];
    char dot[2] = ".";
    cout << "Введите строку" << endl;
    cin.getline(vvod, 1000, '.');
    strcat(vvod, dot);
    vector<char> vvodVector;

    string str;
    str = vvod;
    int len = str.size();
    bool flag = false;
    for (int i = 0; i < len; i++)
    {
        if ((vvod[i + 1] == ' ' || (vvod[i] == ',' || vvod[i] == '?' || vvod[i] == ',' || vvod[i] == ':' || vvod[i] == '!' || vvod[i] == ';' || vvod[i] == '-' || vvod[i] == ')' || vvod[i] == '(')) && flag == true)
        {
            continue;
        }
        if ((vvod[i + 1] == ' ' || (vvod[i] == ',' || vvod[i] == '?' || vvod[i] == ',' || vvod[i] == ':' || vvod[i] == '!' || vvod[i] == ';' || vvod[i] == '-' || vvod[i] == ')' || vvod[i] == '(')) && flag == false)
        {
            vvodVector.push_back(vvod[i]);
            flag = true;
        }
        else
        {
            vvodVector.push_back(vvod[i]);
            flag = false;
        }
    }
    for (int i = 0; i < vvodVector.size(); i++)
    {
        if (vvodVector[i] >= 'А' && vvodVector[i] <= 'Я')
        {

            vvodVector[i] += 'я' - 'Я';
        }
    }
    vvodVector[0] = vvodVector[0] - 32;
    for (int i = 2; i < vvodVector.size(); i++)
    {
        if (vvodVector[i - 2] == '!' || vvodVector[i - 2] == '?')
        {
            vvodVector[i] = vvodVector[i] - 32;
        }
    }

    int choose = 0;
    while (choose != -1)
    {
        cout << "\nВыберите задание:\n\n";
        cout << "1)    С клавиатуры или с файла (*) (пользователь сам может выбрать способ ввода) вводится последовательность, \nсодержащая от 1 до 50 слов, в каждом из которых от 1 до 10 строчных латинских букв и цифр. \nМежду соседними словами произвольное количество пробелов. За последним символом стоит точка.\n\n"
            << "2)    Необходимо отредактировать входной текст: \n\t·        удалить лишние пробелы; \n\t·        удалить лишние знаки препинания(под «лишними» подразумевается несколько подряд идущих знаков \n\t«…» - корректное использование знака в тексте); \n\t·        исправить регистр букв, если это требуется(пример некорректного использования регистра букв : пРиМЕр);\n\n"
            << "3) Вывести на экран только те слова последовательности, в которых первая буква слова встречается в этом слове еще раз.(5)\n\n"
            << "4) Вывести на экран ту же последовательность, удалив из всех слов заданный набор букв и (или) цифр.(3)\n"
            << "5) Необходимо найти все подстроки, которую введёт пользователь в имеющейся строке. Линейный поиск.\n";
        int input;
        cin >> input;
        switch (input)
        {
        case 1:
        {
            string str;
            str = vvod;
            cout << "\nВы ввели: " << vvod << "\n" << endl;
            cout << "Длина строки - " << str.size() << endl;
            break;
        }
        case 2:
        {
            for (int i = 0; i < vvodVector.size(); i++)
            {
                cout << vvodVector[i];
            }
            break;
        }
        case 3:
        {
            vector<char> vvodVectorDownReg = vvodVector;
            for (int i = 0; i < vvodVector.size(); i++)
            {
                if (vvodVector[i] >= 'А' && vvodVector[i] <= 'Я')
                {

                    vvodVectorDownReg[i] += 'я' - 'Я';
                }
            }
            char words[1000];
            char str[2];
            int count = 0;
            string word = "";
            for (char x : vvodVectorDownReg)
            {
                if (x == ' ')
                {
                    //cout << word << endl;
                    word = "";
                    count++;
                }
                else
                {
                    word = word + x;
                }
            }
            //cout << count;

            char vvodClean[1000];
            for (int i = 0; i < vvodVector.size(); i++)
            {
                vvodClean[i] = vvodVectorDownReg[i];
                //cout << vvodClean[i];
            }

            string line = vvodClean;
            int wordsCount = count;
            string arr[1000];
            int i = 0;
            stringstream ssin(line);
            while (ssin.good() && i < wordsCount)
            {
                ssin >> arr[i];
                i++;
            }
            cout << "Элементы, в которых первая буква повторяется несколько раз:\n";
            for (i = 0; i < wordsCount; i++)
            {
                bool f = false;
                for (int j = 0; arr[i][j] != '\0' ; j++)
                {
                    if (arr[i][0] == arr[i][j+ 1])
                    {
                        f = true;
                    }
                }
                if (f == true)
                {
                    cout << arr[i] << " ";
                }
                //cout << arr[i];
            }
            cout << endl;
            break;
        }
        case 4:
        {
            

            cout << "Введите подстроку:\n";
            char supString[100];
            vector<char> vvodVector4;
            cin >> supString;
            cout << "Строка без введенной подстроки:\n";
            int counter = 0;
            int test = 0;
            for (int i = 0; i < len; i++)
            {
                bool flag = false;
                counter = 0;
                for (int j = 0; supString[j] != '\0'; j++)
                {
                    vvodVector4.push_back(vvod[i]);

                    if (supString[j] != vvod[i + counter])
                    {
                        vvodVector4.pop_back();
                        test = counter;
                        flag = true;
                        break;
                    }
                    counter++;
                }
            }
            for (int i = 0; i < len; i++)
            {
                cout << vvodVector4[i];
            }

            break;
        }
        case 5:
        {
            cout << "Введите подстроку:\n";
            char supString[100];
            cin >> supString;
            cout << "Индекс введенной подстроки в осортированной строке:\n";
            for (int i = 0; i < vvodVector.size(); i++)
            {
                bool flag = false;
                int counter = 0;
                for (int j = 0; supString[j] != '\0'; j++)
                {
                    if (supString[j] != vvodVector[i + counter])
                    {
                        flag = true;
                        break;
                    }
                    counter++;
                }
                if (flag == false)
                {
                    cout << i << " ";
                } 
            }
            break;
        }
        default:
            cout << "Доступно 4 задания.\n\n";
            break;
        }
        _getch();
    }
    return 0;
}