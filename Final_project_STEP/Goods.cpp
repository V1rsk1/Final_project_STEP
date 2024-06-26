#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // для зчитування кнопок
#include <Windows.h>
#include <fstream> // для роботи з файлами
#include <stdlib.h>//для переведення типів даних та інших функцій(бібліотека ще з мови програмування с)

//Наші класи, для зручного виклику методів та для доступу полів
#include "Workers.h"
#include "Shop.h"
#include "Goods.h"
#include "Object.h"
using namespace std;











void Goods::del_good() {

    Goods good;
    int num;

    string line;


    vector<string>vec;



    cout << "Номер товару: " << endl;
    cin >> num;
    ifstream file2("Goods.txt");
    if (file2.is_open()) {

        while (getline(file2, line))
        {


            vec.push_back(line);




        }


    }
    else {
        cout << "Помилка!";
    }



    file2.close();
    int pos;

    pos = vec.size() - num + 1;


    vec.erase(vec.end() - pos);

    cout << num << pos << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;


    }


    ofstream file("Goods.txt");
    if (file.is_open()) {

        for (int i = 0; i < vec.size(); i++) {

            file << vec[i] << endl;
        }



        cout << "Все гаразд, натисніть ESC для виходу";
    }

    else {
        cout << "Помилка!";
    }
    file.close();

}

void Goods::out_all_goods_s(string name) {
    Shop shop;
    string line;
    string name_;

    char button;


    ifstream in1(name + ".txt");
    system("cls");

    if (in1.is_open())
    {

        while (getline(in1, line))
        {
            shop.amount_of_goods++;


        }
    }
    in1.close();


    ofstream in2("Amount_Goods.txt");
    in2 << shop.amount_of_goods;
    in2.close();


}






void Goods::add_new_good() {

    Goods good;


    cout << endl << "Назва товару: ";
    cin >> good.name;
    cout << endl << "Кількість:";
    cin >> good.number;
    cout << endl << "Ціна:";
    cin >> good.price;
    ofstream file("Goods.txt", ios::app);
    if (file.is_open()) {
        file << endl << good.name << '|' << good.number << '|' << good.price;
        cout << "Все гаразд, натисніть ESC для виходу";


    }
    else {
        cout << "Помилка!";
    }
    file.close();

}


void Goods::out_all_goods(string name) {
    string line;
    string name_;
    Shop shop;
    char button;
    int count = 1;

    ifstream in1(name + ".txt");
    system("cls");

    cout << "\t\t\t\t\t\t\t\t" << "Всі товари" << endl;
    cout << "Якщо треба додати товар власноруч натисніть пробіл" << endl;
    cout << "Якщо треба видалити товар натисніть q" << endl;
    if (in1.is_open())
    {

        while (getline(in1, line))
        {
            Goods good;

            good.name = get_object(line, 0);
            good.number = stoi(get_object(line, 1)); // з string в int
            good.price = stof(get_object(line, 2)); // з string в float

            cout << count << ") " << good.name << '|' << good.number << '|' << good.price << endl;
            count++;

        }
    }
    in1.close();
    button = _getch();
    if (button == 27) {
        system("cls");
        shop.Main_Menu();


    }
    else if (button == 32) {
        add_new_good();



    }
    else if (button == 'q') {
        del_good();
    }
    button = _getch();
    if (button == 27) {
        system("cls");
        shop.Main_Menu();


    }
}
