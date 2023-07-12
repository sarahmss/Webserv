#ifndef SERVERPARSER_HPP
# define SERVERPARSER_HPP

# include <iostream>
# include <string>

namespace FT
{
	class ServerParser
	{

		public:

			ServerParser();
			ServerParser( ServerParser const & src );
			~ServerParser();

			ServerParser &		operator=( ServerParser const & rhs );

		private:

	};

	std::ostream &			operator<<( std::ostream & o, ServerParser const & i );
}
#endif /* **************************************************** SERVERPARSER_H */
