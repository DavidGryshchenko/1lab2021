#include <iostream>
#include <math.h>
#include <conio.h>
#include <winsock.h>
#include <vector>

using namespace std;

struct spis
{
    string data;
    struct spis* next;
};



struct spis* create(void);
void list(spis* head);
void p_znach(spis* head, string s);
void p_num(spis* head, int g);
void menu_1();
void menu_2();
void menu_3();
struct spis* head;
struct spis* now;
int punkt_1(int a, int b, int** G);






struct spis* create(void)
{
    spis* p, * pred; string c;
    head = pred = p = new spis[sizeof(spis)];
    cout << "\n Введіть 1 елемент списку:";
    cin >> p->data;
    p->next = NULL;
    now = p;
    return head;
}



struct spis* zapolnenie(void)
{
    spis* p, * pred; string c;
    pred = now;
    do {
        p = new spis[sizeof(spis)];
        cout << "\n Елемент:";
        cin >> p->data;
        pred->next = p;
        pred = p;
        cout << "Вийти? y/n ->";
        cin >> c;
    } while (c != "y");
    p->next = NULL;
    return pred;
}


struct spis* del(spis* head)
{
    spis* p, * pred; string c;

    p = head;
    pred = p;
    p = head;
    while (p != NULL)
    {
        cout << "Ви хочите видалити (" << p->data << ") ? y/n ->";
        cin >> c;
        if (c == "y")
        {
            if (p == head) {
                head = head->next;
                delete[] p;
                break;
            }
            if (p) {
                pred->next = p->next;
                delete[] p;
                break;
            }
        }
        else {
            pred = p;
        }
        p = p->next;

    }
    return head;
    cout << "Елемент удалён успешно!!! ;)";
    _getch();
}





void list(spis* head)
{
    spis* p;
    p = head;
    int c = 0;
    while (p != NULL)
    {
        cout << "\n Елемент #" << c << ": " << p->data;
        p = p->next;
        c++;
    }
    _getch();
}

void p_znach(spis* head, string s)
{
    spis* p;
    p = head;
    int c = 0;
    string ss;
    while (p != NULL && ss != s)
    {
        p = p->next;
        ss = p->data;
        c++;
    }
    if (p == NULL)
    {
        cout << "Даного елементу не існує!";
    }
    else
    {
        cout << "Ваш елемент:" << p->data << "(" << c << ")";
    }
    _getch();
}

void p_num(spis* head, int g)
{
    spis* p;
    p = head;
    int c = 0;
    while (p != NULL && c != g)
    {
        p = p->next;
        c++;
    }
    if (p == NULL)
    {
        cout << "Даного елементу не існує!";
    }
    else
    {
        cout << "Ваш елемент:" << p->data << "(" << c << ")";
    }
    _getch();
}



void menu_1()
{

    while (1)
    {
        system("cls");
        cout << "===============Меню===============\n\n\n\n";
        cout << "1.Список\n";
        cout << "2.Матриці\n";
        cout << "3.Вихід\n\n\n";
        cout << "Ваш вибір: ";
        int m;
        cin >> m;
        if (m == 1)
        {
            menu_2();
        }
        else if (m == 2)
        {
            menu_3();
        }
        else if (m == 3)
        {
            system("cls");
            cout << "Допобачення!";
            Sleep(5000);
            exit(1);
        }
        else
        {
            system("cls");
            cout << "Обрано не правильний пункт меню!";
            Sleep(5000);
        }
    }
}
void menu_2()
{
    while (1)
    {
        system("cls");
        cout << "===============Список=============\n\n\n\n";
        cout << "1.Ініціалізація списку\n";
        cout << "2.Додати елемент\n";
        cout << "3.Видалити елемент\n";
        cout << "4.Вивести список\n";
        cout << "5.Пошук елемента\n";
        cout << "6.Повернутися до головного меню\n\n\n";
        int m;
        cout << "Ваш вибір: ";
        cin >> m;
        if (m == 1)
        {
            system("cls");
            head = create();
        }
        else if (m == 2)
        {
            system("cls");
            now = zapolnenie();
        }
        else if (m == 3)
        {
            system("cls");
            head = del(head);
        }
        else if (m == 4)
        {
            system("cls");
            list(head);
        }
        else if (m == 5)
        {
            system("cls");
            cout << "===============Пошук==============\n\n\n\n";
            cout << "1.Пошук за значенням\n";
            cout << "2.Пошук за індексом елемнту списку\n";
            cout << "3.Повернутися до меню \n\n\n";
            int p;
            cout << "Ваш вибір: ";
            cin >> p;
            if (p == 1)
            {
                system("cls");
                cout << "===============Пошук==============\n\n\n\n";
                string s;
                cout << "Введіть значення: ";
                cin >> s;
                p_znach(head, s);
            }
            else if (p == 2)
            {
                system("cls");
                cout << "===============Пошук==============\n\n\n\n";
                int c;
                cout << "Введіть індекс елементу: ";
                cin >> c;
                p_num(head, c);
            }
            else
            {
            }
        }
        else if (m == 6)
        {
            menu_1();
        }
        else
        {
            system("cls");
            cout << "Обрано не правильний пункт меню!";
            Sleep(5000);
        }

    }
}

