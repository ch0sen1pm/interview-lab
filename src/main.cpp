#include <cstdio>
#include <chrono>

#include "interview/models.hpp"

int main() {
    interview::Answer a;

    a.question_id = "q1";
    a.text = "hello";
    a.duration = std::chrono::seconds{42};

    std::printf("%s: %s (%lld s)\n", a.question_id.c_str(), a.text.c_str(),
                  static_cast<long long>(a.duration.count()));

    interview::Question q;
    q.id = "q1";
    q.text = "std::move 做了什么";
    q.topic = "C++";

    interview::Evaluation e;
    e.score = 80;
    e.feedback = "方向对，细节不够";

    std::printf("[%s] %s -> %d\n", q.topic.c_str(), q.text.c_str(), e.score);

    interview::QAPair pair{q, a, e};
    
    interview::InterviewReport report;
    report.candidate = "Xjuner";
    report.role = "C++ 后端";
    report.items.push_back(pair);
    report.overall_score = 80;
    report.summary = "整体不错";

    std::printf("%s / %s：%d 题，总分 %d\n", report.candidate.c_str(),
                report.role.c_str(), static_cast<int>(report.items.size()),
                report.overall_score);

    return 0;
}