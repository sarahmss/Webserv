#include "LocationParser.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

LocationParser::LocationParser()
{
}

LocationParser::LocationParser( const LocationParser & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

LocationParser::~LocationParser()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

LocationParser &				LocationParser::operator=( LocationParser const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, LocationParser const & i )
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