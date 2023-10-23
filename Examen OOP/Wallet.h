#pragma once
#include <string>
#include <vector>
#include "Expense.h"

class Wallet
{
private:
    std::string wallet_name;     // Назва гаманця
    std::string type;            // Тип гаманця 
    double balance;              // Баланс гаманця
    std::vector<Expense> expenses; // Список витрат у гаманці

public:
    // Конструктор за замовчуванням, ініціалізує всі члени класу
    Wallet() : wallet_name(""), balance(0.0) {}

    // Конструктор з параметрами, ініціалізує гаманець з вказаною назвою, балансом і типом
    Wallet(const std::string& wallet_name, double balance, const std::string& type);

    // Метод для додавання витрати до гаманця
    void addExpense(const std::string& category, double amount, const std::string& date);

    // Метод для додавання коштів до гаманця
    void addFunds(double amount);

    // Метод для отримання поточного балансу гаманця
    double getBalance() const;

    // Метод для отримання назви гаманця
    std::string getWalletName() const;

    // Метод для отримання типу гаманця
    std::string getType() const;

    // Метод для отримання списку витрат у гаманця
    std::vector<Expense> getExpenses() const;
};