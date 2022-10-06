#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void add();
        void buyer();
        void edit();
        void remov();
        void list();
        void receipt();

};

void shopping ::menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________^______________\n";
    cout << "\t\t\t\t  Super Market Mian Menu     \n";
    cout << "\t\t\t\t______________^______________\n";
    cout << "\t\t\t\t______________^______________\n";

    cout << "\t\t\t\t| 1. Administrator |\n";
    cout << endl;
    cout << "\t\t\t\t| 2. Buyer         |\n";
    cout << endl;
    cout << "\t\t\t\t| 3. Exit          |\n";
    cout << endl;

    cout << "Please Select!";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Please Login \n";

            cout << "Email : ";
            cin >>email;

            cout << endl << "Password : ";
            cin >> password;

            if (email=="khizar.shah01@gmail.com" && password=="rootroot") {
                administrator();
            }

            else {
            cout << "Invalid Email/Password";
            }
            
          /*  if (email!="khizar.shah01@gmail.com") {
                cout << "Invalid Email" << endl;
            }
            if (password!="rootroot") {
                cout << "Invalid Password" << endl;
            }*/
        case 2:
            {
                buyer();
            }

        case 3:
            {
                exit(0);
            }
        default:
            {
                cout << "Select valid option";
            }
    }
    goto m;

}

void shopping::administrator()
{
    m:
    int choice;

    cout << "\n\n\n\t\t Administrator Menu";
    cout << "\n\n\t\t 1) Add the product.";
    cout << endl;
    cout << "\n\n\t\t 2) Modify the product.";
    cout << endl;
    cout << "\n\t\t\t 3) Delete the product.";
    cout << endl;
    cout << "\n\t\t\t 4) Back to Mian Menu.";

    cout <<"\n Please Select!";
    cin >> choice;

    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remov();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Select right option";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;

    cout << "\n\n\n\t\t\tBuyer";
    cout << "____________________________________";
    cout << "1) Buy products \n";
    cout << "2) Go Back\n";
    cout << "\n Please Select!";
    cin >> choice;

    switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "\n Invalid option";
    }
    goto m;
}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout << "\n\t Add Product \n";
    cout << "\n Product id \n>";
    cin >> pcode;
    cout << "\n Product name \n>";
    cin >> pname;
    cout << "\n Product price \n>";
    cin >> price;
    cout << "\n Product discount \n>";
    cin >> dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while (!data.eof()) 
        {
            if(c ==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    
    if(token==1)
        goto m;
    else
     {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
     }
    }
    cout << "\n\n\t Record inserted!";
}

void shopping ::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t Modify Record\n";
    cout << "\n\t Product code\n";
    cin >> pkey;

    data.open("database.txt",ios::in);
        if(!data)
        {
            cout<<"\n\t File doesn't exit \n";
        }
        else {
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pkey==pcode)
                {
                    cout <<"\n\tProduct new code :";
                    cin >>c;
                    cout <<"\n\tName of the product :";
                    cin >>n;
                    cout <<"\n\tPrice :";
                    cin >>p;
                    cout <<"\n\tDiscount :";
                    cin >>d;

                    data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\t Record edited !";
                    token++;

                }
                else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; 
                }
                data>>pcode>>price>>pname>>dis;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt");

            if (token==0) {
                cout << "\n\t Record not found !";
            }
        }
}

void shopping::remov()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout <<"\n\tDlete product";
    cout <<"\n\tProduct code :";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout << "\n File doesnt exit !";
    }
    else {
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;

    while (!data.eof()) {
        if (pcode==pkey) {
            cout <<"\n\tProduct Delete succesfully";
            token++;
        }
        else{
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        }
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
        cout<<"\n\t Record not found!";
    }
  }

}


//void shopping::list()