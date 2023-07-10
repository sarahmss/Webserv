#include "HttpRequest.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::HttpRequest::HttpRequest()
{

}

FT::HttpRequest::HttpRequest( const HttpRequest & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::HttpRequest::~HttpRequest()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

void		FT::HttpRequest::setMethod(FT::HttpMethod method)
{
	_method = method;
}
void		FT::HttpRequest::setUri(const FT::Uri &uri)
{
	_uri = uri;
}

FT::HttpMethod	FT::HttpRequest::getMethod(void) const
{
	return(_method);
}
FT::Uri			FT::HttpRequest::getUri(void) const
{
	return(_uri);
}

/*
** --------------------------------- METHODS ----------------------------------
*/



std::string	FT::HttpRequest::toString(const FT::HttpRequest &request)
{
	std::ostringstream	oss;

	oss << _toString(request.getMethod()) << ' ';
	oss << request.getUri().getPath() << ' ';
	oss << toascii((int)request.getVersion()) << '\r\n';
	for (const auto &p : request.getHeaders())
		oss << p.first << ": " << p.second << "\r\n";
	oss << "\r\n";
	oss << request.getContent();

	return oss.str();
}

FT::HttpRequest	FT::HttpRequest::stringToRequest(const std::string &requestStr)
{
	std::string	start_line, header_line, message_body;
	std::istringstream	iss;
	std::string	line, method, path, version;
	std::string	Key, Value;
	size_t		lpos = 0, rpos = 0;
	FT::Uri			uri;
	FT::HttpRequest request;


	rpos = requestStr.find("\r\n", lpos);
	if (rpos == std::string::npos)
		throw std::invalid_argument("Could not find request start line");

	start_line = requestStr.substr(lpos, (rpos - lpos));
	lpos = rpos + 2;
	rpos = requestStr.find("\r\n\r\n", lpos);
	if (rpos != std::string::npos) // Has Header
	{
		header_line = requestStr.substr(lpos, rpos - lpos);
		lpos = rpos + 4;
		rpos = requestStr.length();
		if (lpos < rpos)
			message_body = requestStr.substr(lpos, rpos - lpos);
	}

	// Parse start line
	iss.clear();
	iss.str(start_line);
	iss >> method >> path >> version;
	if (!iss.good() && !iss.eof())
		throw std::invalid_argument("Invalid start line fo₢rmat");
	request.setMethod(_stringToMethod(method));
	request.setUri(Uri(path));
	if (_stringToVersion(version) != request.getVersion())
		throw std::logic_error("HTTP version not supported");

	// parse header fields
	iss.clear();
	iss.str(header_line);
	while (std::getline(iss, line))
	{
		std::istringstream	header_stream(line);
		std::getline(header_stream, Key, ':');
		std::getline(header_stream, Value);
		// Remove whitespace
		Key.erase(std::remove_if(Key.begin(), Key.end(),
				[](char c) { return std::isspace(c); }), Key.end());
		Value.erase(std::remove_if(Value.begin(), Value.end(),
				[](char c) { return std::isspace(c); }), Value.end());
		request.SetHeader(Key, Value);
	}
	request.SetContent(message_body);
	
	return (request);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
