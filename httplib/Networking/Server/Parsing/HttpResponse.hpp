#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP

# include <iostream>
# include <string>
# include "HttpMessage.hpp"
# include "Uri.hpp"

namespace FT
{
	class HttpResponse: public HttpMessage
	{

		public:

			HttpResponse();
			HttpResponse(HttpStatusCode statusCode);
			~HttpResponse();

			void SetStatusCode(HttpStatusCode sttsCd);
			HttpStatusCode GetStatusCode(void) const;

			std::string		toString (const HttpResponse &response,
									bool sendContent);

			HttpResponse	stringToResponse(const std::string &response);
		private:
			HttpStatusCode	_statusCode;
	};
}
#endif /* **************************************************** HTTPRESPONSE_H */
