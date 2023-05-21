//
// Created by Alen on 06/06/2022.
//

#include "Repository.h"
#include <fstream>

#include <qdebug.h>
#include <iostream>

Repository::Repository()
{
    loadQuestions();
    loadParticipants();
}

void Repository::loadQuestions()
{
    std::ifstream f(R"(C:\Users\Alen\Documents\GitHub\e913-913-Iaguta-Alen-Mihael-1\questions.txt)");
    Question q;
    while (f >> q) {
        questions.push_back(q);
    }
    //std::cout << questions.size();
    f.close();
}

void Repository::loadParticipants()
{
    std::ifstream f(R"(C:\Users\Alen\Documents\GitHub\e913-913-Iaguta-Alen-Mihael-1\participants.txt)");
    Participant p{};
    while (f >> p) {
        participants.push_back(p);
    }

    //std::cout << participants.size();
    f.close();
}


bool Repository::search(int id)
{
    for (auto q : questions) {
        if (q.getId() == id)
            return true;
    }
    return false;
}

void Repository::update(Question q,std::string name)
{
    int score = q.getScore();
    for (auto p : participants) {
        if (p.getName() == name)
            p.setScore(score);
    }
}

void Repository::saveQuestions()
{
    std::ofstream g(R"(C:\Users\Alen\Documents\GitHub\e913-913-Iaguta-Alen-Mihael-1\questions.txt)");
    for (auto q : questions) {
        g << q.toString();
    }
    g.close();
}

Repository::~Repository()
{

}
