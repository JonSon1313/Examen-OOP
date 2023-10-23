#pragma once
#include <string>
#include <vector>
#include "Expense.h"

class Wallet
{
private:
    std::string wallet_name;     // Name wallet
    std::string type;            // Type wallet 
    double balance;              // Balance wallet
    std::vector<Expense> expenses; //List of expenses in your wallet 

public:
    // Constructor, initialises all members of the class
    Wallet() : wallet_name(""), balance(0.0) {}

    // Constructor with parameters, initialises a wallet with the specified name, balance and type
    Wallet(const std::string& wallet_name, double balance, const std::string& type);

    // Method for adding an expense to the wallet
    void addExpense(const std::string& category, double amount, const std::string& date);

   // Method for adding funds to the wallet
    void addFunds(double amount);

   // Method for getting the current wallet balance
    double getBalance() const;

   // Method for getting the wallet name
    std::string getWalletName() const;

    // Method for getting the wallet type
    std::string getType() const;

    // Method for getting a list of expenses from a wallet
    std::vector<Expense> getExpenses() const;
};
