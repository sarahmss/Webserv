#ifndef SIMPLESERVER_HPP
# define SIMPLESERVER_HPP

# include <iostream>
# include <string>

#include "../httpNetworking.hpp"

namespace FT
{
	class SimpleServer
	{

		public:

			SimpleServer(int domain, int service, int protocol, int port, unsigned long int interface, int bklg);
			SimpleServer( SimpleServer & src );
			virtual ~SimpleServer();

			virtual void launch(void) = 0;
			ListeningSocket *get_socket();

		private:
			ListeningSocket	*socket;
			virtual void accepter(void) = 0;
			virtual void handler(void) = 0;
			virtual void responder(void) = 0;
	};
}

#endif /* **************************************************** SIMPLESERVER_H */
