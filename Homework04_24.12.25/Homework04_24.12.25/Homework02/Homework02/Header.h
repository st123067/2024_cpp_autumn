#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string accountHolder;

public:
    BankAccount(const std::string& accNum, double bal, const std::string& holder)
        : accountNumber(accNum), balance(bal), accountHolder(holder) {}

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << std::endl;
        }
    }

    void Withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    double GetBalance() const {
        return balance;
    }

    std::string GetAccountHolder() const {
        return accountHolder;
    }

    std::string GetAccountNumber() const {
        return accountNumber;
    }

    void PrintAccountInfo() const {
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void AddAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    std::vector<BankAccount>& GetAccounts() {
        return accounts;
    }

    double GetTotalBalance() const {
        double total = 0;
        for (const auto& account : accounts) {
            total += account.GetBalance();
        }
        return total;
    }

    void PrintAllAccounts() const {
        for (const auto& account : accounts) {
            account.PrintAccountInfo();
            std::cout << "-----------------------------" << std::endl;
        }
    }
};

#endif