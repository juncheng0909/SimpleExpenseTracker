#pragma once
#include <string>

class Transaction {
private:
    std::string date;
    std::string category;
    std::string description;
    double amount;

public:
    Transaction(std::string date, std::string category, std::string description, double amount);
    void display() const;
    std::string toCSV() const;
    double getAmount() const;
};