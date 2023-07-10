#ifndef HTTPREQUEST_HPP
# define HTTPREQUEST_HPP

# include <iostream>
# include <string>
# include "HttpMessage.hpp"
# include "Uri.hpp"

/*
	Represents a single HTTP request
	it has a HTTP method and URI so that server can identify
	the corresponding resource and action
*/

namespace	FT
{
	class HttpRequest : public HttpMessage
	{

		public:
			HttpRequest();
			~HttpRequest();

			void		setMethod(HttpMethod method);
			void		setUri(const Uri &uri);

			HttpMethod	getMethod(void) const;
			Uri			getUri(void) const;

			std::string	toString(const HttpRequest &request);
			HttpRequest	stringToRequest(const std::string &requestStr);

		private:
			HttpMethod	_method;
			Uri			_uri;

	};
}


#endif /* ***************************************************** HTTPREQUEST_H */
