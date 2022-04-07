// Food Tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// for(0 - eof) -- vector <MEAL> meals;
/*
LOG.txt
{
    10/10/2020
    <2400,2000,100,300> proprietatile clasei progres (calorii, proteine etc.)   EXPECTED
    <1900,1200,100,300> same -- REAL
    <0,0,0,0>
    <0,0,0,0> 
    *
    MAR, 60, 1      Gustarile
    *
    etc.
    Lista produse recomandate:
    etc.
}
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
#include "Meal.cpp"
#include "Menu.cpp"
#include "Produs.cpp"
#include "Aliment.cpp"
#include "Progres.cpp"
#include "user.cpp"
#include "FoodTracker.h"
using namespace std;
#define CREATE_USER 1
#define ACCESS_USER 2
#define EDIT_USER 3

#define USER 1
#define LOG  2
#define DATA 3

int MENU_STATE = USER;
FoodTracker account;
void createUser()
{
    system("cls");
    ifstream f("account.txt");
    f.seekg(0, f.beg);
    if (f.peek() != EOF)
    {
        cout << "An user has already been created! Do you want to create a new user?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int i;
        cout << "Your option: ";
        cin >> i;
        if (i == 1)
        {
            f.close();
            string data;
            int a;
            int b;
            ofstream f("account.txt");
            cout << "Create a new user"<<endl;
            cout << "Name: ";
            cin.ignore(256, '\n');
            getline(cin, data);
            f << data << ",";
            account.acc.setName(data);
            cout << "Age: ";
            cin >> a;
            f << a << ",";
            account.acc.setAge(a);
            cout << "Sex (male/female): ";
            cin >> data;
            f << data << ",";
            if (data.compare("male") == 0)
                account.acc.setSex(0);
            else
                account.acc.setSex(1);
            cout << "Height: ";
            cin >> b;
            f << b << ",";
            account.acc.setHeight(b);
            cout << "Weight: ";
            cin >> b;
            f << b << ",";
            account.acc.setWeight(b);
            cout << "Weight_goal: ";
            cin >> b;
            f << b << ",";
            account.acc.setWeight_goal(b);
            cout << "Activity (sedentary/light/moderate/intense): ";
            cin >> data;
            f << data << ",";
            if (data.compare("sedentary") == 0)
                account.acc.setActivity(user::sedentary);
            else
                if (data.compare("light") == 0)
                    account.acc.setActivity(user::light);
                else
                    if (data.compare("moderate") == 0)
                        account.acc.setActivity(user::moderate);
                    else
                        account.acc.setActivity(user::intense);
            cout << "Goal (weight_loss/maintain/weight_gain):";
            cin >> data;
            f << data;
            if (data.compare("weight_loss") == 0)
                account.acc.setGoal(user::weight_loss);
            else
                if (data.compare("maintain") == 0)
                    account.acc.setGoal(user::maintain);
                else
                    if (data.compare("weight_gain") == 0)
                        account.acc.setGoal(user::weight_gain);
            f.close();
            std::ofstream ofs;
            ofs.open("log.txt", std::ofstream::out | std::ofstream::trunc);
            ofs << "{" << endl << "0.0.0" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl
                << "*" << endl << "*" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl << "*" << endl << "*" << endl << "/" << endl
                << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl << "*" << endl << "*" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl
                << "*" << endl << "*" << endl << "/" << endl << "}";
            ofs.close();
        }
        else
            cout << "Return to main menu." << endl;
    }
    else
    {
        f.close();
        string data;
        int a;
        int b;
        ofstream f("account.txt");
        cout << "Create a new user";
        cout << "Name: ";
        cin.ignore(256, '\n');
        getline(cin, data);
        f << data << ",";
        account.acc.setName(data);
        cout << "Age: ";
        cin >> a;
        f << a << ",";
        account.acc.setAge(a);
        cout << "Sex (male/female): ";
        cin >> data;
        f << data << ",";
        if (data.compare("male") == 0)
            account.acc.setSex(0);
        else
            account.acc.setSex(1);
        cout << "Height: ";
        cin >> b;
        f << b << ",";
        account.acc.setHeight(b);
        cout << "Weight: ";
        cin >> b;
        f << b << ",";
        account.acc.setWeight(b);
        cout << "Weight_goal: ";
        cin >> b;
        f << b << ",";
        account.acc.setWeight_goal(b);
        cout << "Activity (sedentary/light/moderate/intense): ";
        cin >> data;
        f << data << ",";
        if (data.compare("sedentary") == 0)
            account.acc.setActivity(user::sedentary);
        else
            if (data.compare("light") == 0)
                account.acc.setActivity(user::light);
            else
                if (data.compare("moderate") == 0)
                    account.acc.setActivity(user::moderate);
                else
                    account.acc.setActivity(user::intense);
        cout << "Goal (weight_loss/maintain/weight_gain):";
        cin >> data;
        f << data;
        if (data.compare("weight_loss") == 0)
            account.acc.setGoal(user::weight_loss);
        else
            if (data.compare("maintain") == 0)
                account.acc.setGoal(user::maintain);
            else
                if (data.compare("weight_gain") == 0)
                    account.acc.setGoal(user::weight_gain);
        f.close();
        std::ofstream ofs;
        ofs.open("LOG.txt", std::ofstream::out | std::ofstream::trunc);
        ofs << "{" << endl << "0.0.0" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl
            << "*" << endl << "*" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl << "*" << endl << "*" << endl << "/" << endl
            << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl << "*" << endl << "*" << endl << "/" << endl << "<0,0,0,0>" << endl << "<0,0,0,0>" << endl << "*" << endl
            << "*" << endl << "*" << endl << "/" << endl << "}";
        ofs.close();
    }
}
void edit_user()
{
    string data;
    int a;
    int b;
    ofstream f("account.txt");
    cout << "Edit the user info"<<endl;
    cout << "Name: ";
    cin.ignore(256, '\n');
    getline(cin, data);
    f << data << ",";
    account.acc.setName(data);
    cout << "Age: ";
    cin >> a;
    f << a << ",";
    account.acc.setAge(a);
    cout << "Sex (male/female): ";
    cin >> data;
    f << data << ",";
    if (data.compare("male") == 0)
        account.acc.setSex(0);
    else
        account.acc.setSex(1);
    cout << "Height: ";
    cin >> b;
    f << b << ",";
    account.acc.setHeight(b);
    cout << "Weight: ";
    cin >> b;
    f << b << ",";
    account.acc.setWeight(b);
    cout << "Weight_goal: ";
    cin >> b;
    f << b << ",";
    account.acc.setWeight_goal(b);
    cout << "Activity (sedentary/light/moderate/intense): ";
    cin >> data;
    f << data << ",";
    if (data.compare("sedentary") == 0)
        account.acc.setActivity(user::sedentary);
    else
        if (data.compare("light") == 0)
            account.acc.setActivity(user::light);
        else
            if (data.compare("moderate") == 0)
                account.acc.setActivity(user::moderate);
            else
                account.acc.setActivity(user::intense);
    cout << "Goal (weight_loss/maintain/weight_gain):";
    cin >> data;
    f << data;
    if (data.compare("weight_loss") == 0)
        account.acc.setGoal(user::weight_loss);
    else
        if (data.compare("maintain") == 0)
            account.acc.setGoal(user::maintain);
        else
            if (data.compare("weight_gain") == 0)
                account.acc.setGoal(user::weight_gain);
    f.close();
}
void vizualizare_alimente()
{
    std::ifstream f("data.txt");
        if (f.is_open())
            std::cout << f.rdbuf()<<endl;
        f.close();
}
void introducere_alimente()
{
    std::fstream f("data.txt", ios::app);
    if (f.is_open())
    {
        cout << "Introduceti numele alimentului: ";
        string nume;
        cin >> nume; cout << endl;
        cout << "Introduceti numarul de calorii al alimentului: ";
        int calorii;
        cin >> calorii; cout << endl;
        cout << "Introduceti numarul de proteine al alimentului: ";
        double proteine;
        cin >> proteine; cout << endl;
        cout << "Introduceti numarul de carbohidrati al alimentului: ";
        double carbohidrati;
        cin >> carbohidrati; cout << endl;
        cout << "Introduceti numarul de grasimi al alimentului: ";
        double grasimi;
        cin >> grasimi; cout << endl;
        f <<endl<< nume << "," << calorii << "," << proteine << "," << carbohidrati << "," << grasimi;
    }
    f.close();
}
void log_menu() {
    cout << "--- LOG[2] ---" << endl;
    cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
    cout << "1. Vizualizare alimente" << endl;
    cout << "2. Introducere alimente" << endl;
    cout << "3. Vizualizare date" << endl;
    cout << "4. Inapoi" << endl;
    cout << "5. Iesire aplicatie" << endl;

    int STATE_LOG;
    cin >> STATE_LOG;

    switch (STATE_LOG)
    {
    case 1:
        vizualizare_alimente();
        MENU_STATE = LOG;
        break;
    case 2:
        introducere_alimente();
        MENU_STATE = LOG;
        break;
    case 3:
        MENU_STATE = DATA;
        break;
    case 4:
        MENU_STATE = USER;
        break;
    case 5:
        exit(0);
        break;
    default:
        MENU_STATE = LOG;
        break;
    }
}
void afisare_progres(char ziua[])
{
    char line[100]; //linia din LOG.txt
    fstream f("LOG.txt");
        f.getline(line, 100);
        f.getline(line, 100);
        if (strcmp(line, ziua) == 0)
        {
            cout << "Progresul recomandat:" << endl;
            f.getline(line, 100);
            cout << line;
            cout << endl;
            cout << "Progresul real:" << endl;
            f.getline(line, 100);
            cout << line;
            cout << endl;
        }
        else
        {      
           cout << "Nu exista date pentru ziua respectiva" << endl;
        }
    f.close();
}
void data_menu() {
    cout << "--- LOG[3] ---" << endl;
    cout << "1. Afisare progres" << endl;
    cout << "2. Afisare alimente" << endl;
    cout << "3. Adauga aliment consumat" << endl;
    cout << "4. Inapoi" << endl;
    cout << "5. Iesire aplicatie" << endl;

    int STATE_DATA = 0;
    cin >> STATE_DATA;
    switch (STATE_DATA)
    {
    case 1:
    {cout << "Introduceti ziua dorita (ZZ.LL.AAAA): ";
    char ziua[13];
    cin >> ziua;
    afisare_progres(ziua);
    MENU_STATE = DATA;
    break; }
    case 2:
    {
        cout << "Introduceti ziua dorita (ZZ.LL.AAAA): ";
        char ziua[13];
        cin >> ziua;
    }
    case 3:
    {
        cout << "Introduceti ziua dorita (ZZ.LL.AAAA): ";
        char ziua[13];
        cin >> ziua;
    }
    case 4:
        MENU_STATE = LOG;
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}
void user_menu() {
    cout << "--- LOG[1] ---" << endl;
    cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
    cout << CREATE_USER << ". Creare utilizator" << endl;
    cout << ACCESS_USER << ". Accesare utilizator" << endl;
    cout << EDIT_USER << ". Editare utilizator" << endl;

    int STATE_USER;

    cin >> STATE_USER;

    switch (STATE_USER)
    {
    case CREATE_USER:
        createUser();
        MENU_STATE = USER;
        break;
    case ACCESS_USER:
        MENU_STATE = LOG;
        break;
    case EDIT_USER:
        edit_user();
        MENU_STATE = USER;
        break;
    default:
        MENU_STATE = USER;
        break;
    }
}

int main()
{
    while (true) {
        switch (MENU_STATE)
        {
        case USER:
            user_menu();
            break;
        case LOG:
            log_menu();
            break;
        case DATA:
            data_menu();
            break;
        }
    } 
}
