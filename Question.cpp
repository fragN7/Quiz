//
// Created by Alen on 06/06/2022.
//

#include "Question.h"
#include "Utils.h"


Question::Question():id(0),text(""),score(0),answer("")
{
}


Question::~Question()
{
}

std::istream & operator>>(std::istream & stream, Question & ques)
{
    /*if(stream.eof())
        stream.setstate(std::ios_base::failbit);
    else
    {
        std::string id, score;

        std::getline(stream, id, ';');
        ques.id = std::stoi(id);

        std::getline(stream, ques.text, ';');

        std::getline(stream, ques.answer, ';');

        std::getline(stream, score, '\n');
        ques.score = std::stoi(score);
    }
    return stream;*/

    std::string str;
    getline(stream, str);
    std::vector<std::string>tokens;
    tokens = tokenize(str);
    if (tokens.size() != 4)
        return stream;
    ques.setId(std::stoi(tokens[0]));
    ques.setText(tokens[1]);
    ques.setAnswer(tokens[2]);
    ques.setScore(std::stoi(tokens[3]));
    return stream;
}