void menu_3()
{
    system("cls");
    cout << "Заповніть першу матрицю\n";
    int a;
    int b;
    int m;
    cout << "Введіть A: ";
    cin >> a;
    cout << "Введіть B: ";
    cin >> b;

    int** G;
    int** Z;
    int** C;

    G = new int* [a];
    for (int i = 0; i < a; i++)
    {
        G[i] = new int[b];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "Елемент (" << i << ")(" << ") : ";
            cin >> G[i][j];
        }
    }
    while (1)
    {
        system("cls");
        cout << "===============Матриці============\n\n\n\n";
        cout << "1.Об'явити матрицю\n";
        cout << "2.Вивести матрицю\n";
        cout << "3.Множення матриць\n";
        cout << "4.Множення матриці на вектор\n";
        cout << "5.Додавання матриць\n";
        cout << "6.Транспонування матриці\n";
        cout << "7.Повернутися до меню\n\n\n";

        vector<int>F;
        cout << "Введіть значення: ";
        cin >> m;
        switch (m)
        {


        case 1:

            system("cls");
            cout << "Введіть A: ";
            cin >> a;
            cout << "Введіть B: ";
            cin >> b;
            punkt_1(a, b, G);

            break;

        case 2:

            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << G[i][j] << " ";
                }
                cout << "\n";
            }
            _getch();
            break;
        case 3:

            Z = new int* [b];
            for (int i = 0; i < a; i++)
            {
                Z[i] = new int[a];
            }
            cout << "Заповніть другу матрицю: \n";
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << "Елемент (" << i << ")(" << j << ") : ";
                    cin >> Z[i][j];
                }
            }
            system("cls");
            C = new int* [a];
            for (int i = 0; i < a; ++i)
            {
                C[i] = new int[b];
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < a; j++)
                {
                    for (int k = 0; k < b; k++)
                        C[i][j] += G[i][k] * Z[k][j];
                }
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << C[i][j] << "\n";
                }
                cout << "\n";
            }
            _getch();
            break;
        case 4:

            cout << "Заповніть вектор: \n";

            int h;
            for (int i = 0; i < a; ++i)
            {
                cout << "Елемент (" << i << ") : ";
                cin >> h;
                F.push_back(h);
            }
            system("cls");
            C = new int* [a];
            for (int i = 0; i < a; ++i)
            {
                C[i] = new int[b];
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < a; j++)
                {

                    for (int k = 0; k < b; k++)
                        C[i][j] += G[i][k] * F[k];
                }
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << C[i][j] << "\n";
                }
                cout << "\n";
            }
            _getch();


            break;
        case 5:

            Z = new int* [b];
            for (int i = 0; i < a; i++)
            {
                Z[i] = new int[a];
            }
            cout << "Заповніть другу матрицю: \n";
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << "Елемент (" << i << ")(" << ") : ";
                    cin >> Z[i][j];
                }
            }
            system("cls");
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << G[i][j] + Z[i][j] << " ";
                }
                cout << "\n";
            }
            _getch();
            break;
        case 6:

            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    cout << G[j][i];
                }
                cout << "\n";
            }
            _getch();
            break;
        case 7:

            menu_1();
            break;
        }
    }
}


int punkt_1(int a, int b, int** G)
{
    G = new int* [a];
    for (int i = 0; i < a; i++)
    {
        G[i] = new int[b];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "Елемент (" << i << ")(" << ") : ";
            cin >> G[i][j];
        }
    }
    return **G;
}



int main()
{
    system("chcp 1251");
    system("cls");
    menu_1();
}
