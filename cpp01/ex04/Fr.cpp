/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fr.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:29:02 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/11 20:44:10 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fr.hpp"


bool Fr::find_and_replace(std::string find, std::string replace)
{
    std::string content;
    size_t position;
    std::ifstream inputfile(infile.c_str());
    if (!inputfile.is_open())
    {
        std::cerr << "Error opening input file" << std::endl;
        inputfile.close();
        return (false);
    }
    std::ofstream outputfile(outfile.c_str());
    if(!outputfile.is_open())
    {
        std::cerr << "Error opening output file" << std::endl;
        inputfile.close();
        return (false);
    }
    if (!std::getline(inputfile, content, '\0'))
    {
        std::cerr << "Fr : Empty File!." << std::endl;
        inputfile.close();
        outputfile.close();
        return (false);
    }
    position = content.find(find);
    while (position != std::string::npos)
    {
        content.erase(position, find.length());
        content.insert(position, replace);
        position = content.find(find, position + replace.length());
    }
    outputfile << content;
    inputfile.close();
    outputfile.close();
    return (true);
}


