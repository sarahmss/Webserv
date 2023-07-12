/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:54:57 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 23:05:39 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserUtils.hpp"

void	FT::trim(std::string &line, const std::string Trim)
{
	line.erase(0, line.find_first_not_of(Trim));
	line.erase(line.find_last_not_of(Trim) + 1);
}

bool	FT::IsComment(std::string &line)
{
	FT::trim(line, " \t");
	FT::trim(line, " ");

	if (line[0] == '#')
		return true;
	return false;
}

bool	FT::IsEmpty(std::string &line)
{
	FT::trim(line, " \t");
	FT::trim(line, " ");
	return (line == "");
}

bool	FT::IsValidLine(std::string &line)
{
	if (FT::IsEmpty(line))
		return false;
	if (FT::IsComment(line))
		return false;
	return (true);
}

/* ************************************************************************** */
