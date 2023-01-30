#pragma once
#define CC_FUNC_HEAD_EXPR inline constexpr
#define CC_FUNC_HEAD_EVAL inline consteval
#define CC_ARR_HEAD_CONST static const constexpr

template <auto value>
inline consteval const auto RET_OPT() {
    return value;
}

