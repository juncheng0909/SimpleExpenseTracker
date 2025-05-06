#include <iostream>
#include "../include/Account.h"

int main() {
    Account account;
    account.loadFromFile("data/transactions.csv");

    int choice;
    do {
        std::cout << "\n--- Simple Expense Tracker ---\n";
        std::cout << "1. Add transaction\n";
        std::cout << "2. View all transactions\n";
        std::cout << "3. Show total\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string date, category, desc;
            double amount;
            std::cout << "Date (YYYY-MM-DD): "; std::cin >> date;
            std::cout << "Category: "; std::cin >> category;
            std::cout << "Description: "; std::cin.ignore(); std::getline(std::cin, desc);
            std::cout << "Amount: "; std::cin >> amount;
            account.addTransaction(Transaction(date, category, desc, amount));
        } else if (choice == 2) {
            account.viewAll();
        } else if (choice == 3) {
            std::cout << "Total: " << account.getTotal() << "\n";
        }
    } while (choice != 0);

    account.saveToFile("data/transactions.csv");
    return 0;
}
