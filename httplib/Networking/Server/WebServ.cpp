#include "WebServ.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::WebServ::WebServ(): SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
	launch();
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::WebServ::~WebServ()
{
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	FT::WebServ::launch()
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

void	FT::WebServ::accepter(void)
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

void	FT::WebServ::handler(void)
{
	std::cout << buffer << std::endl;
}

void	FT::WebServ::responder(void)
{
	std::string response = "FT/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
	write(new_socket, response.c_str(), response.size());
	close(new_socket);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
