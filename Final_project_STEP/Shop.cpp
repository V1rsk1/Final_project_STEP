#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // для зчитування кнопок
#include <Windows.h>
#include <fstream> // для роботи з файлами
#include <stdlib.h>//для переведення типів даних(бібліотека ще з мови програмування с)

//Наші класи, для зручного виклику методів та для доступу полів
#include "Workers.h"
#include "Shop.h"
#include "Goods.h"
#include "Object.h"



using namespace std;

void Shop::set_name(string a) {
    Name = a;


}
string Shop::get_name() {
    return Name;
}

void Shop::show_all() {
    cout << endl << Name << endl << balance << endl << amount_of_goods << endl << amount_of_providers << endl;


}


void Shop::Main_Info() {


    Shop shop;
    Goods goods;

    string line;
    goods.out_all_goods_s("Goods");
    ifstream in1("Shop_Name.txt");
    if (in1.is_open())
    {

        while (getline(in1, line))
        {
            shop.get_name() = line;
        }
    }
    in1.close();


    ifstream in4("Amount_Goods.txt");
    if (in4.is_open())
    {

        while (getline(in4, line))
        {
            shop.amount_of_goods = stoi(line);
        }
    }
    in4.close();



    ifstream in3("Balance.txt");
    if (in3.is_open())
    {

        while (getline(in3, line))
        {
            shop.balance = stoi(line);
        }
    }
    in3.close();



    system("cls"); //очистити консоль
    SetConsoleCP(1251); //команда, яка встановлює кодування сторінки консолі у Windows
    SetConsoleOutputCP(1251); //команда, яка встановлює кодування сторінки консолі у Windows
    char tmp[24];
    vector<string>info_variants;
    int cursor = 0;
    bool enter = false;
    char button;
    info_variants = { "Змінити назву","К-сть товарів: ", "К-сть постачальників: ", "Баланс: " };
    while (enter == false) {
        cout << "\t\t\t\t\t\t\t\t" << "Основні відомості про магазин" << endl;

        for (int i = 0; i < info_variants.size(); i++) {
            if (i != cursor) {
                if (i == 1) {
                    cout << info_variants[i] << shop.amount_of_goods << endl;
                }
                else if (i == 2) {
                    cout << info_variants[i] << shop.amount_of_providers << endl;


                }
                else if (i == 3) {
                    cout << info_variants[i] << shop.balance << '$' << endl;

                }


                else {
                    cout << info_variants[i] << endl;


                }




            }


            else {
                cout << '>' << info_variants[i] << '<' << endl;
            }



        }
        button = _getch(); //зчитати кнопку

        if (button == 13) {
            enter = true;
            system("cls"); //очистити консоль
        }
        else if (button == 27) {
            system("cls"); //очистити консоль
            Main_Menu();


        }
        else {
            system("cls"); //очистити консоль
        }

    }
    cout << "\t\t\t\t\t\t\t\t" << "Зміна назви" << endl;
    cout << "Яку назву ви хочите?" << endl;
    cout << "Введіть: ";
    cin.get(tmp, 24);
    shop.set_name(tmp);

    ofstream in2("Shop_Name.txt"); // окрываем файл для чтения
    if (in2.is_open())
    {
        in2 << tmp << endl;


    }
    in2.close();
    cout << "Ваше нова назва: " << shop.get_name();
    button = _getch(); //зчитати кнопку

    if (button == 27) {
        system("cls"); //очистити консоль
        Main_Menu();


    }





    





}



void Shop::Main_Menu() {


    Shop shop;
    Goods goods;
    Workers workers;
    string line;

    ifstream in("Shop_Name.txt");
    if (in.is_open())
    {

        getline(in, line);
        
        shop.set_name(line);
        
    }
    in.close();

    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string>menu_variants;
    int cursor = 0; //позиція курсора (для нвігації стрілочками)
    bool enter = false;
    char button;
    menu_variants = { "Основні відомості про магазин","Товари","Робітники" };
    while (enter == false) {

        cout << "\t\t\t\t\t\t" << "Головне меню магазину " << shop.get_name() << endl;
        for (int i = 0; i < menu_variants.size(); i++) {
            if (i != cursor) {
                cout << menu_variants[i] << endl;


            }
            else {


                cout << '<' << menu_variants[i] << '>' << endl;
            }



        }
        button = _getch();
        //cout << button;
        if (button == 'P') {


            system("cls");
            if (cursor + 1 == menu_variants.size()) {
                cursor = 0;
            }
            else {
                cursor++;
            }




        }
        else if (button == 'H') {


            system("cls");
            if (cursor - 1 < 0) {
                cursor = menu_variants.size() - 1;
            }
            else {
                cursor--;
            }


        }
        else if (button == 13) {
            enter = true;
        }
        else {
            system("cls");
        }

    }

    switch (cursor) {
    case 0:
        system("cls");
        Main_Info();
        system("cls");
        break;

    case 1:
        system("cls");
        goods.out_all_goods("Goods");
        system("cls");

        break;



    case 2:
       system("cls");
        workers.out_all_workers("Workers");
        system("cls");
        break;

   
    }


}
