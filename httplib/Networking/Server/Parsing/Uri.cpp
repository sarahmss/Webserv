/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uri.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:12:18 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/26 21:58:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Uri.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::Uri::Uri()
{

}

FT::Uri::Uri( const std::string & path ): _path( path )
{
	_SetPathToLowercase();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::Uri::~Uri()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

bool	FT::Uri::operator<(const Uri& rhs) const
{
	return (_path < rhs.getPath());
}

bool	FT::Uri::operator==(const Uri& rhs) const
{
	return (_path == rhs.getPath());
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FT::Uri::_SetPathToLowercase(void)
{
	std::transform(_path.begin(), _path.end(),
					_path.begin(), [](char c) { return tolower(c); });
}

void FT::Uri::SetPath(const std::string &path)
{
	_path = std::move(path);
	_SetPathToLowercase();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		FT::Uri::getScheme() const { return _scheme; }

std::string		FT::Uri::getHost() const { return _host; }

std::uint16_t	FT::Uri::getPort() const { return _port; }

std::string		FT::Uri::getPath() const { return _path; }


/* ************************************************************************** */
