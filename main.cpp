#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int snt_counter = 0; 
    int wrd_counter = 0;
    string stroka;
    cout << "Введите предложение: " << "\n" << endl;
    getline(cin, stroka);

    for (int i = 0; i < stroka.size(); i++){

        if (stroka[i] == '.'){
            if (stroka[i+1] == '.' and stroka[i+2] == '.'){
                snt_counter++;
                wrd_counter++;
                i+=2;
            }
            else {
                snt_counter++;
                wrd_counter++;
            }
        }

        if (stroka[i] == '!'){
            snt_counter++;
            wrd_counter++;
        }      

        if (stroka[i] == '?'){
            snt_counter++;
            wrd_counter++; 
        }
        
        if (stroka[i] == ' ') {
            if (stroka[i-1] != '!' and stroka[i-1] != '.' and stroka[i-1] != '?' and stroka[i-1] != ',' and stroka[i-1] != ';' and stroka[i-1] != ':' and stroka[i-1] != '-') {
                if ((stroka[i+1] == ',' or stroka[i+1] == ';' or stroka[i+1] == ':' or stroka[i+1] == '-') and stroka[i+2] != ' ') {
                    wrd_counter++;
                    i++;}
                else if ((stroka[i+1] == ',' or stroka[i+1] == ';' or stroka[i+1] == ':' or stroka[i+1] == '-') and stroka[i+2] == ' ') {
                    wrd_counter++;
                    i+=2;}
                else wrd_counter++;
                }
            else i++;
        }

        if (stroka[i] == ',' or stroka[i] == ';' or stroka[i] == ':') wrd_counter++;

        }

    cout << "\n" << "Количество предложений в строке = " << snt_counter << endl;
    cout << "Количество слов в строке = " << wrd_counter << endl;
}
