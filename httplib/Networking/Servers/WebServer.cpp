#include "WebServer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HTTP::WebServer::WebServer(): SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
	launch();
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HTTP::WebServer::~WebServer()
{
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	HTTP::WebServer::launch()
{
	while (true)
	{
		std::cout << "===== WAITING =====" << std::endl;
		accepter();
		handler();
		responder();
		std::cout << "===== DONE =====" << std::endl;
	}
}

void	HTTP::WebServer::accepter(void)
{
	ListeningSocket *	socket = get_socket();
	struct sockaddr_in	address = socket->get_address();
	int					address_len = sizeof(address);

	bzero(&buffer, 30000);
	new_socket = accept(socket->get_sock(),
						(struct sockaddr *)&address,
						(socklen_t *)&address_len);
	read(new_socket, buffer, 30000);
}

void	HTTP::WebServer::handler(void)
{
	std::cout << buffer << std::endl;
}

void	HTTP::WebServer::responder(void)
{
	std::string response =  "hello from server\n";
	write(new_socket, response.c_str(), response.size());	
	close(new_socket);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */