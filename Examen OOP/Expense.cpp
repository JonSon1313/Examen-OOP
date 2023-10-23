#include "Expense.h"
//constructor 
Expense::Expense(const std::string& category, double amount, const std::string& date)
    : category(category), amount(amount), date(date) {}

// Method to get the category of costs
const std::string& Expense::getCategory() const 
{
    return category;
}
//Method for getting the sum of costs
double Expense::getAmount() const 
{
    return amount;

}
//Method for obtaining the date of expenditure 
const std::string& Expense::getDate() const 
{
    return date;
}
