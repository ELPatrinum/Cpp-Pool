/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FR.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:08:25 by muel-bak          #+#    #+#             */
/*   Updated: 2024/09/11 20:43:06 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fr_HPP
#define Fr_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <stdbool.h>

class Fr
{
private:
    std::string infile;
    std::string outfile;

public:
    Fr( std::string filename);
    ~Fr();
    bool    find_and_replace(std::string find, std::string replace);
};
#endif