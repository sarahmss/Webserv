/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:56:29 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/11 20:56:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTEN_HPP
# define LISTEN_HPP

# include <iostream>
# include <string>


/*
	- Specify the IP address and port on which the server should listen for incoming connections.
	- It determines the network interface and port combination that the server should bind to.
*/

namespace FT
{
	class Listen
	{
		public:

			Listen();
			Listen( Listen const & src );
			~Listen();

			Listen &		operator=( Listen const & rhs );

			void		SetHost(std::string host);
			void		SetPort(int port);

			std::string	GetHost(void) const;
			int			GetPort(void) const;

			bool		IsSet(void) const;

		private:
			std::string	_host;
			int			_port;

	};
}

std::ostream &			operator<<( std::ostream & o, FT::Listen const & i );

#endif /* ********************************************************** LISTEN_H */
