/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPopup.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:25:34 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/09 21:15:31 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POPUP_HPP
# define POPUP_HPP

#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>

#define PARSE_REGEX "^[0-9]{1,3}[+-]?$"

class Popupd
{
	private:
		const std::regex		_bctl;
		const std::string		_name;
		bool					_open;

	protected:
		int	_level;

	public:
		Popupd(const std::string& name);
		virtual ~Popupd() = 0;
		bool	parse_amount(const std::string& amount) const;
		int		open_popup();
		int 	close_popup(); // TODO: std::thread this, conditional variable, check proceed on exit
};

#endif // !POPUP_HPP
