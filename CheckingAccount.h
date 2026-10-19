//
// Created by evant on 10/10/2026.
//

#ifndef INHERITANCE_CHECKINGACCOUNT_H
#define INHERITANCE_CHECKINGACCOUNT_H
#include <vector>

#include "BankAccount.h"
#include "Transaction.h"


class CheckingAccount : public BankAccount {
public:
    CheckingAccount();
    CheckingAccount(std::string accountNumber, std::string accountHolderName, double balance, double transactionFees);
    void withdraw(double amount) override;
private:
    double transactionFees;

};


#endif //INHERITANCE_CHECKINGACCOUNT_H
