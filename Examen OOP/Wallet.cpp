#include "Wallet.h"
#include "expense.h"

// Designer
Wallet::Wallet(const std::string& wallet_name, double balance, const std::string& type)
	: wallet_name(wallet_name), balance(balance), type(type) {}

// Method for adding an expense to the wallet
void Wallet::addExpense(const std::string& category, double amount, const std::string& date) {
	// Create an object of class Expense to represent an expense
	Expense expense(category, amount, date);

        // Add an expense to the list of expenses in your wallet
	expenses.push_back(expense);

	// Reduce the wallet balance by the amount of the expense
	balance -= amount;
}

// Method for adding funds to the wallet
void Wallet::addFunds(double amount)
{
       // Add the amount to the current wallet balance
	balance += amount;
}

// Method for getting the current wallet balance
double Wallet::getBalance() const
{
	return balance;
}

// Method for getting the wallet name
std::string Wallet::getWalletName() const
{
	return wallet_name;
}

// Method to get the type of wallet (for example, "Debit" or "Credit")
std::string Wallet::getType() const
{
	return type;
}

// Method for getting a list of expenses from a wallet
std::vector<Expense> Wallet::getExpenses() const
{
	return expenses;
}
