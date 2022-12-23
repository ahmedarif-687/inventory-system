#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct inventory
{
    string name;
    int itemid;
    string category;
    int qty;
    string allocatedto[100];
};
int counter = 0;
void menu(int& choice)
{
   
    cout<<"***********pucit inventory system**************"<<endl;           
    cout << "       Press 1 to add inventory        " << endl;
    cout << "       Press 2 to edit inventory       " << endl;
    cout << "       Press 3 to delete inventory     " << endl;
    cout << "       Press 4 to search inventory     " << endl;
    cout << "       Press 5 to assign inventory     " << endl;
    cout << "       Press 6 to view inventory       " << endl;
    cout << "       Press 7 to view faculty members  "<<endl;
    cout <<"           assigned with inventory         " << endl;
    cout << "    Press 8 to Retrieve inventory list" << endl;
    cout << "       Press -1 to exit" << endl;
    cout <<"**********************************************"<<endl;
    
    cin >> choice;
}
void addinventory(string nedit)
{
    int noofitems;
    cout << "How Many items Do You want to enter: ";
    cin >> noofitems;
    ofstream fout;
    inventory arr[100];
    for (int i = 0; i < noofitems; i++)
    {
        cout << "Enter the name of the item: " << endl;;
        cin >> arr[i].name;
        cout << "Enter the id of item: " << endl;
        cin >> arr[i].itemid;
        cout << "Enter the category of item: " << endl;
        cin >> arr[i].category;
        cout << "Enter the quantity of item: " << endl;
        cin >> arr[i].qty;
        cout << endl << endl;
        cout << "Item added Successfully";
        cout<<endl<<endl;
        
    }
    fout.open(nedit, ios::app);
    {
        for (int i = 0; i < noofitems; i++)
        {
            fout << arr[i].name <<" "<< arr[i].itemid <<" "<< arr[i].category<<" " << arr[i].qty <<" "<< endl;
        }
    }
    fout.close();
}
void viewinventory(string nedit)
{
    char gar;
    ifstream fin;
    fin.open(nedit);
    {
        while (!fin.eof())
        {
            fin.get(gar);
            cout << gar;
        }
    }
    fin.close();
}
void search(string nedit)
{
    inventory a;
    string gar;
    string searchitem;
    cout << "Enter Items You want to Search: ";
    cin >> searchitem;
    ifstream fin;
    fin.open(nedit);
    {
        while (!fin.eof())
        {
            fin >> gar;
            if (gar == searchitem)
            {
                a.name = gar;
                fin >> a.itemid;
                fin >> a.category;
                fin >> a.qty;
            }
        }
    }
    fin.close();
    cout << "Item Name is: ";
    cout << a.name << endl;
    cout << "Item Id are: ";
    cout << a.itemid << endl;
    cout << "Item category is: ";
    cout << a.category << endl;
    cout << "Number of Items in Inventory Are: ";
    cout << a.qty << endl;
}
void editor(string nedit)
{
    bool flag = false;
    int i = 1;
    inventory b[50];
    viewinventory(nedit);
    string searchitem;
    cout << "Enter Items You want to edit: ";
    cin >> searchitem;
    cout << "Enter New name: ";
    cin >> b[0].name;
    cout << "Enter New ID: ";
    cin >> b[0].itemid;
    cout << "Enter New category: ";
    cin >> b[0].category;
    cout << "Enter New Quantity: ";
    cin >> b[0].qty;
    ifstream fin;
    fin.open(nedit);
    {
        while (!fin.eof())
        {
            fin >> b[i].name;
            fin >> b[i].itemid;
            fin >> b[i].category;
            fin >> b[i].qty;
            i++;
        }
    }
    fin.close();
    ofstream fout;
    fout.open(nedit);
    {
        for (int j = 1; j < i - 1; j++)
        {
            if (b[j].name == searchitem)
            {
                fout << b[0].name << " " << b[0].itemid << " " << b[0].category << " " << b[0].qty << endl;
            }
            else
                fout << b[j].name << " " << b[j].itemid << " " << b[j].category << " " << b[j].qty << endl;
        }
    }
    fout.close();
}
void assign(string file)
{
    bool flag = false;
    int i = 1;
    string gar;
    inventory a[50];
    cout << "Enter Your Name: ";
    cin >> a[0].allocatedto[counter];
    viewinventory(file);
    cout << endl;
    cout << "What Item Do YOu Want: ";
    cin >> a[0].name;
    ifstream fin;
    ofstream fout;
    fout.open("Faculty.txt", ios::app);
    {
        fout << a[0].allocatedto[counter] << "  " << a[0].name << endl;
    }
    counter++;
    fout.close();
    fin.open(file);
    {
        while (!fin.eof())
        {
            fin >> a[i].name;
            if (a[i].name == a[0].name)
            {
                fin >> a[i].itemid;
                fin >> a[i].category;
                fin >> a[i].qty;
               a[i].qty--;
                flag = true;
            }
            if (flag == false)
            {
                fin >> a[i].itemid;
                fin >> a[i].category;
                fin >> a[i].qty;
            }
            flag = false;
            i++;
        }
    }
    fin.close();
    ofstream fouta;
    fouta.open(file);
    {
        for (int j = 1; j < i - 1; j++)
        {
            fouta << a[j].name << " " << a[j].itemid << " " << a[j].category << " " << a[j].qty << endl;
        }
    }
    fouta.close();
}
void viewfac()
{
    viewinventory("Faculty.txt");
}
void retrive(string file)
{
    bool flag = false;
    int i = 1;
    inventory a[50];
    string item;
    viewinventory(file);
    cout << "Enter Name of Item You are Returning: ";
    cin >> item;
    ifstream fin;
    fin.open(file);
    {
        while (!fin.eof())
        {
            fin >> a[i].name;
            if (a[i].name == item)
            {
                fin >> a[i].itemid;
                fin >> a[i].category;
                fin >> a[i].qty;
                a[i].qty++;
                flag = true;
            }
            if (flag == false)
            {
                fin >> a[i].itemid;
                fin >> a[i].category;
                fin >> a[i].qty;
            }
            flag = false;
            i++;
        }
    }
    fin.close();
    ofstream fouta;
    fouta.open(file);
    {
        for (int j = 1; j < i - 1; j++)
        {
            fouta << a[j].name << " " << a[j].itemid << " " << a[j].category << " " << a[j].qty << endl;
        }
    }
    fouta.close();

}
void deleteitem(string file)
{
    bool flag = false;
    int i = 1;
    inventory b[50];
    viewinventory(file);
    string searchitem;
    cout << "Enter Items You want to delete: ";
    cin >> searchitem;
    ifstream fin;
    fin.open(file);
    {
        while (!fin.eof())
        {
            fin >> b[i].name;
            fin >> b[i].itemid;
            fin >> b[i].category;
            fin >> b[i].qty;
            i++;
        }
    }
    fin.close();
    ofstream fout;
    fout.open(file);
    {
        for (int j = 1; j < i - 1; j++)
        {
            if (b[j].name == searchitem)
            {
                continue;
            }
            else
                fout << b[j].name << " " << b[j].itemid << " " << b[j].category << " " << b[j].qty << endl;
        }
    }
    fout.close();
}
int main()
{
    bool flag = false;
    string nedit = "Inventory.txt";
    int choice;
    do {
    choice = 0;
    menu(choice);
    system("cls");
    if (choice == 1)
    {
        addinventory(nedit);
    }
    else if (choice == 6)
    {
        viewinventory(nedit);
    }
    else if (choice == 4)
    {
        search(nedit);
    }
    else if (choice == 2)
    {
        editor(nedit);
    }
    else if (choice == 5)
    {
        assign(nedit);
    }
    else if (choice == 7)
    {
        viewfac();
    }
    else if (choice == 8)
    {
        retrive(nedit);
    }
    else if (choice == 3)
    {
        deleteitem(nedit);
    }
    system("pause");
   
    }while(choice != -1);
    return 0;
}