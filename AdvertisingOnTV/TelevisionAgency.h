#pragma once
#include "Header.h"

class TelevisionAgency
{
private:
    std::vector<Telecast> telecasts;
    std::vector<Advertiser> advertisers;
    std::vector<Discount> discounts;
    std::vector<Order> orders;
public:
    TelevisionAgency() = default;
    ~TelevisionAgency() = default;
    
    bool isEmptyTelecasts() const;
    bool isEmptyAdvertisers() const;
    bool isEmptyDiscounts() const;
    bool isEmptyOrders() const;
    
    void readTelecast(const std::string&);
    void readAdvertiser(const std::string&);
    void readDiscount(const std::string&);
    void readOrder(const std::string&);
    
    void printTelecast(std::ostream&) const;
    void printAdvertiser(std::ostream&) const;
    void printDiscount(std::ostream&) const;
    void printOrder(std::ostream&) const;
    void printOrderByCompany(std::ostream&) const;
    
    void saveTelecast(const std::string&) const;
    void saveAdvertiser(const std::string&) const;
    void saveDiscount(const std::string&) const;
    void saveOrder(const std::string&) const;
    
    void addTelecast();
    void addAdvertiser();
    void addDiscount();
    void addOrder();
    
    void editTelecast();
    void editAdvertiser();
    void editDiscount();
    
    void eraseTelecast();
    void eraseAdvertiser();
    void eraseDiscount();
    void eraseOrder();
    
    void sortTelecast();
    void sortAdvertiser();
    void sortDiscount();
    void sortOrder();
    
    void profit();
};

void TelevisionAgency:: readTelecast(const std::string& file)
{
    std::ifstream in(file);
    checkFile(in);
    std::copy(std::istream_iterator<Telecast>(in), std::istream_iterator<Telecast>(), std::back_inserter(telecasts));
}

void TelevisionAgency:: readAdvertiser(const std::string& file)
{
    std::ifstream in(file);
    checkFile(in);
    std::copy(std::istream_iterator<Advertiser>(in), std::istream_iterator<Advertiser>(), std::back_inserter(advertisers));
}

void TelevisionAgency:: readDiscount(const std::string& file)
{
    std::ifstream in(file);
    checkFile(in);
    std::copy(std::istream_iterator<Discount>(in), std::istream_iterator<Discount>(), std::back_inserter(discounts));
}

void TelevisionAgency:: readOrder(const std::string& file)
{
    std::ifstream in(file);
    checkFile(in);
    std::copy(std::istream_iterator<Order>(in), std::istream_iterator<Order>(), std::back_inserter(orders));
}

void TelevisionAgency:: printTelecast(std::ostream& out) const
{
    if (isEmptyTelecasts())
        return;
    
    size_t number = 0;
    manipHeaderTelecast(out);
    std::for_each(telecasts.begin(), telecasts.end(), [&out, &number] (Telecast telecast) { out << std::setw(8) << ++number << telecast << "\n"; });
    manipTailTelecast(out);
}

void TelevisionAgency:: printAdvertiser(std::ostream& out) const
{
    if (isEmptyAdvertisers())
        return;
    
    size_t number = 0;
    manipHeaderAdvertiser(out);
    std::for_each(advertisers.begin(), advertisers.end(), [&out, &number] (Advertiser advertiser) { out << std::setw(8) << ++number << advertiser << "\n"; });
    manipTailAdvertiser(out);
}

void TelevisionAgency:: printDiscount(std::ostream& out) const
{
    if (isEmptyDiscounts())
        return;
    
    size_t number = 0;
    manipHeaderDiscount(out);
    std::for_each(discounts.begin(), discounts.end(), [&out, &number] (Discount discount) { out << std::setw(8) << ++number << discount << "\n"; });
    manipTailDiscount(out);
}

void TelevisionAgency:: printOrder(std::ostream& out) const
{
    if (isEmptyOrders())
        return;
    
    size_t number = 0;
    manipHeaderOrder(out);
    std::for_each(orders.begin(), orders.end(), [&out, &number] (Order order) { out << std::setw(8) << ++number << order << "\n"; });
    manipTailOrder(out);
}

void TelevisionAgency:: saveTelecast(const std::string& file) const
{
    if (isEmptyTelecasts())
        return;
    
    std::ofstream out(file);
    std::for_each(telecasts.begin(), telecasts.end(), [&out] (Telecast telecast) { out << telecast << "\n"; });
    out.close();
}

