#pragma once

#include <chrono>
#include <string>

namespace interview {

enum class Stage {
    Kintro,
    kQuestioning,
    kSummary,
    kFinished,
};

struct Answer {
    std::string question_id;
    std::string text;
    std::chrono::seconds duration{0};
};

} // namespace interview