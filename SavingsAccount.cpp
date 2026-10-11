//
// Created by evant on 10/10/2026.
//

#include "SavingsAccount.h"
SavingsAccount::SavingsAccount():  interestRate(0.0) {}
SavingsAccount::SavingsAccount(std::string accountNumber, std::string accountHolderName, double balance, double interestRate) : BankAccount(accountNumber, accountHolderName, balance),interestRate(interestRate) {}
void SavingsAccount::calculateInterest() {
    deposit(getBalance() * interestRate);
}