void TelevisionAgency:: saveAdvertiser(const std::string& file) const
{
    if (isEmptyAdvertisers())
        return;
    
    std::ofstream out(file);
    std::for_each(advertisers.begin(), advertisers.end(), [&out] (Advertiser advertiser) { out << advertiser << "\n"; });
    out.close();
}

void TelevisionAgency:: saveDiscount(const std::string& file) const
{
    if (isEmptyDiscounts())
        return;
    
    std::ofstream out(file);
    std::for_each(discounts.begin(), discounts.end(), [&out] (Discount discount) { out << discount << "\n"; });
    out.close();
}

void TelevisionAgency:: saveOrder(const std::string& file) const
{
    if (isEmptyOrders())
        return;
    
    std::ofstream out(file);
    std::for_each(orders.begin(), orders.end(), [&out] (Order order) { out << order << "\n"; });
    out.close();
}

bool TelevisionAgency:: isEmptyTelecasts() const
{
    if (telecasts.size())
        return false;
    
    std::cout << "\nTelecasts is empty!\n";
    return true;
}

bool TelevisionAgency:: isEmptyAdvertisers() const
{
    if (advertisers.size())
        return false;
    
    std::cout << "\nAdvertisers is empty!\n";
    return true;
}

bool TelevisionAgency:: isEmptyDiscounts() const
{
    if (discounts.size())
        return false;
    
    std::cout << "\nDiscounts is empty!\n";
    return true;
}

bool TelevisionAgency:: isEmptyOrders() const
{
    if (orders.size())
        return false;
    
    std::cout << "\nOrders is empty!\n";
    return true;
}

void TelevisionAgency:: addTelecast()
{
    std::string numberChannel, name, airTime, surnameHost;
    size_t maxMinuteAds, pause;
    double costMinuteAds;
    std::cout << "\nEnter number channel: ";
    std::cin >> numberChannel;
    std::cout << "Enter name telecast: ";
    std::cin >> name;
    std::cout << "Enter airtime: ";
    std::cin >> airTime;
    std::cout << "Enter cost minute ads: ";
    std::cin >> costMinuteAds;
    std::cout << "Enter max minutes ads: ";
    std::cin >> maxMinuteAds;
    std::cout << "Enter amount pauses: ";
    std::cin >> pause;
    std::cout << "Enter surname presenter: ";
    std::cin >> surnameHost;
    telecasts.push_back(Telecast(numberChannel, name, airTime, costMinuteAds, maxMinuteAds, pause, surnameHost));
    sortTelecast();
    saveTelecast(fileTelecast);
    std::cout << "\nTelecast added successfully!\n";
}

