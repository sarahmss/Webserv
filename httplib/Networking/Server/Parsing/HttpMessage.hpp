/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpMessage.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:47:13 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/26 22:38:48 by smodesto         ###   ########.fr       */
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

namespace FT
{
	# define HeaderType	std::map<std::string, std::string>

	/********************************************************************
	*	HTTP methods defined in the following document:					*
	*	https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods		*
	*********************************************************************/
	enum class HttpMethod
	{
		GET,
		HEAD,
		POST,
		PUT,
		DELETE,
		CONNECT,
		OPTIONS,
		TRACE,
		PATCH,
	};

	enum class HttpVersion
	{
		HTTP_0_9 = 9,
		HTTP_1_0 = 10,
		HTTP_1_1 = 11,
		HTTP_2_0 = 20
	};

	enum class HttpStatusCode {
		Continue = 100,
		SwitchingProtocols = 101,
		EarlyHints = 103,
		Ok = 200,
		Created = 201,
		Accepted = 202,
		NonAuthoritativeInformation = 203,
		NoContent = 204,
		ResetContent = 205,
		PartialContent = 206,
		MultipleChoices = 300,
		MovedPermanently = 301,
		Found = 302,
		NotModified = 304,
		BadRequest = 400,
		Unauthorized = 401,
		Forbidden = 403,
		NotFound = 404,
		MethodNotAllowed = 405,
		RequestTimeout = 408,
		ImATeapot = 418,
		InternalServerError = 500,
		NotImplemented = 501,
		BadGateway = 502,
		ServiceUnvailable = 503,
		GatewayTimeout = 504,
		HttpVersionNotSupported = 505
	};

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
