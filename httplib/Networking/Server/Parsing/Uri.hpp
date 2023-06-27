/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Uri.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:50:03 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/26 21:58:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef URI_HPP
# define URI_HPP

# include <algorithm>
# include <string>
# include <cctype>
#include <utility>


/*
	A Uri obbject will contain a valid scheme, host, posrt, and the actual Uri path
*/
namespace FT
{
	class Uri
	{
		public:
			Uri();
			explicit Uri(const std::string& path);
			~Uri();

			bool operator<(const Uri& rhs) const;
			bool operator==(const Uri& rhs) const;

			void SetPath(const std::string& path);

			std::string		getScheme(void) const;
			std::string		getHost(void) const;
			std::uint16_t	getPort(void) const;
			std::string		getPath(void) const;

		private:
			std::string		_path;
			std::string		_scheme;
			std::string		_host;
			std::uint16_t	_port;

			void	_SetPathToLowercase(void);
	};
}


#endif /* ************************************************************* Uri_H */
