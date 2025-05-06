#pragma once
#include <vector>
#include "Transaction.h"

class Account {
private:
    std::vector<Transaction> transactions;

public:
    void addTransaction(const Transaction& t);
    void viewAll() const;
    double getTotal() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};