#include <string>
#pragma once
class Expense
{
private:
    std::string category;   // Категорія витрати
    double amount;         // Сума витрати
    std::string date;      // Дата витрати 

public:
    // Конструктор 
   
    Expense(const std::string& category, double amount, const std::string& date);

    // Метод для отримання категорії витрати
    const std::string& getCategory() const;

    // Метод для отримання суми витрати
    double getAmount() const;

    // Метод для отримання дати витрати
    const std::string& getDate() const;
};

