#ifndef INCLUDE_ZX_DEFER
#define INCLUDE_ZX_DEFER

#pragma once

#include <utility>

namespace zx
{

template<typename F>
class defer final
{
private:
    F m_Function;
    bool m_ShouldExecute;

public:
    defer() = delete;
    defer(const defer&) = delete;
    defer(defer &&rhs) : m_Function(std::move(rhs.m_Function)), m_ShouldExecute(rhs.m_ShouldExecute)
    {
        rhs.m_ShouldExecute = false;
    }

    defer(F &&function) : m_Function(std::move(function)), m_ShouldExecute(true)
    {
    }

    defer &operator=(const defer&) = delete;
    defer &operator=(defer &&rhs) = delete;

    bool has_executed() const noexcept
    {
        return !m_ShouldExecute;
    }

    void cancel() noexcept
    {
        m_ShouldExecute = false;
    }

    bool execute()
    {
        if(m_ShouldExecute)
        {
            m_Function();
            m_ShouldExecute = false;

            return true;
        }

        return false;
    }

    ~defer()
    {
        execute();
    }
};

}

#endif // INCLUDE_ZX_DEFER