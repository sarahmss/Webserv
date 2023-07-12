/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:55:03 by smodesto          #+#    #+#             */
/*   Updated: 2023/07/10 23:01:23 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSERUTILS_HPP
# define PARSERUTILS_HPP

# include <string>
# include <string.h>

namespace FT
{
	bool	IsValidLine(std::string &line);
	bool	IsComment(std::string &line);
	bool	IsEmpty(std::string &line);

	void trim(std::string &line, const std::string Trim);
}


#endif /* ***************************************************** PARSERUTILS_H */
