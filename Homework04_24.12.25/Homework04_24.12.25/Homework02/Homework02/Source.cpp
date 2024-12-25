#include "Header.h"
#include <iostream>
#include <vector>
#include <string>
void ShowMenu() {
    std::cout << "\n--- Bank Application Menu ---\n";
    std::cout << "1. Add Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Show Account Information\n";
    std::cout << "5. Show All Accounts\n";
    std::cout << "6. Show Total Balance\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main(int argc, char* argv[]) {
    Bank bank;
    bool running = true;

    while (running) {
        ShowMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string accountNumber, accountHolder;
            double initialBalance;

            std::cout << "Enter account holder name: ";
            std::cin >> accountHolder;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;

            BankAccount newAccount(accountNumber, initialBalance, accountHolder);
            bank.AddAccount(newAccount);
            std::cout << "Account created successfully.\n";
            break;
        }
        case 2: {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;

            bool found = false;
            for (auto& account : bank.GetAccounts()) {
                if (account.GetAccountNumber() == accountNumber) {
                    account.Deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Account not found.\n";
            }
            break;
        }
        case 3: {
            std::string accountNumber;
            double amount;

            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;

            bool found = false;
            for (auto& account : bank.GetAccounts()) {
                if (account.GetAccountNumber() == accountNumber) {
                    account.Withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Account not found.\n";
            }
            break;
        }
        case 4: {
            std::string accountNumber;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;

            bool found = false;
            for (const auto& account : bank.GetAccounts()) {
                if (account.GetAccountNumber() == accountNumber) {
                    account.PrintAccountInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Account not found.\n";
            }
            break;
        }
        case 5:
            std::cout << "\nAll accounts in the bank:\n";
            bank.PrintAllAccounts();
            break;

        case 6:
            std::cout << "Total balance in the bank: " << bank.GetTotalBalance() << std::endl;
            break;

        case 0:
            running = false;
            std::cout << "Exiting application...\n";
            break;

        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return EXIT_SUCCESS;
}