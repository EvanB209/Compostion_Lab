//
// Created by evant on 10/2/2026.
//

#ifndef OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#include <string>


class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

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
    void setAccountHolderName(std::string accountHolderName);
    void deposit(double amount);
    virtual void withdraw(double amount);
    BankAccount();
    BankAccount(std::string accountNumber, std::string accountHolderName, double balance);
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};


#endif //OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
