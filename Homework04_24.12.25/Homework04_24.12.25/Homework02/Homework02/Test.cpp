#include "gtest/gtest.h"
#include "Header.h"

TEST(BankAccountTests, CreateAccount) {
    BankAccount account("12345", 100.0, "John Doe");
    EXPECT_EQ(account.GetAccountNumber(), "12345");
    EXPECT_EQ(account.GetBalance(), 100.0);
    EXPECT_EQ(account.GetAccountHolder(), "John Doe");
}

TEST(BankAccountTests, Deposit) {
    BankAccount account("12345", 100.0, "John Doe");
    account.Deposit(50.0);
    EXPECT_EQ(account.GetBalance(), 150.0);
}

TEST(BankAccountTests, Withdraw) {
    BankAccount account("12345", 100.0, "John Doe");
    account.Withdraw(30.0);
    EXPECT_EQ(account.GetBalance(), 70.0);
    account.Withdraw(100.0);
    EXPECT_EQ(account.GetBalance(), 70.0); 
}

TEST(BankTests, AddAndRetrieveAccounts) {
    Bank bank;
    BankAccount account1("12345", 100.0, "John Doe");
    BankAccount account2("67890", 200.0, "Jane Smith");
    bank.AddAccount(account1);
    bank.AddAccount(account2);
    auto& accounts = bank.GetAccounts();
    EXPECT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0].GetAccountNumber(), "12345");
    EXPECT_EQ(accounts[1].GetAccountNumber(), "67890");
}

TEST(BankTests, GetTotalBalance) {
    Bank bank;
    bank.AddAccount(BankAccount("12345", 100.0, "John Doe"));
    bank.AddAccount(BankAccount("67890", 200.0, "Jane Smith"));
    EXPECT_EQ(bank.GetTotalBalance(), 300.0);
}
