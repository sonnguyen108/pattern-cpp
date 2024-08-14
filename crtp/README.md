### Motivation
- Performance is very important in C++. So important in fact, that in several
contexts the performance overhead of using virtual functions is considered
outright unacceptable
- Therefore, in performance-sensitive contexts, such as
certain parts of computer games or high-frequency trading, no virtual
functions are used
- The same is true for high-performance computing (HPC). In HPC, any kind of conditional or indirection, and this includes
virtual functions, is banned from the most performance-critical parts, such
as the innermost loops of compute kernels. Using them would incur too
much of a performance overhead

### Explain
- The CRTP design pattern builds on the common idea of creating an
abstraction using a base class. But instead of establishing a runtime
relationship between base and derived classes via virtual functions, it
creates a compile-time relationship.
