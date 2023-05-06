#include <string>

struct Task
{
    int t = 0;
    int p = 0;
    double u = 0;

    Task() = default;

    Task(int t_value, int p_value) : t(t_value), p(p_value), u(static_cast<double>(t_value) / p_value) {}

    Task(int t_value, int p_value, double u_value) : t(t_value), p(p_value), u(u_value) {}

    std::string toString()
    {
        return std::to_string(t) + " " + std::to_string(p) + " " + std::to_string(u);
    }
};