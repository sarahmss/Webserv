#include "SimpleServer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, unsigned long int interface, int bklg)
{
	socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::SimpleServer::~SimpleServer()
{
	delete socket;
	return ;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

FT::ListeningSocket * FT::SimpleServer::get_socket()
{
	return (socket);
}
/* ************************************************************************** */
