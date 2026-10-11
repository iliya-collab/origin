#ifndef COUNTER_H
#define COUNTER_H

class Counter 
{
private:
    long long m_counter{};

public:
    Counter() = default;
    Counter(long long start);

    void inc();
    void dec();
    long long current();

};

#endif