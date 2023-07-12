#ifndef LOCATIONPARSER_HPP
# define LOCATIONPARSER_HPP

# include <iostream>
# include <string>

class LocationParser
{

	public:

		LocationParser();
		LocationParser( LocationParser const & src );
		~LocationParser();

		LocationParser &		operator=( LocationParser const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, LocationParser const & i );

#endif /* ************************************************** LOCATIONPARSER_H */