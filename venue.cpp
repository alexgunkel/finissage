#include "venue.h"

Venue::Venue()
{

}

void Venue::setName(const std::string &name)
{
    this->name = name;
    this->name = name;
}

std::string Venue::Name() const
{
    return this->name;
}

void Venue::setAddress(const address &address)
{
    this->_address = address;
}

address Venue::Address() const
{
    return this->_address;
}

bool Venue::operator==(const Venue &other) const
{
    return this->name == other.name;
}

bool Venue::operator!=(const Venue &other) const
{
    return ! (*this == other);
}
