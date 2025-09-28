#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
    string message;
    getline(cin, message);
    string bynestart;

    for (char c: message) {
        bitset<7>bChar(c); //Приводим значение символа к бинарному формату (7 бит)
        bynestart += bChar.to_string(); //Далее формируем строку

    }

    string res = "";
    int len = bynestart.length();
    //обработка последовотельности битов
    for (int i = 0; i<len; i++) {
        int count = 1;
        char bitNow = bynestart[i];
        int j = i + 1;
        //Считаем количество одинаковых подряд идущих битов
        for (j; j < len & bynestart[j] == bitNow; j++) {
        
            count += 1;
            
            
        }
        //формирование результируещей строки
        if (bitNow == '1') {
            res += "0 ";
        } else {
            res += "00 ";
        }
        res += string(count, '0');
        if (j < len) {
            res += " ";
        }
        //Присваиваем i значение j на котором бит не совпал и уменьшаем на 1,
        //т.к. цикл увеличивает переменную i на 1
        i = j - 1;
    }

    cout << res << endl;
}