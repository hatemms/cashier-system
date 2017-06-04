#include <iostream>
#include <string>
#include <conio.h> //for gtech(); to press any key
#include <stdlib.h> //for system('cls'); to clean console
//#include <fstream>

using namespace std;
int input = 99;
int arr = 0;
float c_data [100];
int c_ID[100];

void wrong_input_ms()   //wrong choice massage
{
   cout << "\n\n";
   cout << "\t" << "****************************************************************************************************" << "\n";
   cout << "\t" << "***                                   YOUR CHOICE IS WRONG !!                                    ***" << "\n";
   cout << "\t" << "****************************************************************************************************" << "\n\n";
}

bool input_validation()   //to validate the inputs
{
int error;

// input validation loop
do
{
   error = 0;
   cout << "\t\t"   << "Your choice : ";
   cin >> input;
   if (cin.fail())
   {
      wrong_input_ms();
      error = 1;
      cin.clear();
      cin.ignore(80, '\n');
      input_validation();
   }
}while(cin.fail());

}

void admin_form()   //basic admin form
{
   cout << "\n"   << "\t\t\t\t\t\t" << "         * admin access *"   << "\n";
   cout << "\t\t"   << "press 1. to quick report"                      << "\n";
   cout << "\t\t"   << "press 2. to show detailed report"              << "\n";
   cout << "\t\t"   << "press 3. to logout"                            << "\n\n";
}

void user_form()    //basic user form
{
   cout << "\n"   << "\t\t\t\t\t\t" << "         * user access *"   << "\n";
   cout << "\t\t"   << "press 1. to sell item"                      << "\n";
   cout << "\t\t"   << "press 2. to edit"                           << "\n";
   cout << "\t\t"   << "press 3. to logout"                         << "\n\n";
}

class login   //login class has username, password and some function to validate it
{
public:
   string username,password;
   bool IsLogIn();
   void login_input();
}log;

