/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPopup.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:25:36 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/13 20:47:24 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPopup.hpp"

Popupd::Popupd(const std::string& name) : _bctl(PARSE_REGEX), _name(name)
{
}

Popupd::~Popupd()
{}

bool Popupd::parse_amount(const std::string& amount) const
{
	std::smatch	smack;

	return !std::regex_match(amount, smack, _bctl);
}

int Popupd::close_popup()
{

	return 0;
}

int Popupd::force_close()
{
	if (_open)
		return system(std::format("eww close {}", this->_name).c_str());
	return 0;
}
