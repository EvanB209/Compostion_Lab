//
// Created by evant on 10/10/2026.
//

#ifndef OPERATOR_OVERLOAD_LAB_SAVINGSACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_SAVINGSACCOUNT_H
#include "BankAccount.h"


class SavingsAccount : public BankAccount  {
public:
    SavingsAccount();
    SavingsAccount(std::string accountNumber, std::string accountHolderName, double balance, double interestRate);
    void calculateInterest();
private:
    double interestRate;
};


#endif //OPERATOR_OVERLOAD_LAB_SAVINGSACCOUNT_H