void login :: login_input()
{
   cout << "\n\n" << "\t\t"   << "Enter your name     : ";
   cin >> username ;

   cout           << "\t\t"   << "Enter your password : ";
   char ch;
   ch = _getch();
   while(ch != 13){
      password.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout << endl;
   }

bool login :: IsLogIn()
{
   string ch_adminPass = "admin";
   string ch_userPass = "user";

   system ("cls");
   cout << "\n\n\n" << "\t\t\t\t\t\t" << "WELCOME TO CASHIER SYSTEM" << "\n";
   cout             << "\t\t\t\t\t\t" << "_________________________" << "\n\n";
   cout             << "\t\t\t\t\t\t" << "     * Login page *"       << "\n\n";
   cout << "\t\t"   << "press 1. to login as an (admin)"                << "\n";
   cout << "\t\t"   << "press 2. to login as an (user)"              << "\n\n";
   cout << "\t\t"   << "press 0. to exit"                            << "\n\n";

   input_validation();
   for ( ; input >=3 ; )
      {
         wrong_input_ms();
         input_validation();
      }
   if (input == 0) {exit(0);}

   login_input();

   system ("cls");

   if (input == 1)
   {
      while (password != ch_adminPass)
         {
            cout << "\n" << "                                                         * invalid password *"        << "\n" ;
            cout         << "                                                       * please enter a valid *"             << "\n";
            password = "";
            login_input();
         }
      return true;
   }

   if (input == 2)
   {
      while (password != ch_userPass)
         {
            cout << "\n" << "                                                         * invalid password *"               << "\n" ;
            cout         << "                                                       * please enter a valid *"             << "\n";
            password = "";
            login_input();
         }
      return true;
   }
}

class user   //user way class
{
protected:
   int item_ID [100];
   float item_price [100];

public:
      //float c_data [100];

      double sell_item()
      {
         //ofstream file;
         //file.open("sells.txt",ios::out);

         //system ("cls");
         for ( ; input != 0 ; )
         {
            c_data[arr] = item_price[arr];
            c_ID[arr]   = item_ID[arr];
            arr++;

            cout << "\n\n" << "\t\t\t\t\t\t\t" << "  no." << arr << "\n";
            cout           << "\t\t\t\t\t\t" << "     * sells page *"       << "\n\n";
            cout << "\t\t" << "Enter the item-ID    : ";
            cin >> item_ID[arr];
            cout << "\t\t" << "Enter the item price : ";
            cin >> item_price[arr];

            cout << "\n\n--------------------------------\n";
            cout << "press 1. to sell another one"    << "\n";
            cout << "press 0. to back to user access" << "\n\n";

            input_validation();
            for ( ; input >=2 ; )
            {
               wrong_input_ms();
               input_validation();
            }

            c_data[arr] = item_price[arr];
            c_ID[arr] = item_ID[arr];

            if (input == 1) { sell_item(); }
         }
            if (input == 0) { return false; return item_price[arr]; return item_ID[arr];}
      }

      double edit()
      {
         system ("cls");
         int edit,a;
       cout << "\n\n" << "\t\t\t\t\t\t" << "     * edit page *" << "\n\n";
       cout << "\t\t" << "Enter the item-ID to edit : ";
       cin >> item_ID[edit];
       cout << "\n\n";
       for (a=arr ; item_ID[edit] != item_ID[a] ; a--)
       {
          //cout << "h  ";
       }
       edit = a;

       cout << "\t\t" << "the item price is = " << item_price[edit] << "\n\n";
       cout << "\t\t" << "Enter the new price : ";
       cin >> item_price[edit];

       cout << "\n\t\t\t\t\t\t DONE :) \n";
       cout << "press any key to back to user access...";
       getch();
      }
}U;

class admin : public user   //admin way class
{
protected:
   float sum;

public:
   float q_report()
   {
   system ("cls");

   for (int arr_size=0 ; arr>=arr_size ; )
   {
      sum = sum + c_data[arr_size];
      arr_size++;
   }
   cout << "\n\n" << "\t\t\t" << "---------------------------------"   << "\n";
   cout           << "\t\t\t" << "| number of items : " << arr            << "\n";
   cout           << "\t\t\t" << "---------------------------------"   << "\n";
   cout           << "\t\t\t" << "| your balance    : " << sum            << " L.E\n";
   cout           << "\t\t\t" << "---------------------------------"   << "\n";
   cout           << "\t\t\t" << "| sells man       : " << log.username   << "\n";
   cout           << "\t\t\t" << "---------------------------------"   << "\n";
   sum = 0;
   }

   void d_report()
   {
      for (int arr_size=1 ; arr>=arr_size ; )
      {
         sum = sum + c_data[arr_size];
         arr_size++;
      }

      system ("cls");
      cout<< "\n\n"  << "\t\t\t" << "| item ID | item price |"   << "\n";
      cout           << "\t\t\t" << "------------------------"   << "\n";

      for (int i=1 ; i<arr+1 ; i++ )
      {
         cout << "\t\t\t" << "| " << c_ID[i] << "       | " << c_data[i] << " L.E\n";
      }

      cout << "\t\t\t" << "========================"   << "\n";
      cout << "\t\t Total :  " << arr << "       | " << sum << " L.E\n";
      sum = 0;
   }
}A;

int main()
{
   if(log.IsLogIn())
   {
      if (input == 2)
         {
         for (int x=1 ; x!=0 ; ){
         system ("cls");
         cout << "\n\n\n" << "\t\t\t\t\t\t\t" << "   WELCOME " << log.username << " !\n";
         cout             << "\t\t\t\t\t\t\t" << "____________________"   << "\n";
         user_form();

         input_validation();
         for ( ; input >=4 ; )
         {
            wrong_input_ms();
            input_validation();
         }
         if (input == 1) { U.sell_item(); }
         if (input == 2) { U.edit(); }
         if (input == 3) { main(); input=99; x=0; }
         }
         }

      if (input == 1)
         {
         for (int x=1 ; x!=0 ; )
            {
               system ("cls");
               cout << "\n\n\n" << "\t\t\t\t\t\t\t" << "   WELCOME " << log.username << " !\n";
               cout             << "\t\t\t\t\t\t\t" << "____________________"   << "\n";
               admin_form();

               input_validation();
               for ( ; input >=4 ; )
               {
                  wrong_input_ms();
                  input_validation();
               }

               if (input == 1)
               {
                  A.q_report();
                  cout << "\n\t\t\t\t\t\t DONE :) \n";
                  cout << "\npress any key to back to admin access...";
                  getch();
               }
               if (input == 2)
               {
                  A.d_report();
                  cout << "\n\t\t\t\t\t\t DONE :) \n";
                  cout << "\npress any key to back to admin access...";
                  getch();
               }
               if (input == 3) { main(); input=99; x=0; }
            }
         }
   }
   return 0;
}
