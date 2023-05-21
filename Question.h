#pragma once
#include <string>
class Question
{
private:
    std::string text, answer;
    int id, score;
public:
    Question();
    Question(int id, std::string text, std::string answer, int score):id(id),text(text),answer(answer),score(score){}
    std::string getText() { return text; }
    std::string getAnswer() { return answer; }
    int getId() { return id; }
    int getScore() { return score; }
    void setText(std::string newText) { text = newText; }
    void setId(int newID) { id = newID; }
    void setScore(int newScore) { score = newScore; }
    void setAnswer(std::string newAnsw) { answer = newAnsw; }
    friend std::istream& operator>>(std::istream& stream, Question& ques);
    std::string toString() {
        return std::to_string(this->id) + ";" + this->text + ";" + this->answer + ";" + std::to_string(this->score);
    }
    std::string toStringParticipant() {
        return std::to_string(this->id) + ";" + this->text + ";" + std::to_string(this->score);
    }

    ~Question();
};