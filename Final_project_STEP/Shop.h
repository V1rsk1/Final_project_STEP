#pragma once
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
class Shop {


private:
    string Name;


public:
    
    int balance;
    int amount_of_goods = 0;
    int amount_of_providers = 0;


    void set_name(string a);
    string get_name();

    void show_all();


    void Main_Info();

    void Main_Menu();





};
