#include "Wallet.h"
#include "expense.h"

// Конструктор
Wallet::Wallet(const std::string& wallet_name, double balance, const std::string& type)
	: wallet_name(wallet_name), balance(balance), type(type) {}

// Метод для додавання витрати до гаманця
void Wallet::addExpense(const std::string& category, double amount, const std::string& date) {
	// Створюємо об'єкт класу Expense, щоб представити витрату
	Expense expense(category, amount, date);

	// Додаємо витрату до списку витрат у гаманці
	expenses.push_back(expense);

	// Зменшуємо баланс гаманця на суму витрати
	balance -= amount;
}

// Метод для додавання коштів до гаманця
void Wallet::addFunds(double amount)
{
	// Додаємо суму до поточного балансу гаманця
	balance += amount;
}

// Метод для отримання поточного балансу гаманця
double Wallet::getBalance() const
{
	return balance;
}

// Метод для отримання назви гаманця
std::string Wallet::getWalletName() const
{
	return wallet_name;
}

// Метод для отримання типу гаманця (наприклад, "Debit" або "Credit")
std::string Wallet::getType() const
{
	return type;
}

// Метод для отримання списку витрат у гаманця
std::vector<Expense> Wallet::getExpenses() const
{
	return expenses;
}