#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    //Строка с алфавитом, для извлечения индексов
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str = "";
    int index_char;
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();
    string t;
    getline(cin, t);

    //Обработка ASCII строки
    for (int i = 0; i < h; i++) {
        string str = ""; 
        string row;
        getline(cin, row);
        
        //Преобразуем к верхнему регистру, т.к алфавит в верхнем регистре и для 3 теста
        for (char a : t) {
            a = toupper(a);
        
            //Ищем позицию символа в алфавите
            if (alpha.find(a) != string::npos) {
                index_char = alpha.find(a);
            } else {
                index_char = 26; 
            }
            
            //Срез строки соответсвующий символу
            str += row.substr(index_char * l, l);
        }
        cout << str << endl;
    }
}


