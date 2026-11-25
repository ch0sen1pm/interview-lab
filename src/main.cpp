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
    return 0;
}