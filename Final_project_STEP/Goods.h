#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // ��� ���������� ������
#include <Windows.h>
#include <fstream> // ��� ������ � �������
#include <stdlib.h>//��� ����������� ���� �����(�������� �� � ���� ������������� �)

//���� �����, ��� �������� ������� ������ �� ��� ������� ����
#include "Workers.h"
#include "Shop.h"
#include "Goods.h"
#include "Object.h"
using namespace std;

class Goods : public Object{
public:
    string name;
    int number;
    float price;
    


   



    void out_all_goods(string name);
    

    void add_new_good();

    void del_good();

    void out_all_goods_s(string name);




};


