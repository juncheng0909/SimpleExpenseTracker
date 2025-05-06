#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string d, std::string c, std::string desc, double amt)
    : date(d), category(c), description(desc), amount(amt) {}

void Transaction::display() const {
    std::cout << date << " | " << category << " | " << description << " | " << amount << "\n";
}

std::string Transaction::toCSV() const {
    return date + "," + category + "," + description + "," + std::to_string(amount);
}

double Transaction::getAmount() const {
    return amount;
}