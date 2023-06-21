#include <iostream>
using namespace std;

struct Pekerja
{
    string nama;
    int umur, id;

    Pekerja *next;
};

Pekerja *head, *tail, *newNode, *cur, *del;

void createCSLL(string nama, int umur, int id)
{
    head = new Pekerja();
    head->nama = nama;
    head->umur = umur;
    head->id = id;
    tail = head;
    tail->next = head;
}

void addFirst(string nama, int umur, int id)
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        newNode = new Pekerja();
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->id = id;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void addMid(string nama, int umur, int id, int posisi)
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        if (posisi == 1)
        {
            cout << "bukan posisi tengah" << endl;
        }
        else
        {
            newNode = new Pekerja();
            newNode->nama = nama;
            newNode->umur = umur;
            newNode->id = id;

            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

void addLast(string nama, int umur, int id)
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        newNode = new Pekerja();
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->id = id;
        tail->next = newNode;
        tail = newNode;
    }
}

void delFirst()
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

void delMid(int posisi)
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        if (posisi == 1)
        {
            cout << "bukan posisi tengah" << endl;
        }
        else
        {
            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }
            del = cur->next;
            cur->next = del->next;
            delete del;
        }
    }
}

void delLast()
{
    if (head == NULL)
    {
        cout << "Linked list belum dibuat" << endl;
    }
    else
    {
        del = tail;
        cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

void printCSLL()
{
    cur = head;
    while (cur->next != head)
    {
        cout << "nama\t: " << cur->nama << endl;
        cout << "umur\t: " << cur->umur << endl;
        cout << "id\t: " << cur->id << endl
             << endl;
        cur = cur->next;
    }
    cout << "nama\t: " << cur->nama << endl;
    cout << "umur\t: " << cur->umur << endl;
    cout << "id\t: " << cur->id << endl;
    cout << "---------------------------" << endl;
}

int main(int argc, char const *argv[])
{
    createCSLL("Asep", 39, 01);
    addFirst("Bambang", 22, 02);
    addLast("Ucup", 25, 03);
    addMid("Dadang", 41, 04, 2);
    delMid(2);
    printCSLL();

    return 0;
}
