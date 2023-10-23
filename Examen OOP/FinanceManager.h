#pragma once
#include "Wallet.h"
#include <string>
#include <map>
#include <vector>

class FinanceManager
{
private:
    std::string user_name;        // Name useer
    std::map<std::string, Wallet> wallets; // Wallets users 
    std::string period;           // Period for the report
    std::string amountStr;        // String to save the amount
    std::string startDate;        // Start date 
    std::string endDate;          // Deadline date 

public:
   // Constructor with parameters
    FinanceManager(std::string user_name)
        : user_name(user_name) {}

// Функція для додавання нового гаманця
    void addWallet(std::string wallet_name, double balance, std::string type);
 
// Function for adding a new wallet
    void addFunds(const std::string& wallet_name, double amount);

// Function for adding an expense to the wallet
    void addExpense(std::string& wallet_name, std::string& category, double amount, std::string& date);

 // Function for checking the validity of the entered data for the operation of adding funds
    bool isValidFundsInput(const std::string wallet_name, double amount, const std::string type, const std::string amountStr);

// Function for checking the correctness of the entered date
    bool validDayOrMonthOrYear(const std::string dates);

// Function to check if the expense date belongs to the specified range
    bool isInDateRange(const std::string expenseDate, const std::string startDate, const std::string endDate);

// Function for saving the report to a file
    void saveReportsToFile(const std::string filename, const std::string period);
 
// Function for checking the validity of the entered data for the operation of adding a cost
    bool isValidExpenseInput(const std::string category, const std::string wallet_name, const std::string type, const std::string amountStr, double amount);

 // Function for generating an expense report
    void generateExpenseReport(const std::string period);

// Function to check if the date of the expense belongs to the specified year
    bool isInYear(const std::string expenseDate, int year);

 // A function to check if a string is a number
    bool isNumeric(const std::string amountStr);

// Function for saving transactions with funds to a file
    void saveFundsToFile(const std::string filename, const std::string date, double amount);

// Function to check if the year is a leap year
    bool isLeapYear(int year);
};
