#pragma once
#include "Wallet.h"
#include <string>
#include <map>
#include <vector>

class FinanceManager
{
private:
    std::string user_name;        // Ім'я 
    std::map<std::string, Wallet> wallets; // Гаманці користувача 
    std::string period;           // Період для  звіту
    std::string amountStr;        // Рядок для збереження суми
    std::string startDate;        // Початкова дата 
    std::string endDate;          // Кінцева дата 

public:
    // Конструктор з параметрами
    FinanceManager(std::string user_name)
        : user_name(user_name) {}

    // Функція для додавання нового гаманця
    void addWallet(std::string wallet_name, double balance, std::string type);

    // Функція для додавання коштів до гаманця
    void addFunds(const std::string& wallet_name, double amount);

    // Функція для додавання витрати до гаманця
    void addExpense(std::string& wallet_name, std::string& category, double amount, std::string& date);

    // Функція для перевірки валідності введених даних для операції додавання коштів
    bool isValidFundsInput(const std::string wallet_name, double amount, const std::string type, const std::string amountStr);

    // Функція для перевірки правильності введеної дати
    bool validDayOrMonthOrYear(const std::string dates);

    // Функція для перевірки, чи дата витрати належить до заданого діапазону
    bool isInDateRange(const std::string expenseDate, const std::string startDate, const std::string endDate);

    // Функція для збереження звіту у файл
    void saveReportsToFile(const std::string filename, const std::string period);

    // Функція для перевірки валідності введених даних для операції додавання витрати
    bool isValidExpenseInput(const std::string category, const std::string wallet_name, const std::string type, const std::string amountStr, double amount);

    // Функція для генерації звіту про витрати
    void generateExpenseReport(const std::string period);

    // Функція для перевірки, чи дата витрати належить до заданого року
    bool isInYear(const std::string expenseDate, int year);

    // Функція для перевірки, чи рядок є числом
    bool isNumeric(const std::string amountStr);

    // Функція для збереження операцій з коштами в файл
    void saveFundsToFile(const std::string filename, const std::string date, double amount);

    // Функція для перевірки, чи є рік високосним
    bool isLeapYear(int year);
};