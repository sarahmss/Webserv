/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:34:00 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/09 20:34:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DEFINES_HPP
# define DEFINES_HPP

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
}

# endif // DEFINES_HPP
