#include <string>
#pragma once
class Expense
{
private:
    std::string category; // 
    double amount; // Amount
    std::string date; // 

public:
    // Constructor 
   
    Expense(const std::string& category, double amount, const std::string& date);

    // Method for obtaining the category of expenditure
    const std::string& getCategory() const;

    // Method for obtaining the amount of consumption
    double getAmount() const;

    // Method for obtaining the amount of value
    const std::string& getDate() const;
};
