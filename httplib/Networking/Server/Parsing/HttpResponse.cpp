#include "HttpResponse.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::HttpResponse::HttpResponse(): _statusCode(HttpStatusCode::Ok)
{
	return ;
}

FT::HttpResponse::HttpResponse(HttpStatusCode sttsCd): _statusCode(sttsCd)
{
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::HttpResponse::~HttpResponse()
{
	return ;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

FT::HttpResponse	FT::HttpResponse::stringToResponse (const std::string& response)
{
	throw	std::logic_error("method not implemented");
}

std::string	FT::HttpResponse::toString(const FT::HttpResponse &response, bool sendContent)
{
	std::ostringstream	oss;

	oss << _toString(response.getVersion()) << ' ';
	oss << static_cast<int>(response.GetStatusCode()) << ' ';
	oss << _toString(response.GetStatusCode()) << '\r\n';
	for (const auto& p : response.getHeaders())
		oss << p.first << ": " << p.second << "\r\n";
	oss << "\r\n";
	if (sendContent)
		oss << response.getContent();
	return (oss.str());
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	FT::HttpResponse::SetStatusCode(HttpStatusCode sttsCd)
{
	_statusCode = sttsCd;
}
FT::HttpStatusCode		FT::HttpResponse::GetStatusCode(void) const
{
	return (_statusCode);
}

/* ************************************************************************** */
