/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:01:44 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/10 16:08:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BindingSocket.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HTTP::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, unsigned long interface):
	SimpleSocket(domain, service, protocol, port, interface)
{
	set_connection(connect_to_network(get_sock(), get_address())); 
	test_connection(get_connection());
}

HTTP::BindingSocket::BindingSocket( BindingSocket & src ): HTTP::SimpleSocket(src)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HTTP::BindingSocket::~BindingSocket()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HTTP::BindingSocket &				HTTP::BindingSocket::operator=( BindingSocket & rhs )
{
	if ( this != &rhs )
        HTTP::SimpleSocket::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


int HTTP::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	return (bind(sock, (struct sockaddr *)&address, sizeof(address)));
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */