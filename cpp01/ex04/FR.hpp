/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FR.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:08:25 by muel-bak          #+#    #+#             */
/*   Updated: 2024/06/17 19:09:57 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_HPP
#define FR_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <stdbool.h>

class FR
{
private:
    std::string infile;
    std::string outfile;

public:
    FR( std::string filename);
    ~FR();
    bool    find_and_replace(std::string find, std::string replace);
};
#endif