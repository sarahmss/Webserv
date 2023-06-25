/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:27:22 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/25 18:51:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Networking/Sockets/httpSockets.hpp"
#include "../Networking/Servers/httpServers.hpp"


/*static void testSockets(void)
{
    std::cout << "<<< Starting... >>>" << std::endl;
    std::cout << "Binding Socket..." << std::endl;
    HTTP::BindingSocket bs(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);
    std::cout << "Listening socket..." << std::endl;
    HTTP::ListeningSocket ls(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);     
}*/

static void testServer(void)
{
    HTTP::WebServer WebServer;
}

int main(void)
{   
  testServer();
}