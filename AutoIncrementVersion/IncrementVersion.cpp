/*------------------------------------------------------------------------------
   Copyright (C) 2019 by Bach Nguyen Sy
   Unauthorized copying of this file via any medium is strictly prohibited
   bachns.dev@gmail.com | github.com/bachns.dev
--------------------------------------------------------------------------------
 File name:    AutoIncrementVersion/IncrementVersion.cpp
 Date created: Saturday, November 02, 2019
 Written by Bach Nguyen Sy
*/

#include "IncrementVersion.h"
#include <fstream>
#include <iostream>
#include <ctime>

IncrementVersion::IncrementVersion(std::string sourceCodeDir)
	: m_sourceCodeDir(std::move(sourceCodeDir))
{
	m_versionLines = std::vector<size_t>(4);
	m_major = 1;
	m_minor = 0;
	m_revision = 0;
	m_build =  1;
}

void IncrementVersion::incrementBuild()
{
	m_build++;
	std::string& line = m_lines[m_versionLines[BUILD]];
	line = line.substr(0, 22) + std::to_string(m_build);
}

void IncrementVersion::incrementRevision()
{
	m_revision++;
	std::string& line = m_lines[m_versionLines[REVISION]];
	line = line.substr(0, 22) + std::to_string(m_revision);
}

void IncrementVersion::incrementMinor()
{
	m_minor++;
	std::string& line = m_lines[m_versionLines[MINOR]];
	line = line.substr(0, 22) + std::to_string(m_revision);
}

void IncrementVersion::incrementMajor()
{
	m_major++;
	std::string& line = m_lines[m_versionLines[MAJOR]];
	line = line.substr(0, 22) + std::to_string(m_major++);
}

void IncrementVersion::readAllLines()
{
	m_lines.clear();
	std::ifstream file(m_sourceCodeDir + "\\resource.h");
	if (file.is_open())
	{
		std::string line;
		while (!file.eof())
		{
			std::getline(file, line);
			if (line.length() > 22)
			{
				std::string code = line.substr(8, 13);
				std::string numberStr = line.substr(22);
				if (code == "VERSION_MAJOR")
				{
					m_major = std::stoi(numberStr);
					m_versionLines[MAJOR] = m_lines.size();
				}
				else if (code == "VERSION_MINOR")
				{
					m_minor = std::stoi(numberStr);
					m_versionLines[MINOR] = m_lines.size();
				}
				else if (code == "VERSION_REVIS")
				{
					m_revision = std::stoi(numberStr);
					m_versionLines[REVISION] = m_lines.size();
				}
				else if (code == "VERSION_BUILD")
				{
					m_build = std::stoi(numberStr);
					m_versionLines[BUILD] = m_lines.size();
				}
				else if (code == "VS_BUILD_DATE")
				{
					std::time_t t = std::time(nullptr);
					std::tm* now = std::localtime(&t);
					int year = now->tm_year + 1900;
					int month = now->tm_mon + 1;
					int day = now->tm_mday;
					char date[13] = {};
					sprintf(date, "\"%02d/%02d/%4d\"", day, month, year);
					line = line.substr(0, 22) + date;
				}
			}
			m_lines.push_back(line);
		}
		file.close();
		std::cout << "Old version: " << m_major << "." << m_minor
			<< "." << m_revision << "." << m_build<< std::endl;
	}
	else
	{
		std::cerr << "Cannot open file resource.h" << std::endl;
	}
}

void IncrementVersion::writeAllLines()
{
	if (!m_lines.empty())
	{
		std::ofstream file(m_sourceCodeDir + "\\resource.h");
		if (file.is_open())
		{
			file << m_lines[0];
			for (size_t i = 1; i < m_lines.size(); i++)
				file << std::endl << m_lines.at(i);
			file.close();
			std::cout << "New version: " << m_major << "." << m_minor
			<< "." << m_revision << "." << m_build<< std::endl;
		}
		else
		{
			std::cerr << "Cannot open file resource.h" << std::endl;
		}
	}
	else
	{
		std::cerr << "Resource code is empty" << std::endl;
	}
}
