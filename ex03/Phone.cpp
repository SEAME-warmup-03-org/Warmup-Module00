# include "Phone.hpp"
# include "Utils.hpp"

Phone::Phone() {}

Phone::Phone(const Phone& other)
{
    this->nation_code = other.nation_code;
    this->number = other.number;
}

string  Phone::getNationCode(void) const
{
    return (this->nation_code);
}

int     Phone::setNationCode(const string _nation_code)
{
    if (isNumeric(_nation_code) == SUCCESS &&
        _nation_code.length() >= 1 &&
        _nation_code.length() <= 3) {
        this->nation_code = _nation_code;
        return (SUCCESS);
    } else {
        return (FAILURE);
    }
}

string  Phone::getNumber(void) const
{
    return (this->number);
}

int     Phone::setNumber(const string _number)
{
    if (isNumeric(_number) == SUCCESS &&
        _number.length() >= 5 &&
        _number.length() <= 15) {
        this->number = _number;
        return (SUCCESS);
    } else {
        return (FAILURE);
    }
}

string  Phone::getPhone(void) const
{
    string phone;

    phone = "" + this->nation_code + "+ " + this->number;

    return (phone);
}

bool    Phone::operator<(const Phone& other) const
{
    if (this->nation_code != other.nation_code)
        return nation_code < other.nation_code;
    else
        return number < other.number;
}

bool    Phone::operator==(const Phone& other) const
{
    return ((this->nation_code == other.nation_code) &&
            (number == other.number));
}
