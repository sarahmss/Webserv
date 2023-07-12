#include "ServerParser.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ServerParser::ServerParser()
{
}

ServerParser::ServerParser( const ServerParser & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ServerParser::~ServerParser()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ServerParser &				ServerParser::operator=( ServerParser const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ServerParser const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */