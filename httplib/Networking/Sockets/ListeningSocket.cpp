#include "ListeningSocket.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HTTP::ListeningSocket::ListeningSocket(int domain, int service, int protocol,  int port, unsigned long interface, int bklog):
BindingSocket(domain, service, protocol, port, interface)
{
	backlog = bklog;
	start_listening();
	test_connection(listening);

}

HTTP::ListeningSocket::ListeningSocket( ListeningSocket & src ): HTTP::BindingSocket(src)
{
	this->listening = src.listening;
	this->backlog = src.backlog;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HTTP::ListeningSocket::~ListeningSocket()
{
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HTTP::ListeningSocket &				HTTP::ListeningSocket::operator=( ListeningSocket  & rhs )
{
	if ( this != &rhs )
	{
        HTTP::BindingSocket::operator=(rhs);
		this->listening = rhs.get_listening();
		this->backlog = rhs.get_backlog();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HTTP::ListeningSocket::start_listening()
{
	listening = listen(get_sock(), backlog);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int HTTP::ListeningSocket::get_listening()
{
	return (listening);
}

int HTTP::ListeningSocket::get_backlog()
{
	return (backlog);
}
/* ************************************************************************** */