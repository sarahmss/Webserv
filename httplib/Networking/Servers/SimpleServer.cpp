#include "SimpleServer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HTTP::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, unsigned long int interface, int bklg)
{
	socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HTTP::SimpleServer::~SimpleServer()
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

HTTP::ListeningSocket * HTTP::SimpleServer::get_socket()
{
	return (socket);
}
/* ************************************************************************** */