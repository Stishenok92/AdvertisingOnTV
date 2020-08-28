#pragma once
#include "Header.h"

void menuTelecast(TelevisionAgency&);
void menuAdvertiser(TelevisionAgency& agency);
void menuDiscount(TelevisionAgency& agency);
void menuOrder(TelevisionAgency& agency);

void menuTelecast(TelevisionAgency& agency)
{
    bool flag = false;
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Print all telecasts\n"
        << "2. Add telecast\n"
        << "3. Edit telecast\n"
        << "4. Erase telecast\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                break;
            case 1:
                agency.printTelecast(std::cout);
                break;
            case 2:
                agency.addTelecast();
                break;
            case 3:
                agency.editTelecast();
                break;
            case 4:
                agency.eraseTelecast();
                break;
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flag)
            break;
    }
}

void menuAdvertiser(TelevisionAgency& agency)
{
    bool flag = false;
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Print all advertisers\n"
        << "2. Add advertiser\n"
        << "3. Edit advertiser\n"
        << "4. Erase advertiser\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                break;
            case 1:
                agency.printAdvertiser(std::cout);
                break;
            case 2:
                agency.addAdvertiser();
                break;
            case 3:
                agency.editAdvertiser();
                break;
            case 4:
                agency.eraseAdvertiser();
                break;
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flag)
            break;
    }
}

void menuDiscount(TelevisionAgency& agency)
{
    bool flag = false;
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Print all discounts\n"
        << "2. Add discount\n"
        << "3. Edit discount\n"
        << "4. Erase discount\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                break;
            case 1:
                agency.printDiscount(std::cout);
                break;
            case 2:
                agency.addDiscount();
                break;
            case 3:
                agency.editDiscount();
                break;
            case 4:
                agency.eraseDiscount();
                break;
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flag)
            break;
    }
}

void menuOrder(TelevisionAgency& agency)
{
    bool flag = false;
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Print all orders\n"
        << "2. Print orders by company\n"
        << "3. Add order\n"
        << "4. Erase order\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
                flag = true;
                break;
            case 1:
                agency.printOrder(std::cout);
                break;
            case 2:
                agency.printOrderByCompany(std::cout);
                break;
            case 3:
                agency.addOrder();
                break;
            case 4:
                agency.eraseOrder();
                break;
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flag)
        break;
    }
}
