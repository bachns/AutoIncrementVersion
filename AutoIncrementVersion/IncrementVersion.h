/*------------------------------------------------------------------------------
   Copyright (C) 2019 by Bach Nguyen Sy
   Unauthorized copying of this file via any medium is strictly prohibited
   bachns.dev@gmail.com | github.com/bachns.dev
--------------------------------------------------------------------------------
 File name:    AutoIncrementVersion/IncrementVersion.h
 Date created: Saturday, November 02, 2019
 Written by Bach Nguyen Sy
*/

#ifndef INCREMENTVERSION_H
#define INCREMENTVERSION_H

#include <string>
#include <vector>

class IncrementVersion
{
public:
	explicit IncrementVersion(std::string sourceCodeDir);
	~IncrementVersion() = default;
	void incrementBuild();
	void incrementRevision();
	void incrementMinor();
	void incrementMajor();
	
	void readAllLines();
	void writeAllLines();

private:
	std::string m_sourceCodeDir;
	std::vector<std::string> m_lines;
	std::vector<int> m_versionLines;
	int m_major, m_minor, m_revision, m_build;
	
	enum
	{
		MAJOR = 0, MINOR, REVISION, BUILD
	};
};


#endif // INCREMENTVERSION_H
