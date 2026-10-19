//
// Created by evant on 10/2/2026.
//

#ifndef OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#include <format>
#include <string>
#include <vector>

#include "Transaction.h"


class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
    std::vector<Transaction> transactionHistory;

public:
    std::string getAccountNumber() const;
    BankAccount(const BankAccount& other);
    virtual ~BankAccount() = default;   
    BankAccount& operator=(const BankAccount& other);
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;
    std::string getAccountHolderName() const;
    double getBalance() const;
    std::vector<Transaction> getTransactionHistory() const;
    void setAccountHolderName(std::string accountHolderName);
    void deposit(double amount);
    virtual void withdraw(double amount);
    BankAccount();
    BankAccount(std::string accountNumber, std::string accountHolderName, double balance);
    static void printAccount(const BankAccount& account);
    static void printHistory(const std::vector<Transaction>& history);
    static BankAccount createAccountFromInput();
};


#endif //OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
