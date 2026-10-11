//
// Created by evant on 10/2/2026.
//

#include "BankAccount.h"
//
// Created by evant on 9/23/2026.
//

#include "BankAccount.h"
#include <iostream>
using namespace std;
BankAccount::BankAccount() : balance(0.0){}

BankAccount::BankAccount(std::string accountNumber, std::string accountHolderName, double balance) {
    this-> accountNumber = accountNumber;
    this-> accountHolderName = accountHolderName;
    this-> balance = balance;
}
BankAccount& BankAccount::operator+=(double amount) {
    this-> balance = balance + amount;
}
BankAccount& BankAccount::operator-=(double amount) {
    this-> balance = balance - amount;
}
bool BankAccount::operator==(const BankAccount& other) const {
    return this-> accountNumber == other.accountNumber;
}
bool BankAccount::operator<(const BankAccount& other) const {
    return this-> balance < other.balance;
}
bool BankAccount::operator>(const BankAccount& other) const {
    return this-> balance > other.balance;
}
BankAccount::BankAccount(const BankAccount& other) {
    this-> accountNumber = other.accountNumber;
    this-> accountHolderName = other.accountHolderName;
    this-> balance = other.balance;
}
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        this-> accountNumber = other.getAccountNumber();
        this-> balance = other.getBalance();
        this-> accountHolderName = other.getAccountHolderName();
    }
    return *this;
}
void BankAccount::printAccount(const BankAccount& account) {
    std::cout <<"Account Number: "<< account.getAccountNumber()<< " Account Name: " << account.getAccountHolderName()<< " Account Balance: "<< account.getBalance()<< endl;
}
void BankAccount::deposit(double amount) {
    this-> balance = balance + amount;
}
BankAccount BankAccount::createAccountFromInput() {
    double newBalance;
    string newAccountNumber;
    string newAccountHolderName;
    cout<<"Enter Account Number: "<<endl;
    cin>>newAccountNumber;
    cout<<"Enter Account Holder Name: "<<endl;
    cin>>newAccountHolderName;
    cout<<"Enter Balance: "<<endl;
    cin>>newBalance;
    BankAccount account(newAccountNumber, newAccountHolderName, newBalance);
    return account;
}
void BankAccount::withdraw(double amount) {
    this-> balance = balance - amount;
}
double BankAccount::getBalance() const {
    return balance;
}
string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}
void BankAccount::setAccountHolderName(string newName) {
    this-> accountHolderName = newName;
}
string BankAccount::getAccountNumber() const {
    return accountNumber;
}

