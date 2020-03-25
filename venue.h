#ifndef VENUE_H
#define VENUE_H

#include <string>

struct address {
    std::string street;
    std::string number;
    std::string zipCode;
    std::string city;
};

class Venue
{
public:
    Venue();

    void setName(const std::string &name);
    std::string Name() const;

    void setAddress(const address &address);
    address Address() const;

    bool operator==(const Venue &other) const;
    bool operator!=(const Venue &other) const;

private:
    std::string name;
    address _address;
};

#endif // VENUE_H
