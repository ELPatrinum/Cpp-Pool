/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:07:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/12/06 15:06:23 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void):filename("test.csv"), dataname("data.csv")
{
	if (dataname.size() < 4)
		throw std::runtime_error("Error: Data File must be in csv format");
	std::string format = dataname.substr(dataname.size() - 4, dataname.size() - 1);
	if (format != ".csv")
		throw std::runtime_error("Error: Data File must be in csv format");
    std::ifstream inputFile(dataname);
	if (!inputFile.is_open())
    	throw std::runtime_error("Error: Could not open the file [" + dataname + "]");
    std::string line;
	std::string key;

    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        size_t delim = line.find(',');

        key = trimSpaces(line.substr(0, delim));
        float value = atof((trimSpaces(line.substr(delim + 1, line.length()))).c_str());
        data[key] = value;
    }
    inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->filename = other.filename;
        this->data = other.data;
    }
};
BitcoinExchange::~BitcoinExchange(void){};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->filename = other.filename;
        this->data = other.data;
    }
    return (*this);
};

std::string BitcoinExchange::trimSpaces(const std::string &str)
{
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start < str.length() && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end]))
        end--;
    return (str.substr(start, end - start + 1));
}

void BitcoinExchange::isValidKey(const std::string &date)
{
    if (date.length() != 10)
         throw std::runtime_error("Error: bad input : " + date);
    if (date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: bad input : " + date);
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = atof(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 1000 || year > 9999)
        throw std::runtime_error("Error: invalid year : " + date);

    if (month < 1 || month > 12)
        throw std::runtime_error("Error: invalid month : " + date);

    int maxDaysInMonth = 31;
    if (month == 2)
	{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            maxDaysInMonth = 29;
		else
            maxDaysInMonth = 28;
    }
	else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDaysInMonth = 30;
    if (day < 1 || day > maxDaysInMonth)
        throw std::runtime_error("Error: invalid day : " + date);
}
void BitcoinExchange::isValidValue(const std::string& value)
{
    if (value.empty())
	;
    float result = atof(value.c_str());

    if (result < 0)
		throw std::runtime_error("Error: negative value : " + value);
	if (result > 1000)
		throw std::runtime_error("Error: too large value : " + value);

}
std::string BitcoinExchange::ft_itoa(int num)
{
    std::string str = "";
    if (num == 0)
        return "0";
    while (num > 0)
	{
        str = char(num % 10 + '0') + str;
        num /= 10;
    }
    return (str);
}

std::string BitcoinExchange::findDate(const std::string &date)
{
    int year = atoi((date.substr(0, 4)).c_str());
    int month = atoi((date.substr(5, 2).c_str()));
    int day = atoi((date.substr(8, 2)).c_str());

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        daysInMonth[2] = 29;

    day--;

    if (day == 0)
	{
        month--;

        if (month == 0)
		{
            month = 12;
            year--;
        }

        day = daysInMonth[month];
    }
    std::string newYear = ft_itoa(year);
    std::string newMonth = (month < 10) ? "0" + ft_itoa(month) : ft_itoa(month);
    std::string newDay = (day < 10) ? "0" + ft_itoa(day) : ft_itoa(day);

    return (newYear + "-" + newMonth + "-" + newDay);
}



void BitcoinExchange::check_find(std::string file)
{
	filename = file;
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open the file [" + filename + "]");

    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            throw std::runtime_error("Error: empty line in the input file " + filename);
        if (line == "date | value")
            continue;
 
        char    *c_line = const_cast<char*>(line.c_str());
		char	*prekey = strtok(c_line, "|");
		char	*preval = strtok(NULL, "|");
		try
		{
			if(!prekey || !preval)
				throw std::runtime_error("Error: invalid line " + line);
			std::string key(trimSpaces(prekey));
			std::string valueStr(preval);
			isValidKey(trimSpaces(key));
			isValidValue(trimSpaces(valueStr));
			std::map<std::string, float>::iterator it;
			std::string preDate = key;
			it = data.find(key);

			while (it == data.end())
			{
				const std::string &nowDate = preDate;
				it = data.find(preDate);
				if(it == data.end())
					preDate = findDate(nowDate);
				it = data.find(preDate);
			}
		 	std::cout << key << " => " << valueStr  << " = " << it->second * atof(valueStr.c_str()) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
    inputFile.close();
}
