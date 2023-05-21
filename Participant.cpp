//
// Created by Alen on 06/06/2022.
//

#include "Participant.h"

Participant::Participant()
{
}


Participant::~Participant()
{
}

std::istream & operator>>(std::istream & stream, Participant & part)
{

    std::string str;
    getline(stream, str);
    std::vector< std::string> tokens = tokenize(str);
    if (tokens.size() != 2)
        return stream;
    part.setName(tokens[0]);
    part.setScore(std::stoi(tokens[1]));
    return stream;
}
