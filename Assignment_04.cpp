#include <iostream>
#include <fstream>
using namespace std;

template <class T>
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

class random_class
{
private:
    int a, b;

public:
    random_class(int c, int d)
    {
        cout << "Constructor is called" << endl;
        a = c;
        b = d;

        cout << "Value of a: " << a << endl;
        cout << "Value of b: " << b << endl;
        cout << endl;
    }

    ~random_class()
    {
        cout << "\nDestructor is called" << endl;
        cout << "Value of a: " << a << endl;
        cout << "Value of b: " << b << endl;
    }
};

class Parent
{
public:
    int id_p;
};

class Child : public Parent
{
public:
    int id_c;
};

class Test
{
private:
    int num;

public:
    Test() : num(3) {}
    void operator++()
    {
        num = num + 5;
    }
    void Print()
    {
        cout << "The Count is: " << num;
    }
};

int main()
{
    int a[9] = {36, 76, 23, 64, 34, 66, 13, 90, 12};
    int n = sizeof(a) / sizeof(a[0]);

    selectionSort<int>(a, n);

    cout << "Sorted array :\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    random_class obj(5, 6);

    Child obj1;
    obj1.id_c = 9;
    obj1.id_p = 45;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n';

    Test t;
    ++t;
    t.Print();

    int roll, fee;
    char name[50];
    cout << "\n\nEnter the Roll Number:";
    cin >> roll;
    cout << "\nEnter the Name:";
    cin >> name;
    cout << "\nEnter the Fee:";
    cin >> fee;

    ofstream fout("d:/student.doc");
    fout << roll << "\t" << name << "\t" << fee;

    fout.close();

    ifstream fin("d:/student.doc");

    fin >> roll >> name >> fee;

    fin.close();

    cout << endl
         << roll << "\t" << name << "\t" << fee;
    return 0;
}