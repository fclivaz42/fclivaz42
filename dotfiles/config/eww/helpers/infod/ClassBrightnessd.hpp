/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrightnessd.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:27:28 by fclivaz           #+#    #+#             */
/*   Updated: 2026/02/13 20:46:49 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIGHTNESSD_HPP
# define BRIGHTNESSD_HPP

#include "ClassPopup.hpp"

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

#define REGEX_STR "[0-9]{0,3}%"
#define BRIGHTNESS_POPUP_NAME "brightpopup"

class Brightnessd : Popupd
{
	private:
		const std::regex		_bctl;

	public:
		Brightnessd();
		~Brightnessd();

		int	set_brightness(const std::string& amount, const std::string& device);
};

#endif // !BRIGHTNESSD_HPP
