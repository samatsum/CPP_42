/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:32:54 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/24 13:00:45 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

static int open_files(std::string name_inputfile, std::string name_outputfile,
	std::ifstream *input_file, std::ofstream *output_file);
static void read_and_replace(char **argv, std::ifstream *input_file, std::ofstream *output_file);

int main(int argc, char **argv)
{
	std::string name_inputfile;
	std::string name_outputfile;
	std::ifstream input_file;
	std::ofstream output_file;

	if (argc != 4)
		return (std::cerr << "Wrong number of arguments" << std::endl, 0);
	name_inputfile = argv[1];
	name_outputfile = std::string(argv[1]) + ".replace";
	if (open_files(name_inputfile, name_outputfile, &input_file, &output_file))
		return (1);
	read_and_replace(argv, &input_file, &output_file);
	input_file.close();
	output_file.close();
	return (0);
}

static int open_files(std::string name_inputfile, std::string name_outputfile,
					std::ifstream *input_file, std::ofstream *output_file)
{
	(*input_file).open(name_inputfile, std::fstream::in);
	(*output_file).open(name_outputfile, std::fstream::out);
	if (!(*input_file) || !(*output_file))
	{
        std::cerr << "Failed to open file" << std::endl;
		(*input_file).close();
		(*output_file).close();
        return (1);
    }
	return (0);
}

static void read_and_replace(char **argv, std::ifstream *input_file, std::ofstream *output_file)
{
	std::string 			to_find;
	std::string 			to_replace;
	std::string 			line;
	std::string::size_type	found;
	size_t					end_last_found;
	std::string				replaced_line;

	to_find = argv[2];
	to_replace = argv[3];
	end_last_found = 0;

	while(std::getline(*input_file, line))
	{
		
		replaced_line.clear();
		end_last_found = 0;
		found = line.find(to_find);
		if (found != std::string::npos)
		{
			while (found != std::string::npos)
			{
				replaced_line.append(line,end_last_found,found - end_last_found);
				replaced_line += to_replace;
				end_last_found = found + to_find.length();
				found = line.find(to_find, end_last_found);
				if (found == std::string::npos)
					replaced_line.append(line, end_last_found,line.length());
			}
		}
		else
			replaced_line = line;
		if (!(*input_file).eof())
			*output_file << replaced_line << std::endl;
		else
			*output_file << replaced_line;
	}
}
