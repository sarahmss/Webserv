/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:37:23 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 23:13:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "./ParserUtils.hpp"
#include "./ServerInfo.hpp"
#include "./ServerParser.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>


# define ServerInfoVecType std::vector<FT::ServerInfo>

namespace	FT
{
	class	Parser
	{
		public:
			Parser(void);
			Parser(Parser const& src);
			~Parser(void);

			Parser	&operator=(Parser const& rhs);

			void					exec(std::string filename);
			const ServerInfoVecType	&getServers(void) const;

		private:
			ServerInfoVecType	_servers;
			std::ifstream		_fileStream;
			std::string			_line;

			void _parseFile(void);
			void _parseServerBlock(void);
	};

std::ostream &			operator<<( std::ostream & o, ServerInfo const & i );

}

#endif //PARSER_HPP
