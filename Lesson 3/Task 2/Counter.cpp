#include "Counter.h"

Counter::Counter(long long start) { m_counter = start; }

void Counter::inc() { ++m_counter; }

void Counter::dec() { --m_counter; }

long long Counter::current() { return m_counter; }