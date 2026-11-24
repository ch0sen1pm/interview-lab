# interview-lab

基于 **C++17** 的 AI 模拟面试系统。根据简历生成技术问题，对回答评分、追问，最后导出 JSON 报告。
CLI 与 HTTP 服务复用同一套核心流程，支持离线运行和接入大模型两种模式。

> 🚧 开发中，当前仅有工程骨架，路线图见文末。

## 设计目标

核心业务**不依赖任何第三方库**，通过端口（纯虚接口）与适配器隔离。这样核心流程可以在没有网络、
没有 API 密钥的情况下用离线实现跑通，也便于替换模型服务商。

| 端口 | 职责 | 实现 |
|---|---|---|
| `ResumeParser` | 简历文本提取 | 纯文本 / PDF（规划中） |
| `QuestionGenerator` | 生成面试题 | 固定题库 / LLM |
| `AnswerEvaluator` | 回答评分 | 规则打分 / LLM |
| `SummaryGenerator` | 生成总结 | 规则 / LLM |
| `ReportWriter` | 导出报告 | JSON 文件 |
| `ASRClient` / `TTSClient` | 语音识别与合成 | （规划中） |

职责划分：

- `InterviewSession` —— 保存面试状态（阶段、题目、回答记录）
- `InterviewOrchestrator` —— 推进流程（自我介绍 → 出题 → 评分 → 追问 → 总结）
- `Runtime` —— 装配真实实现或离线实现，全项目只有这一处知道"今天用哪个"

## 构建

依赖 vcpkg，清单见 `vcpkg.json`（目前只有 `curl`、`nlohmann-json`、`gtest`）。

```powershell
$env:VCPKG_ROOT = "D:/vcpkg"

cmake -S . -B build -G "Visual Studio 18 2026" -A x64 `
  -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"

cmake --build build --config Debug
```

首次配置会自动安装依赖（manifest 模式），之后改 `vcpkg.json` 需要重新配置一次。

## 运行

```powershell
.\build\Debug\interview_lab.exe
```

## 目录结构

```text
interview-lab/
├── CMakeLists.txt       # 顶层构建：C++17、编译选项、测试开关
├── vcpkg.json           # 依赖清单
├── src/
│   └── main.cpp
└── .gitignore
```

## 路线图

- [x] 工程骨架：vcpkg + CMake
- [ ] 构建预设（CMakePresets.json）
- [ ] 核心模型与端口定义
- [ ] `InterviewSession` 状态机
- [ ] `InterviewOrchestrator` 流程编排
- [ ] 离线实现（固定题库 + 规则评分）
- [ ] JSON 报告导出
- [ ] CLI 入口
- [ ] 接入大模型
- [ ] HTTP 服务
- [ ] 语音链路
- [ ] Qt 界面
