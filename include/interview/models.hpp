#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace interview {

enum class Stage {
    kIntro,
    kQuestioning,
    kSummary,
    kFinished,
};

struct Answer {
    std::string question_id;
    std::string text;
    std::chrono::seconds duration{0};
};

struct Question {
    std::string id;
    std::string text;
    std::string topic;
};

struct Evaluation {
    int score = 0;
    std::string feedback;
};

struct QAPair {
    Question question;
    Answer answer;
    Evaluation evaluation;
};

struct InterviewReport {
    std::string candidate;
    std::string role;
    std::vector<QAPair> items;
    int overall_score = 0;
    std::string summary;
};

} // namespace interview