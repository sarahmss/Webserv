/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:34:08 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/25 19:01:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP


# include <string.h>
# include <unistd.h>
#include "./SimpleServer.hpp"

namespace HTTP
{
	class WebServer: public SimpleServer
	{
		public:

			WebServer();
			~WebServer();

			void launch(void);

		private:
			char	buffer[30000];
			int		new_socket;

			void accepter();
			void handler();
			void responder();

	};
}



#endif /* ******************************************************* WEBSERVER_H */