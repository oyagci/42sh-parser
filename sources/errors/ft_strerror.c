/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:19:50 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 11:50:12 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strerror(int err)
{
	char *const str[] = {
		"Undefined Error", "Operation not permitted",
		"No such file or directory", "No such process",
		"Interrupted system call", "Input/output error",
		"Device not configured", "Argument list too long", "Exec format error",
		"Bad file descriptor", "No child processes",
		"Resource deadlock avoided", "Cannot allocate memory",
		"Permission denied", "Bad address", "Block device required",
		"Resource busy", "File exists", "Cross-device link",
		"Operation not supported by device", "Not a directory",
		"Is a directory", "Invalid argument", "Too many open files in system",
		"Too many open files", "Inappropriate ioctl for device",
		"Text file busy", "File too large", "No space left on device",
		"Illegal seek", "Read-only file system", "Too many links"
	};

	return (err >= 1 && err <= 31 ? str[err] : str[0]);
}
