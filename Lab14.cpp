//Дан пофамильный список учителей школы, которые преподают математику, информатику,
//физику, химию и биологию, с указанием их недельной нагрузки по каждому из предметов.
//Вывести учителей, имеющих минимальную нагрузку среди преподающих один предмет, затем
//среди преподающих два предмета и т.д.до пяти.
//Применить в задаче перечислимый тип enum

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum subject_name
{
    math,
    info,
    phys, 
    chem,
    biol
};

struct teacher
{
    string surname;
    int number_subject = 0;
    map <subject_name, int> subjects;
    int sum_load = 0;
};

subject_name code(string input)
{
    subject_name returning;
    if (input == "математика")
    {
        returning = math;
    }
    else if (input == "информатика")
    {
        returning = info;
    }
    else if (input == "физика")
    {
        returning = phys;
    }
    else if (input == "химия")
    {
        returning = chem;
    }
    else if (input == "биология")
    {
        returning = biol;
    }
    return returning;
}

string decode(int input)
{
    string returning;
    switch (input)
    {
    case math:
        returning = "математика";
        break;
    case info:
        returning = "информатика";
        break;
    case phys:
        returning = "физика";
        break;
    case chem:
        returning = "химия";
        break;
    case biol:
        returning = "биология";
        break;
    }
    return returning;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <teacher> teachers;
    int number_teachers;
    cout << "Введите количество учителей в школе: "; cin >> number_teachers;
    teachers.resize(number_teachers);

    cout << endl << "Заполнение списка учителей " << endl;
    for (int i = 0; i < number_teachers; i++)
    {
        cout << "Учитель " << i + 1 << endl;
        cout << "Введите фамилию: "; cin >> teachers[i].surname;
        cout << "Введите количество предметов (максимально - 5): "; cin >> teachers[i].number_subject;
        for (int j = 0; j < teachers[i].number_subject; j++)
        {
            cout << "Введите " << j + 1 << " предмет и недельную нагрузку: ";
            string subject; cin >> subject;
            int weekly_load; cin >> weekly_load;
            teachers[i].subjects.insert(make_pair(code(subject), weekly_load));
        }
        cout << endl;
    }

    for (int i = 0; i < number_teachers; i++)
    {
        map <subject_name, int> ::iterator it = teachers[i].subjects.begin();
        for (; it != teachers[i].subjects.end(); it++)
        {
            teachers[i].sum_load += it->second;
        }
        cout << endl;
    }

    int min_sum_load[5] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };
    for (int i = 0; i < number_teachers; i++)
    {
        if (teachers[i].sum_load < min_sum_load[teachers[i].number_subject - 1])
        {
            min_sum_load[teachers[i].number_subject - 1] = teachers[i].sum_load;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Учителя с минимальной нагрузкой на " << i + 1 << " предмет(а/ов): " << endl;
        for (int j = 0; j < number_teachers; j++)
        {
            if ((teachers[j].sum_load == min_sum_load[i]) && (i == teachers[j].number_subject - 1))
            {
                cout << teachers[j].surname << endl;
            }
        }
        cout << endl;
    }
}