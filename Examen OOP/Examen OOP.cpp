#include <iostream>
#include "FinanceManager.h"
#include "Expense.h"
#include "Wallet.h"
#include <stdexcept> 
                   //Створіть систему управління персональними фінансами.
                  //Система мусить мати такі можливості :
               //■ Наявність різних гаманців і карт(дебетових / кредитних);
           //■ Поповнення гаманців і карт;
       //■ Внесення витрат.Кожна витрата належить певній категорії;
     //■ Формування звітів за витратами та категоріями :
 /* - я вирішив зробити за рік */
using namespace std;
bool to_continue = true;

int main()
{
    FinanceManager financeManager("User");
   
    financeManager.addWallet("Visa", 0.0, "Debit");
    financeManager.addWallet("Mastercard", 0.0, "Credit");
   
    char choice = ' ';
    do {
        try
        {
            cout << "Enter an option:" << "\n";
            cout << "1. Add funds" << "\n";
            cout << "2. Add expense" << "\n";
            cout << "3. Generate Expense Report" << "\n";
            cout << "Input a number of instruction: ";

            cin >> choice;

            switch (choice)
            {
            case '1':
            {
                cout << "Enter wallet name, amount, date (YYYY-MM-DD), and type (Debit/Credit):" << endl;
                string walletName, date, type, amountStr;

                double amount;

                cin.ignore();
                getline(cin, walletName);

                cin >> amountStr >> date >> type;
                amount = stod(amountStr);

                if (financeManager.isValidFundsInput(walletName, amount, type, amountStr) && financeManager.validDayOrMonthOrYear(date))
                {
                    financeManager.addFunds(walletName, amount);
                    cout << "Funds added successfully." << "\n";
                    financeManager.saveFundsToFile("funds_history.txt", date, amount);
                }
                else
                {
                    cout << "Invalid input. Please enter valid data." << "\n";
                }
                break;
            }
             case '2':
             {
                 cout << "Enter wallet name, category number (1-Travels, 2-Shop, 3-Entertainment, 4-Online shopping, 5-Insurance, 6-Education), amount, date (YYYY-MM-DD), and type (Debit/Credit):" << endl;
                 string walletName, category, date, type, amountStr;
                 double amount;

                 int categoryNumber;

                 cin.ignore();
                 getline(cin, walletName);

                 cin >> categoryNumber >> amountStr >> date >> type;
                 amount = stod(amountStr);

                 switch (categoryNumber)
                 {
                 case 1:
                     category = "Travels";
                     break;
                 case 2:
                     category = "Shop";
                     break;
                 case 3:
                     category = "Entertainment";
                     break;
                 case 4:
                     category = "Online shopping";
                     break;
                 case 5:
                     category = "Insurance";
                     break;
                 case 6:
                     category = "Education";
                     break;
                 default:
                     cout << "Invalid category: " << categoryNumber << "\n";
                     break;
                 }

                 if (!category.empty() && financeManager.isValidExpenseInput(walletName, category, type, amountStr, amount) && financeManager.validDayOrMonthOrYear(date))
                 {
                     financeManager.addExpense(walletName, category, amount, date);
                     cout << "Expense added successfully." << "\n";

                     financeManager.saveReportsToFile("transactions.txt", "Added Expense - Wallet: " + walletName + ", Category: " + category + ", Amount: " + to_string(amount) + ", Date: " + date + ", Type: " + type);

                     break;
                 }
                 else
                 {
                     cout << "Invalid input. Please enter valid data." << "\n";

                     break;
                 }
             }
              case '3':
              {
                  cout << "Enter start date (YYYY-MM-DD):" << "\n";
                  string startDate;
                  cin >> startDate;

                  cout << "Enter end date (YYYY-MM-DD):" << "\n";
                  string endDate;
                  cin >> endDate;

                  string period = startDate + " - " + endDate;

                  financeManager.generateExpenseReport(period);
                  cout << "Expense report generated." << "\n";
                  break;
              }


            case '4':
            {
                cout << "Exiting the program." << "\n";
                to_continue = false;
                return 0;
            }
            default:
            {
                cout << "Invalid option. Please choose a valid option." << "\n";
                break;

            }
            }
        }
        catch (const std::exception& e)
        {
            cout << "Caught exception: " << e.what() << "\n";

        }
      
    }while (to_continue);

    return 0;
}