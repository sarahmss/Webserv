#include "ConnectingSocket.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HTTP::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, unsigned long interface):
	SimpleSocket(domain, service, protocol, port, interface)
{
	set_connection(connect_to_network(get_sock(), get_address())); 
	test_connection(get_connection());
}

HTTP::ConnectingSocket::ConnectingSocket( ConnectingSocket & src ): HTTP::SimpleSocket(src)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HTTP::ConnectingSocket::~ConnectingSocket()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HTTP::ConnectingSocket &				HTTP::ConnectingSocket::operator=( ConnectingSocket & rhs )
{
	if ( this != &rhs )
        HTTP::SimpleSocket::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int HTTP::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
	return (connect(sock, (struct sockaddr *)&address, sizeof(address)));
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */