/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:07:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/10/20 17:52:07 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool    isValidKey(char *key)
{
    if (!key)
        return (false);
    bool valid = true;
    char *date[3];
    int i = 1;
    // std::cout << key << std::endl;
    date[0] = strtok(key, "-");
    while((date[i++] = strtok(NULL, "-")));
    std::cout  << "["<< date[0] << date[1] << date[2] << "]" << std::endl;
    return (valid);
}

BitcoinExchange::BitcoinExchange(std::string file):filename(file), dataname("data.csv")
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: Could not open the file " + filename);

    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
            throw std::runtime_error("Error: empty line in the input file " + filename);
        if (line == "date | value")
            continue;
        // std::cout << line << std::endl;

        
        char    *c_line = const_cast<char*>(line.c_str());
  
        char    *key = strtok(c_line, "|");
        char    *valueStr = strtok(NULL, "|");
        std::cout << key << "====" << valueStr << std::endl; 

        if (isValidKey(key) && valueStr)
        {
            float value = static_cast<float>(atof(valueStr));
            data.insert(std::pair<std::string, float>(key, value));
        }
        else
        {
            throw std::runtime_error("Error: invalid line " + line);
        }
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
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->filename = other.filename;
        this->data = other.data;
    }
    return (*this);
};