# BankAccount Class

A C++ class for representing a bank account in a banking system

## Data Dictionary

| Attribute     | Data Type     | Description                    |
|---------------|---------------|--------------------------------|
| `accountNumber`       | `std::string` | The number that identifies the account.              |
| `accountHolderName`      | `std::string` | The name of the account holder.             |
| `balance`        | `double` | The balance in dollars in the account.        |

## Methods List

| Method Signature             | Return Type   | Description               |
|------------------------------|---------------|---------------------------|
| `BankAccount()`                     | (Constructor) | Default constructor.      |
| `BankAccount(accountNumber, accountHolderName, balance)`  | (Constructor) | Parameterized constructor.|
| `getBalance() const`           | `double` | Gets the account's balance.    |
| `getAccountHolderName() const`          | `std::string` | Gets the account holder's name.   |
| `getAccountNumber() const`        | `std::string`        | Gets the account's identification number      |
| `deposit(amount)`                 | `void`        | Deposits the stated amount into account     |
| `withdraw(amount)`               | `void`        | Withdraws the stated amount from account         |
| `setAccountHolderName(accountHolderName)`                | `void`        |Sets the name of the account holder        |
| `static void printAccount(const BankAccount& account)`| `void` | Prints the account passed|
| `    static BankAccount createAccountFromInput()`| `BankAccount` | Creates a BankAccount object from user input|