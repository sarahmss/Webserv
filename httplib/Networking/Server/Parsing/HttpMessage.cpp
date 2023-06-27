/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpMessage.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:31:33 by smodesto          #+#    #+#             */
/*   Updated: 2023/06/26 22:38:34 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpMessage.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FT::HttpMessage::HttpMessage() : _version(HttpVersion::HTTP_1_1) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FT::HttpMessage::~HttpMessage() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	FT::HttpMessage::_SetContentLength(void)
{
	SetHeader("Content-Length", std::to_string(_content.length()));
}

std::string		_toString(FT::HttpMethod method)
{
	switch (method) {
	case FT::HttpMethod::GET:
		return "GET";
	case FT::HttpMethod::HEAD:
		return "HEAD";
	case FT::HttpMethod::POST:
		return "POST";
	case FT::HttpMethod::PUT:
		return "PUT";
	case FT::HttpMethod::DELETE:
		return "DELETE";
	case FT::HttpMethod::CONNECT:
		return "CONNECT";
	case FT::HttpMethod::OPTIONS:
		return "OPTIONS";
	case FT::HttpMethod::TRACE:
		return "TRACE";
	case FT::HttpMethod::PATCH:
		return "PATCH";
	default:
		return std::string();
  }
}
std::string		_toString(FT::HttpVersion version)
{
	switch (version)
	{
		case FT::HttpVersion::HTTP_0_9:
			return "HTTP/0.9";
		case FT::HttpVersion::HTTP_1_0:
			return "HTTP/1.0";
		case FT::HttpVersion::HTTP_1_1:
			return "HTTP/1.1";
		case FT::HttpVersion::HTTP_2_0:
			return "HTTP/2.0";
		default:
			return std::string();
	}
}

std::string		_toString(FT::HttpStatusCode status_code)
{
	switch (status_code) {
	case FT::HttpStatusCode::Continue:
		return "Continue";
	case FT::HttpStatusCode::Ok:
		return "OK";
	case FT::HttpStatusCode::Accepted:
		return "Accepted";
	case FT::HttpStatusCode::MovedPermanently:
		return "Moved Permanently";
	case FT::HttpStatusCode::Found:
		return "Found";
	case FT::HttpStatusCode::BadRequest:
		return "Bad Request";
	case FT::HttpStatusCode::Forbidden:
		return "Forbidden";
	case FT::HttpStatusCode::NotFound:
		return "Not Found";
	case FT::HttpStatusCode::MethodNotAllowed:
		return "Method Not Allowed";
	case FT::HttpStatusCode::ImATeapot:
		return "I'm a Teapot";
	case FT::HttpStatusCode::InternalServerError:
		return "Internal Server Error";
	case FT::HttpStatusCode::NotImplemented:
		return "Not Implemented";
	case FT::HttpStatusCode::BadGateway:
		return "Bad Gateway";
	default:
		return std::string();
	}
}

FT::HttpMethod		_stringToMethod(const std::string& method)
{
	std::string method_string_uppercase;
	std::transform(method.begin(), method.end(),
					std::back_inserter(method_string_uppercase),
					[](char c) { return toupper(c); });
	if (method_string_uppercase == "GET") {
	return FT::HttpMethod::GET;
	} else if (method_string_uppercase == "HEAD") {
	return FT::HttpMethod::HEAD;
	} else if (method_string_uppercase == "POST") {
	return FT::HttpMethod::POST;
	} else if (method_string_uppercase == "PUT") {
	return FT::HttpMethod::PUT;
	} else if (method_string_uppercase == "DELETE") {
	return FT::HttpMethod::DELETE;
	} else if (method_string_uppercase == "CONNECT") {
	return FT::HttpMethod::CONNECT;
	} else if (method_string_uppercase == "OPTIONS") {
	return FT::HttpMethod::OPTIONS;
	} else if (method_string_uppercase == "TRACE") {
	return FT::HttpMethod::TRACE;
	} else if (method_string_uppercase == "PATCH") {
	return FT::HttpMethod::PATCH;
	} else {
	throw std::invalid_argument("Unexpected HTTP method");
	}
}

FT::HttpVersion		_stringToVersion(const std::string& version)
{
	std::string version_string_uppercase;

	std::transform(version.begin(), version.end(),
					std::back_inserter(version_string_uppercase),
					[](char c) { return toupper(c); });
	if (version_string_uppercase == "HTTP/0.9") {
	return FT::HttpVersion::HTTP_0_9;
	} else if (version_string_uppercase == "HTTP/1.0") {
	return FT::HttpVersion::HTTP_1_0;
	} else if (version_string_uppercase == "HTTP/1.1") {
	return FT::HttpVersion::HTTP_1_1;
	} else if (version_string_uppercase == "HTTP/2" ||
				version_string_uppercase == "HTTP/2.0") {
	return FT::HttpVersion::HTTP_2_0;
	} else {
	throw std::invalid_argument("Unexpected HTTP version");
	}
}

void	FT::HttpMessage::SetHeader(const std::string& key, const std::string& value)
{
	_headers[key] = std::move(value);
}

void	FT::HttpMessage::RemoveHeader(const std::string& key)
{
	_headers.erase(key);
}

void	FT::HttpMessage::ClearHeader(void)
{
	_headers.clear();
}

void	FT::HttpMessage::SetContent(const std::string& content)
{
	_content = std::move(content);
	_SetContentLength();
}

void	FT::HttpMessage::ClearContent(void)
{
	_content.clear();
	_SetContentLength();
}


size_t	FT::HttpMessage::ContentLength(void) const{ return _content.length(); }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

FT::HttpVersion	FT::HttpMessage::getVersion(void) const { return _version; }

std::string	FT::HttpMessage::getHeader(const std::string &key) const
{
	if (_headers.count(key) > 0 )
		return (_headers.at(key));
	return (std::string());
}

HeaderType	FT::HttpMessage::getHeaders(void) const { return _headers; }
std::string	FT::HttpMessage::getContent(void) const { return _content; }


/* ************************************************************************** */
