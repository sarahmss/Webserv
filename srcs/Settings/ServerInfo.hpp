/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:15:45 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 22:19:11 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERINFO_HPP
# define SERVERINFO_HPP

# include <iostream>
# include <string>
# include <vector>

# define StrVecType			std::vector<std::string>
# define ListenType			std::string
# define LocationType		std::string
# define LocationVecType	std::vector<std::string>
# define ErrorType			std::string
# define CgiType			std::string

namespace FT
{
	class ServerInfo
	{
		public:
			ServerInfo();
			ServerInfo( ServerInfo const & src );
			~ServerInfo();

			ServerInfo &	operator=( ServerInfo const & rhs );

			ListenType		getListen(void) const;
			StrVecType		getServerName(void) const;
			std::string		getRoot(void) const;
			std::string		getErrorPage(std::string code) const;
			ErrorType		getErrorPages(void) const;
			ErrorType		getDefaultErrorPages(void) const;
			CgiType			getCgi(void) const;
			int				getBodySize(void) const;
			LocationVecType	getLocation(void) const;

			void			SetListen(ListenType listen);
			void			SetRoot(std::string root);
			void			SetBodySize(int bodySize);

			void			AddServerName(std::string serverName);
			void			AddLocation(LocationType locationBlock);
			void			AddErrorPage(std::string code, std::string pagePath);
			void			AddCgiConf(std::string extension,
							std::string programPath);

			bool			IsListenSet(void) const;
			bool			IsServerNameSet(void) const;
			bool			IsRootSet(void) const;
			bool			IsErrorPageSet(std::string code) const;

			std::string		ServerNameToString(void) const;

		private:
			ListenType		_listen;
			StrVecType		_serverName;
			LocationVecType	_location;
			ErrorType		_errorPages;
			ErrorType		_errorPagesDefault;
			CgiType			_cgi;
			std::string		_root;
			int				_bodySize;

	};

	std::ostream &			operator<<( std::ostream & o, ServerInfo const & i );
}
#endif /* ****************************************************** SERVERINFO_H */
