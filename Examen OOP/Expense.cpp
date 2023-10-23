#include "Expense.h"
//конструктор 
Expense::Expense(const std::string& category, double amount, const std::string& date)
    : category(category), amount(amount), date(date) {}

// Метод для отримання категорії витрат
const std::string& Expense::getCategory() const 
{
    return category;
}
//Метод для отримання суми витрат
double Expense::getAmount() const 
{
    return amount;

}
//Метод для отримання дати витрати 
const std::string& Expense::getDate() const 
{
    return date;
}