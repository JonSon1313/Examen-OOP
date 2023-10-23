#include "FinanceManager.h"
#include <iostream>
#include <fstream>
#include <map>
//Метод для додавання нового гаманця
void FinanceManager::addWallet(std::string wallet_name, double balance, std::string type)
{
    Wallet wallet(wallet_name, balance, type);
    wallets[wallet_name] = wallet;
   //через ключ
}
//Метод для додавання коштів до гаманця
void FinanceManager::addFunds(const std::string& wallet_name, double amount)
{
    if (wallets.find(wallet_name) != wallets.end())
    {
        wallets[wallet_name].addFunds(amount);
    }
    else
    {
        std::cout << "Wallet for name " << wallet_name << " not found." << std::endl;
    }
}
//Метод для додавання витрати до гаманця
void FinanceManager::addExpense(std::string& wallet_name, std::string& category, double amount, std::string& date)
{
    if (wallets.find(wallet_name) != wallets.end()) 
    {
        Wallet& wallet = wallets[wallet_name];
        double balance = wallet.getBalance();

        
        if (balance >= amount) 
        {
      
            Expense expense(category, amount, date);

 
            wallet.addExpense(category, amount,date);

        
            balance -= amount;
        }
        else 
        {
            std::cout << "insufficient funds  " << wallet_name << "' In this wallets." << std::endl;
        }
    }
    else 
    {
        std::cout << " Wallet not found " << wallet_name << "' Not found." << std::endl;
    }
}
//Метод для перевірки, чи є рік високосним
bool FinanceManager::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
//Метод для перевірки, чи рядок є числовим
bool FinanceManager::isNumeric(const std::string amountStr)
{
    for (char c : amountStr)
    {
        if (!std::isdigit(c) && c != '.')
        {
            return false;
        }
    }
    return true;
}
//Метод для перевірки валідності введених даних 
bool FinanceManager::isValidExpenseInput(const std::string wallet_name,const std::string category, const std::string type, const std::string amountStr, double amount)
{
    bool validWalletName = (wallet_name == "Visa" || wallet_name == "Mastercard");
    bool validCategory = (category == "Travels" || category == "Shop" || category == "Entertainment" ||
        category == "Online shopping" || category == "Insurance" || category == "Education");
    bool validWalletType = (type == "Debit" || type == "Credit");

    if (!validCategory)
    {
        std::cout << "Invalid category: " << category << std::endl;
        return false;
    }
    if (!validWalletName)
    {
        std::cout << "Invalid wallet name: " << wallet_name << std::endl;
        return false;
    }
    if (!validWalletType)
    {
        std::cout << "Invalid wallet type: " << type << std::endl;
        return false;
    }
 
    if (!isNumeric(amountStr) || sscanf_s(amountStr.c_str(), "%lf", &amount) != 1 || amount <= 0)
    {
        std::cout << "Invalid numeric amount" << std::endl;
        return false;
    }

    return true;
}
//Метод для перевірки правильності введеної дати
bool FinanceManager::validDayOrMonthOrYear(const std::string dates)
{
    int year, month, day;
    if (sscanf_s(dates.c_str(), "%d-%d-%d", &year, &month, &day) == 3)
    {
       
        if ((month >= 1 && month <= 12) && (day >= 1 && day <= 31))
        {
            int daysInMonth;

            if (month == 2)
            {
                if (isLeapYear(year))
                {
                    daysInMonth = 29;
                }
                else
                {
                    daysInMonth = 28;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                daysInMonth = 30;
            }
            else
            {
                daysInMonth = 31;
            }

            if (day <= daysInMonth)
            {
                return true;
            }
        }
    }

    std::cout << "Invalid date format or values: " << dates << std::endl;
    return false;
}
//Метод для збереження операцій з коштами в файл
void FinanceManager::saveFundsToFile(const std::string filename, const std::string date, double amount)
{
    std::ofstream file(filename);

    if (file.is_open()) 
    {
        for (const auto& pair : wallets)
        {
            const Wallet& wallet = pair.second;
            file << "Wallet Name: " << wallet.getWalletName() << "\n";
            file << "Balance: " << wallet.getBalance() << "\n";
            file << "Type: " << wallet.getType() << "\n";

            file << "\n";
        }
        file.close();
        std::cout << "The data on the funds was saved to the file '" << filename << "'.\n";
    }
    else 
    {
        std::cout << "Error: Could not open file '" << filename <<"\n";
    }
}
//Метод для збереження звіту у файл
void FinanceManager::saveReportsToFile(const std::string filename, const std::string period)
{
    std::ofstream file(filename, std::ios::app); 

    if (file.is_open())
    {
        for (const auto& pair : wallets)
        {
            const Wallet& wallet = pair.second;
            file << "Wallet Name: " << wallet.getWalletName() << "\n";
            file << "Type: " << wallet.getType() << "\n";
            file << "Balance: " << wallet.getBalance() << "\n\n";

            std::vector<Expense> expenses = wallet.getExpenses();

            for (const Expense& expense : expenses)
            {
                std::string category = expense.getCategory();
                double amount = expense.getAmount();
                std::string date = expense.getDate();

                file << "Category: " << category << "\n\n";
                file << "Amount: " << amount << " UAH\n";
                file << "Date: " << date << "\n";
            }
        }
        file.close();
        std::cout << "The report data was saved to the file '" << filename << "'.\n";
    }
    else
    {
        std::cout  << "Error: Could not open file '" << filename << "' for writing.\n";
    }
}
//Метод для перевірки валідності введених даних для операції додавання коштів
bool FinanceManager::isValidFundsInput(const std::string wallet_name, double amount, const std::string type, const std::string amountStr)
{
    bool validWalletName = (wallet_name == "Visa" || wallet_name == "Mastercard");
    bool validWalletType = (type == "Debit" || type == "Credit");

    if (!validWalletName)
    {
        std::cout << "Invalid wallet name: " << wallet_name << std::endl;
        return false;
    }
    if (!validWalletType)
    {
        std::cout << "Invalid wallet type: " << type << std::endl;
        return false;
    }

    if (!isNumeric(amountStr))
    {
        std::cout << "Invalid numeric amount" << std::endl;
        return false;
    }

    if (sscanf_s(amountStr.c_str(), "%lf", &amount) != 1 || amount <= 0)
    {
        std::cout << "Invalid numeric amount" << std::endl;
        return false;
    }

    return true;
}
//Метод для генерації звіту про витрати
void FinanceManager::generateExpenseReport(const std::string period)
{
    std::vector<Expense> expenses;

    
    int year = std::stoi(period.substr(0, 4));

    for (const auto& pair : wallets)
    {
        const Wallet& wallet = pair.second;
        const std::vector<Expense>& walletExpenses = wallet.getExpenses();

        for (const Expense& expense : walletExpenses)
        {
            
            if (isInYear(expense.getDate(), year))
            {
                expenses.push_back(expense);
            }
        }
    }

    if (expenses.empty())
    {
        std::cout << "No expenses found for the specified year.\n";
        return;
    }

    std::cout << "Expense Report (" << period << "):\n";
    for (const Expense& expense : expenses)
    {
        std::cout << "Category: " << expense.getCategory() << "\n";
        std::cout << "Amount: " << expense.getAmount() << " UAH\n";
        std::cout << "Date: " << expense.getDate() << "\n";
        std::cout << "\n";
    }

    std::string report_filename = "expense_report_" + period + ".txt";
    std::ofstream report_file(report_filename);

    if (report_file.is_open())
    {
        report_file << "Expense Report (" << period << "):\n";
        for (const Expense& expense : expenses)
        {
            report_file << "Category: " << expense.getCategory() << "\n";
            report_file << "Amount: " << expense.getAmount() << " UAH\n";
            report_file << "Date: " << expense.getDate() << "\n";
            report_file << "\n";
        }
        report_file.close();
        std::cout << "Report data was saved to the file '" << report_filename << "'.\n";
    }
    else
    {
        std::cerr << "Error: Could not open file '" << report_filename << "' for writing.\n";
    }
}
//Метод для перевірки чи дата витрати належить до заданого діапазону дат
bool FinanceManager::isInDateRange(const std::string expenseDate, const std::string startDate, const std::string endDate)
{
    try
    {
        int eYear, eMonth, eDay;
        int startYear, startMonth, startDay;
        int endYear, endMonth, endDay;

        if (sscanf_s(expenseDate.c_str(), "%d-%d-%d", &eYear, &eMonth, &eDay) != 3 ||
            sscanf_s(startDate.c_str(), "%d-%d-%d", &startYear, &startMonth, &startDay) != 3 ||
            sscanf_s(endDate.c_str(), "%d-%d-%d", &endYear, &endMonth, &endDay) != 3)
        {
            return false;
        }

        if (eYear >= startYear && eYear <= endYear &&
            eMonth >= startMonth && eMonth <= endMonth &&
            eDay >= startDay && eDay <= endDay)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (const std::exception& e)
    {
        return false;
    }
}
//Метод для перевірки чи дата витрати належить до визначеного року
bool FinanceManager::isInYear(const std::string expenseDate, int year)
{
    try
    {
        int eYear, eMonth, eDay;

        if (sscanf_s(expenseDate.c_str(), "%d-%d-%d", &eYear, &eMonth, &eDay) != 3)
        {
            return false;
        }

        return eYear == year;
    }
    catch (const std::exception& e)
    {
        return false;
    }
}
