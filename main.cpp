#include "BankAccount.h"
#include <iostream>
#include <vector>

#include "CheckingAccount.h"
#include "SavingsAccount.h"


int main() {
    std::vector<BankAccount*> accounts;
    int choice = 0;
    int accountChoice(1);
    bool quit = false;
    BankAccount currAccount;
    double amount;



    do  {
        std::cout << "Pick a Choice:"<< std::endl;
        std::cout << "1. Display all accounts"<< std::endl;
        std::cout << "2. Enter New Simple Account"<< std::endl;
        std::cout << "3. Select Account from List"<< std::endl;
        std::cout << "4. Change the Name of the Account Holder of the Selected Account"<< std::endl;
        std::cout << "5. Make a Deposit"<< std::endl;
        std::cout << "6. Make a Withdrawal"<< std::endl;
        std::cout << "7. Print Current Account"<< std::endl;
        std::cout << "8. Print Current Account's Transaction Historr"<< std::endl;
        std::cout << "9. Quit"<< std::endl;
        std::cin>> choice;
        switch (choice) {
            case 1: {
                std::cout << "The Current Accounts Are:" << std::endl;
                for (size_t i = 0; i < accounts.size(); i++) {
                    std::cout << i+1 << ") Account Number: " << accounts.at(i)->getAccountNumber()
                              << ", Account Holder: " << accounts.at(i)->getAccountHolderName()
                              << ", Balance: " << accounts.at(i)->getBalance() << std::endl;
                }
                break;

            }
            case 2:{
                std::cout << "Account type: 1. Basic  2. Checking  3. Savings" << std::endl;
                int type;
                std::cin >> type;

                // Gets number, name, and balance
                BankAccount base = BankAccount::createAccountFromInput();

                switch (type) {
                    case 1:
                        accounts.push_back(new BankAccount(base));
                        break;
                    case 2: {
                        double fee;
                        std::cout << "Enter Transaction Fee: " << std::endl;
                        std::cin >> fee;
                        accounts.push_back(new CheckingAccount(base.getAccountNumber(),
                            base.getAccountHolderName(), base.getBalance(), fee));
                        break;
                    }
                    case 3: {
                        double rate;
                        std::cout << "Enter Interest Rate (e.g. 0.03 for 3%): " << std::endl;
                        std::cin >> rate;
                        accounts.push_back(new SavingsAccount(base.getAccountNumber(),
                            base.getAccountHolderName(), base.getBalance(), rate));
                        break;
                    }
                    default:
                        std::cout << "Invalid account type" << std::endl;
                }
                break;


            }

            case 3: {
                std::cout<<"Select Account Based on the corresponding number on the list:"<< std::endl;
                for (int i = 0; i < accounts.size(); i++) {
                    std::cout << i+1 <<") Account Number: " << accounts.at(i)->getAccountNumber()<< ", Account Holder: "<<
                        accounts.at(i)->getAccountHolderName() << ", Balance:" << accounts.at(i)->getBalance()<< std::endl;
                }
                std::cin>>accountChoice;

                std::cout<<"The Account you Have Chosen Belongs to : "<< accounts.at(accountChoice-1)->getAccountHolderName()<< std::endl;
                break;
            }
            case 4: {
                std::cout<<"Enter The Name you Wish to Change the Current Account to: "<< std::endl;
                std::string newName;
                std::cin>>newName;
                accounts.at(accountChoice-1)->setAccountHolderName(newName);
                std::cout<<"The Account is now set to: "<< accounts.at(accountChoice-1)->getAccountHolderName()<< std::endl;
                break;
            }
            case 5: {
                std::cout<<"Enter the Amount to be Deposited into "<<accounts.at(accountChoice-1)->getAccountHolderName()<<"'s Account:" << std::endl;
                std::cin>>amount;
                accounts.at(accountChoice-1)->deposit(amount);
                std::cout<<"You have deposited $"<< amount << " into the Account of "
                << accounts.at(accountChoice-1)->getAccountHolderName()<< " making the total $"<< accounts.at(accountChoice-1)->getBalance()<< std::endl;
                break;


            }
            case 6: {
                std::cout<<"Enter the Amount to be Withdrawn from "<<accounts.at(accountChoice-1)->getAccountHolderName()<<"'s Account:"<< std::endl;
                std::cin>>amount;
                if (accounts.at(accountChoice-1)->getBalance()>=amount) {
                    accounts.at(accountChoice-1)->withdraw(amount);
                    std::cout<<"You have Withdrawn $"<< amount << " from the Account of "
                    << accounts.at(accountChoice-1)->getAccountHolderName()<< " making the total $"<< accounts.at(accountChoice-1)->getBalance()<< std::endl;
                }else {
                    std::cout<<"Insufficient Funds"<< std::endl;
                }
                break;
            }

            case 7: {
                BankAccount::printAccount(*accounts.at(accountChoice-1));
                break;
            }
            case 8: {
                BankAccount::printHistory(accounts.at(accountChoice-1)->getTransactionHistory());
                break;
            }
            case 9: {
                std::cout<<"Exiting Program!"<< std::endl;
                quit = true;
                break;
            }

            default: std::cout<<"Incorrect entry"<<std::endl;

        }


    }while (!quit);




    return 0;
}