void TelevisionAgency:: editTelecast()
{
    printTelecast(std::cout);
    
    if (telecasts.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number telecast: ";
        std::cin >> number;
        --number;
        
        if(number < telecasts.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    bool flagExit = false, flagSave = false;
    
    
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Edit number chanell\n"
        << "2. Edit name telecast\n"
        << "3. Edit airtime\n"
        << "4. Edit cost minute\n"
        << "5. Edit max minutes\n"
        << "6. Edit amount pauses\n"
        << "7. Edit surname presenter\n"
        << "8. Print telecast\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
            {
                flagExit = true;
                break;
            }
            case 1:
            {
                std::string str;
                std::cout << "\nEnter new number chanell: ";
                std::cin >> str;
                telecasts[number].setNumberChannel(str);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 2:
            {
                std::string str;
                std::cout << "\nEnter new name telecast: ";
                std::cin >> str;
                telecasts[number].setName(str);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 3:
            {
                std::string str;
                std::cout << "\nEnter new airtime: ";
                std::cin >> str;
                telecasts[number].setAirTime(str);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 4:
            {
                double num;
                std::cout << "\nEnter new cost minute: ";
                std::cin >> num;
                telecasts[number].setCostMinuteAds(num);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 5:
            {
                size_t num;
                std::cout << "\nEnter new max minutes: ";
                std::cin >> num;
                telecasts[number].setMaxMinuteAds(num);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 6:
            {
                size_t num;
                std::cout << "\nEnter new amount pauses: ";
                std::cin >> num;
                telecasts[number].setPause(num);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 7:
            {
                std::string str;
                std::cout << "\nEnter new surname presenter: ";
                std::cin >> str;
                telecasts[number].setSurnameHost(str);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 8:
            {
                manipHeaderTelecastNotIndex(std::cout);
                std::cout << telecasts[number] << "\n";
                manipTailTelecastNotIndex(std::cout);
                break;
            }
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flagExit)
        {
            sortTelecast();
            
            if(flagSave)
                saveTelecast(fileTelecast);
                
            break;
        }
    }
}

void TelevisionAgency:: eraseTelecast()
{
    printTelecast(std::cout);
    
    if (telecasts.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number telecast: ";
        std::cin >> number;
        --number;
        
        if(number < telecasts.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    telecasts.erase(telecasts.begin()+number);
    saveTelecast(fileTelecast);
    std::cout << "\nTelecast deleted successfully!\n";
}

void TelevisionAgency:: eraseOrder()
{
    printOrder(std::cout);
    
    if (orders.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number order: ";
        std::cin >> number;
        --number;
        
        if(number < orders.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    orders.erase(orders.begin()+number);
    saveOrder(fileOrder);
    std::cout << "\nOrder deleted successfully!\n";
}

void TelevisionAgency:: addAdvertiser()
{
    std::string nameCompany, nameProduct;
    size_t discount = 0;
    std::cout << "\nEnter name company: ";
    std::cin >> nameCompany;
    std::cout << "\nSearch discount for company.\nPlease wait...\n";
    auto it = std::find_if(discounts.begin(), discounts.end(), [nameCompany] (Discount discount) { return toLower(discount.getNameCompany()) == toLower(nameCompany); });
    
    if (it != discounts.end())
    {
        std::cout << "\nThis company has " << it->getDiscount() << " percent discount.\n";
    }
    else
    {
        std::cout << "\nThis company has no discount.\n\nPlease enter discount: ";
        std::cin >> discount;
        discounts.push_back(Discount(nameCompany, discount));
        sortDiscount();
        saveDiscount(fileDiscount);
        std::cout << "\nAdvertiser added successfully!\n";
    }
    
    std::cout << "\nEnter name product: ";
    std::cin >> nameProduct;
    
    it = std::find_if(advertisers.begin(), advertisers.end(), [nameCompany, nameProduct] (Advertiser advertiser)
    {
        return ((toLower(advertiser.getNameCompany()) == toLower(nameCompany)) && (toLower(advertiser.getNameProduct()) == toLower(nameProduct)));
    });
    
    if(it != advertisers.end())
    {
        std::cout << "\nProduct of this company is already!\n";
        return;
    }
    
    advertisers.push_back(Advertiser(nameCompany, discount, nameProduct));
    sortAdvertiser();
    saveAdvertiser(fileAdvertiser);
    std::cout << "\nAdvertiser added successfully!\n";
}


void TelevisionAgency:: sortTelecast()
{
    std::sort(telecasts.begin(), telecasts.end(), [] (Telecast a, Telecast b)
              {
        if (a.getNumberChannel() == b.getNumberChannel())
        {
            return a.getAirTime() < b.getAirTime();
        }
        else
        {
            return a.getNumberChannel() < b.getNumberChannel();
        }
    });
}

void TelevisionAgency:: sortDiscount()
{
    std::sort(discounts.begin(), discounts.end(), [] (Discount a, Discount b) { return a.getNameCompany() < b.getNameCompany(); });
}

void TelevisionAgency:: sortAdvertiser()
{
    std::sort(advertisers.begin(), advertisers.end(), [] (Advertiser a, Advertiser b)
    {
            if (a.getNameCompany() == b.getNameCompany())
            {
                return a.getNameProduct() < b.getNameProduct();
            }
            else
            {
                return a.getNameCompany() < b.getNameCompany();
            }
    });
}


void TelevisionAgency:: sortOrder()
{
    std::sort(orders.begin(), orders.end(), [] (Order a, Order b)
              {
        if (a.getAirDay() == b.getAirDay())
        {
            return a.getAirTime() < b.getAirTime();
        }
        else
        {
            return a.getAirDay() < b.getAirDay();
        }
    });
}





void TelevisionAgency:: editAdvertiser()
{
    printAdvertiser(std::cout);
    
    if (advertisers.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number advertiser: ";
        std::cin >> number;
        --number;
        
        if(number < advertisers.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    bool flagExit = false, flagSave = false;
    
    
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Edit name company\n"
        << "2. Edit name product\n"
        << "3. Print advertiser\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
            {
                flagExit = true;
                break;
            }
            case 1:
            {
                std::string newNameCompany;
                std::cout << "\nEnter new name company: ";
                std::cin >> newNameCompany;
                std::string nameProduct = advertisers[number].getNameProduct();
                
                auto it = std::find_if(advertisers.begin(), advertisers.end(), [newNameCompany, nameProduct] (Advertiser advertiser)
                {
                    return ((toLower(advertiser.getNameCompany()) == toLower(newNameCompany)) && (toLower(advertiser.getNameProduct()) == toLower(nameProduct)));
                });
                
                if(it != advertisers.end())
                {
                    std::cout << "\nError! This company already has such a product!\n";
                    break;
                }
                
                advertisers[number].setNameCompany(newNameCompany);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 2:
            {
                std::string newNameProduct;
                std::cout << "\nEnter new name product: ";
                std::cin >> newNameProduct;
                std::string nameCompany = advertisers[number].getNameCompany();
                
                auto it = std::find_if(advertisers.begin(), advertisers.end(), [nameCompany, newNameProduct] (Advertiser advertiser)
                {
                    return ((toLower(advertiser.getNameCompany()) == toLower(nameCompany)) && (toLower(advertiser.getNameProduct()) == toLower(newNameProduct)));
                });
                
                if(it != advertisers.end())
                {
                    std::cout << "\nError! This company already has such a product!\n";
                    break;
                }
                
                advertisers[number].setNameProduct(newNameProduct);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 3:
            {
                manipHeaderAdvertiserNotIndex(std::cout);
                std::cout << advertisers[number] << "\n";
                manipTailAdvertiserNotIndex(std::cout);
                break;
            }
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flagExit)
        {
            sortAdvertiser();
            
            if(flagSave)
                saveAdvertiser(fileAdvertiser);
            
            break;
        }
    }
}

void TelevisionAgency:: eraseAdvertiser()
{
    printAdvertiser(std::cout);
    
    if (advertisers.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number advertiser: ";
        std::cin >> number;
        --number;
        
        if(number < advertisers.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    advertisers.erase(advertisers.begin()+number);
    saveAdvertiser(fileAdvertiser);
    std::cout << "\nAdvertiser deleted successfully!\n";
}

void TelevisionAgency:: addDiscount()
{
    std::string nameCompany;
    size_t discount = 0;
    std::cout << "\nEnter name company: ";
    std::cin >> nameCompany;
    std::cout << "\nSearch discount for company.\nPlease wait...\n";
    
    auto it = std::find_if(discounts.begin(), discounts.end(), [nameCompany] (Discount discount) { return toLower(discount.getNameCompany()) == toLower(nameCompany); });
    
    if (it != discounts.end())
    {
        std::cout << "\nThis company has " << it->getDiscount() << " percent discount.\n";
    }
    else
    {
        std::cout << "\nThis company has no discount.\n\nPlease enter discount: ";
        std::cin >> discount;
        discounts.push_back(Discount(nameCompany, discount));
        sortDiscount();
        saveDiscount(fileDiscount);
        std::cout << "\nDiscount added successfully!\n";
    }
}

void TelevisionAgency:: editDiscount()
{
    printDiscount(std::cout);
    
    if (advertisers.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number discount: ";
        std::cin >> number;
        --number;
        
        if(number < discounts.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    bool flagExit = false, flagSave = false;
    
    
    while (true)
    {
        size_t operation;
        std::cout << "\nOperations:\n"
        << "1. Edit name company\n"
        << "2. Edit discount\n"
        << "3. Print advertiser\n"
        << "0. <-...\n"
        << "\nSelect number operation: ";
        std::cin >> operation;
        
        switch (operation)
        {
            case 0:
            {
                flagExit = true;
                break;
            }
            case 1:
            {
                std::string newNameCompany;
                std::cout << "\nEnter new name company: ";
                std::cin >> newNameCompany;
                
                auto it = std::find_if(discounts.begin(), discounts.end(), [newNameCompany] (Discount discount)
                {
                    return toLower(discount.getNameCompany()) == toLower(newNameCompany);
                });
                
                if (it != discounts.end())
                {
                    std::cout << "\nError! This company already has discount!\n";
                    break;
                }
                
                discounts[number].setNameCompany(newNameCompany);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 2:
            {
                size_t discount;
                std::cout << "\nEnter new discount: ";
                std::cin >> discount;
                discounts[number].setDiscount(discount);
                std::cout << "\nChanges saved successfully!\n";
                flagSave = true;
                break;
            }
            case 3:
            {
                manipHeaderDiscountNotIndex(std::cout);
                std::cout << discounts[number] << "\n";
                manipTailDiscountNotIndex(std::cout);
                break;
            }
            default:
                std::cout << "\nError! Operation selected incorrectly!\n";
                break;
        }
        
        if (flagExit)
        {
            sortDiscount();
            
            if(flagSave)
                saveDiscount(fileDiscount);
            
            break;
        }
    }
}

void TelevisionAgency:: eraseDiscount()
{
    printDiscount(std::cout);
    
    if (discounts.size() == 0)
        return;
    
    size_t number;
    
    while (true)
    {
        std::cout << "\nEnter number discount: ";
        std::cin >> number;
        --number;
        
        if(number < discounts.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    discounts.erase(discounts.begin()+number);
    saveDiscount(fileDiscount);
    std::cout << "\nDiscount deleted successfully!\n";
}

void TelevisionAgency:: addOrder()
{
    if(isEmptyTelecasts() || isEmptyAdvertisers())
        return;
    
    size_t duration;
    std::cout << "\nEnter duration of your ad (min): ";
    std::cin >> duration;
    
    std::vector<Telecast> tempTelecast;
    std::copy_if(telecasts.begin(), telecasts.end(), std::back_inserter(tempTelecast), [duration] (Telecast telecast)
    {
        return (telecast.getMaxMinuteAds() >= duration);
    });
    
    if(tempTelecast.size() == 0)
    {
        std::cout << "\nSorry, your ad is too long!\n";
        return;
    }
    
    size_t number = 0, numberTelecast;
    manipHeaderTelecast(std::cout);
    std::for_each(tempTelecast.begin(), tempTelecast.end(), [&number] (Telecast telecast) { std::cout << std::setw(8) << ++number << telecast << "\n"; });
    manipTailTelecast(std::cout);
    
    while (true)
    {
        std::cout << "\nEnter number telecast: ";
        std::cin >> numberTelecast;
        --numberTelecast;
        
        if(numberTelecast < tempTelecast.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    printAdvertiser(std::cout);
    size_t numberAdvertiser;
    
    while (true)
    {
        std::cout << "\nEnter number advertiser: ";
        std::cin >> numberAdvertiser;
        --numberAdvertiser;
        
        if(numberAdvertiser < advertisers.size())
            break;
        
        std::cout << "\nError! Number selected incorrectly!\n";
    }
    
    std::string date;
    std::cout << "\nEnter date: ";
    std::cin>> date;
    std::string tempCompany = advertisers[numberAdvertiser].getNameCompany();
    
    auto it = std::find_if(discounts.begin(), discounts.end(), [tempCompany] (Discount discount)
    {
        return toLower(tempCompany) == toLower(discount.getNameCompany());
    });
    
    double discount = it->getDiscount();
    orders.push_back(Order ((tempTelecast[numberTelecast]), (advertisers[numberAdvertiser]), discount, duration, date));
    sortOrder();
    saveOrder(fileOrder);
    std::cout << "\nOrder added successfully!\n";
}

void TelevisionAgency:: profit()
{
    double profit = 0;
    
    if(orders.size() != 0)
    {
        std::for_each(orders.begin(), orders.end(), [&profit] (Order order)
                      {
            profit += order.getPrice();
        });
    }
    
    std::cout << "\nProfit: " << std::fixed << std::setprecision(0) << profit << " BYN\n";
}

void TelevisionAgency:: printOrderByCompany(std::ostream&) const
{
    if(isEmptyOrders())
        return;
    
    std::string tempCompany;
    std::cout << "\nEnter name company: ";
    std::cin >> tempCompany;
    
    std::vector<Order> tempOrder;
    std::copy_if(orders.begin(), orders.end(), std::back_inserter(tempOrder), [tempCompany] (Order order)
    {
        return toLower(tempCompany) == toLower(order.getNameCompany());
    });
    
    if(tempOrder.size() == 0)
    {
        std::cout << "\nSorry, no orders found for this company!\n";
        return;
    }
    
    size_t number = 0;
    manipHeaderOrder(std::cout);
    std::for_each(tempOrder.begin(), tempOrder.end(), [&number] (Order order) { std::cout << std::setw(8) << ++number << order << "\n"; });
    manipTailOrder(std::cout);
}
