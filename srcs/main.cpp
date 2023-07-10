/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:27:22 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 17:59:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Networking/Sockets/httpSockets.hpp"
#include "./Networking/Server/httpServ.hpp"


/*static void testSockets(void)
{
	std::cout << "<<< Starting... >>>" << std::endl;
	std::cout << "Binding Socket..." << std::endl;
	FT::BindingSocket bs(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);
	std::cout << "Listening socket..." << std::endl;
	FT::ListeningSocket ls(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
}*/

static void testServer(void)
{
	FT::WebServ WebServ;
}

int main(void)
{
	testServer();
}
