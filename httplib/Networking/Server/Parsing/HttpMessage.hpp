/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpMessage.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:47:13 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/09 20:35:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPMESSAGE_HPP
# define HTTPMESSAGE_HPP

#include <algorithm>
#include <cctype>
#include <iterator>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include "./Defines.hpp"

namespace FT
{
	class HttpMessage
	{

		public:

			HttpMessage();
			virtual	~HttpMessage();

			void	SetHeader(const std::string& key, const std::string& value);
			void	RemoveHeader(const std::string& key);
			void	ClearHeader(void);

			void	SetContent(const std::string& content);
			void	ClearContent(void);
			size_t	ContentLength(void) const;

			HttpVersion	getVersion(void) const;
			std::string	getHeader(const std::string &key) const;
			HeaderType	getHeaders(void) const;
			std::string	getContent(void) const;

		protected:

			HttpVersion							_version;
			HeaderType							_headers;
			std::string							_content;

			void			_SetContentLength(void);
			std::string		_toString(HttpMethod method);
			std::string		_toString(HttpVersion version);
			std::string		_toString(HttpStatusCode status_code);
			HttpMethod		_stringToMethod(const std::string& method);
			HttpVersion		_stringToVersion(const std::string& version);
	};
}

#endif /* ***************************************************** FTMESSAGE_H */
