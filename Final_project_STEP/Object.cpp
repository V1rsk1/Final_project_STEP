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









string Object::get_object(string line, int num) { //��������� ����-����� ��'���� � ����� �� ������� ���������: ��'���0|��'���1|��'���2)
    int i = 0;


    string tmp = "";
    vector<string>vec;
    while (i < line.length()) {
        while (line[i] != '|' && i < line.length()) {

            tmp += line[i];
            i++;


        }

        vec.push_back(tmp);
        tmp = "";

        i++;

    }

    return vec[num];


}

