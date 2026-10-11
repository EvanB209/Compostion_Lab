//
// Created by evant on 10/10/2026.
//

#include "CheckingAccount.h"
CheckingAccount::CheckingAccount():  transactionFees(0.0) {}
CheckingAccount::CheckingAccount(std::string accountNumber, std::string accountHolderName, double balance, double transactionFees) : BankAccount(accountNumber, accountHolderName, balance),transactionFees(transactionFees) {}
void CheckingAccount::withdraw(double amount) {
    BankAccount::withdraw(amount + transactionFees);
}