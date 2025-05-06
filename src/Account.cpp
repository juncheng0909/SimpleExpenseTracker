#include "Account.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Account::addTransaction(const Transaction& t) {
    transactions.push_back(t);
}

void Account::viewAll() const {
    for (const auto& t : transactions) {
        t.display();
    }
}

double Account::getTotal() const {
    double sum = 0;
    for (const auto& t : transactions) {
        sum += t.getAmount();
    }
    return sum;
}

void Account::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& t : transactions) {
        file << t.toCSV() << "\n";
    }
    file.close();
}

void Account::loadFromFile(const std::string& filename) {
    transactions.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, category, description, amountStr;
        std::getline(ss, date, ',');
        std::getline(ss, category, ',');
        std::getline(ss, description, ',');
        std::getline(ss, amountStr, ',');
        double amount = std::stod(amountStr);
        Transaction t(date, category, description, amount);
        transactions.push_back(t);
    }
}
