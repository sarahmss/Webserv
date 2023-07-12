/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerInf<< " " << i.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:15:28 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 21:36:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerInfo.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::ServerInfo::ServerInfo():	_listen(ListenType()),
								_serverName(StrVecType()),
								_root(""),
								_errorPages(ErrorType()),
								_errorPagesDefault(ErrorType()),
								_cgi(CgiType()),
								_bodySize(1000000),
								_location(LocationVecType())
{
	//_errorPages.setDefault();
	return ;
}

FT::ServerInfo::ServerInfo( const ServerInfo & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::ServerInfo::~ServerInfo() { return ; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FT::ServerInfo	&FT::ServerInfo::operator=( FT::ServerInfo const & rhs )
{
	if ( this != &rhs )
	{
		this->_listen = rhs.getListen();
		this->_serverName = rhs.getServerName();
		this->_root = rhs.getRoot();
		this->_errorPages = rhs.getErrorPages();
		this->_errorPagesDefault = getDefaultErrorPages();
		this->_cgi = rhs.getCgi();
		this->_bodySize = rhs.getBodySize();
		this->_location =  rhs.getLocation();
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, FT::ServerInfo const & i )
{
	o	<< "Listen: "				<< i.getListen()			<< std::endl
		<< "Server Name: "			<< i.ServerNameToString()	<< std::endl
		<< "Root: " 				<< i.getRoot()				<< std::endl
		<< "Error Pages: " 			<< i.getErrorPages()		<< std::endl
		<< "Error Pages Default: "	<< i.getDefaultErrorPages()	<< std::endl
		<< "Cgi: " 					<< i.getCgi()				<< std::endl
		<< "Body Size: "			<< i.getBodySize()			<< std::endl
		<< "Location: "				<<	std::endl;
		for (int j=0; j < i.getLocation().size(); j++)
			o << i.getLocation()[j] << std::endl;

	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	FT::ServerInfo::AddServerName(std::string serverName)
{
	_serverName.push_back(serverName);
}

void	FT::ServerInfo::AddLocation(LocationType locationBlock)
{
	_location.push_back(locationBlock);
}

void	FT::ServerInfo::AddErrorPage(std::string code, std::string pagePath)
{
	// errorPage.addPage(code, pagePath);
	std::cout << "class not implemented" << std::endl;
}

void	FT::ServerInfo::AddCgiConf(std::string extension,
		std::string programPath)
{
	//_cgi.addProgram(extension, programPath);
	std::cout << "class not implemented" << std::endl;
}

bool	FT::ServerInfo::IsListenSet(void) const
{
	//	return (_listen.isSet());
	std::cout << "class not implemented" << std::endl;
}

bool	FT::ServerInfo::IsServerNameSet(void) const
{
	return (!_serverName.empty());
}

bool	FT::ServerInfo::IsRootSet(void) const
{
	return (!_root.empty());
}
bool	FT::ServerInfo::IsErrorPageSet(std::string code) const
{
	//return (_errorPage.HasPage(code));
}

std::string		FT::ServerInfo::ServerNameToString(void) const
{
	std::string	FinalStr;

	for (int i = 0; i < _serverName.size(); i++)
		FinalStr += _serverName[i] + " ";
	return (FinalStr);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
ListenType	FT::ServerInfo::getListen(void) const
{
	return (_listen);
}
StrVecType	FT::ServerInfo::getServerName(void) const
{
	return (_serverName);
}
std::string	FT::ServerInfo::getRoot(void) const
{
	return (_root);
}
std::string	FT::ServerInfo::getErrorPage(std::string code) const
{
	return ("Not implemented class");
	// return (_errorPages.get_page(code));
}
ErrorType	FT::ServerInfo::getDefaultErrorPages(void) const
{
	return (_errorPagesDefault);
}
ErrorType	FT::ServerInfo::getErrorPages(void) const
{
	return (_errorPages);
}

CgiType		FT::ServerInfo::getCgi(void) const
{
	return (_cgi);
}
int			FT::ServerInfo::getBodySize(void) const
{
	return (_bodySize);
}
LocationVecType	FT::ServerInfo::getLocation(void) const
{
	return (_location);
}

void	FT::ServerInfo::SetListen(ListenType listen)
{
	_listen = listen;
}

void	FT::ServerInfo::SetRoot(std::string root)
{
	_root = root;
}

void	FT::ServerInfo::SetBodySize(int bodySize)
{
	_bodySize = bodySize;
}


/* ************************************************************************** */
