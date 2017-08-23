# learning_modern_c-
c++11 and c++14 related exercises

Modern C++ learning (C++11 and C++14)
c++11:
-------
http://www.stroustrup.com/C++11FAQ.html#language
 - __cplusplus
     => InitializerList
 - alignments
     => Alignment
 - attributes
     => Attributes
 - atomic operations
     => Atomic
 - auto (type deduction from initializer)
    => InitializerList
 - C99 features
 - enum class (scoped and strongly typed enums)
    => EnumClass
 - [[carries_dependency]]
    => similar as Attributes exercise
 - copying and rethrowing exceptions
    => CopyAndRethrowException
 - constant expressions (generalized and guaranteed;constexpr)
 - decltype
 - control of defaults: default and delete
 - control of defaults: move and copy
 - delegating constructors
 - Dynamic Initialization and Destruction with Concurrency
 - exception propagation (preventing it; noexcept)
 - explicit conversion operators
 - extended integer types
 - extern templates
 - for statement; see range-for statement
 - suffix return type syntax (extended function declaration syntax)
 - in-class member initializers
 - inherited constructors
 - initializer lists (uniform and general initialization)
 - Inline namespace
 - lambdas
 - local classes as template arguments
 - long long integers (at least 64 bits)
    => LongLongInteger
 - memory model
 - move semantics; see rvalue references
 - narrowing (how to prevent it)
 - [[noreturn]]
 - null pointer (nullptr)
 - override controls: override
 - override controls: final
 - PODs (generalized)
 - range-for statement
     => InitializerList
 - raw string literals
 - right-angle brackets
 - rvalue references
 - Simple SFINAE rule
 - static (compile-time) assertions (static_assert)
 - template alias
 - template typedef; see template alias
 - thread-local storage (thread_local)
 - unicode characters
 - Uniform initialization syntax and semantics
 - unions (generalized)
 - user-defined literals
 - variadic templates
   => VariadicTemplate
c++11 Standard Library:
-----------------------
http://www.stroustrup.com/C++11FAQ.html#library
 - abandoning a process
 - Improvements to algorithms
 - array
 - async()
 - atomic operations
 - Condition variables
 - Improvements to containers
 - function and bind
 - forward_list a singly-liked list
 - future and promise
 - garbage collection ABI
 - hash_tables; see unordered_map
 - metaprogramming and type traits
 - Mutual exclusion
 - random number generators
 - regex a regular expression library
 - scoped allocators
 - shared_ptr
 - smart pointers; see shared_ptr, weak_ptr, and unique_ptr
 - threads
 - Time utilities
 - tuple
 - unique_ptr
 - unordered_map
 - weak_ptr
 - system error

c++14:
--------
- Generic lambdas - you can now write lambda parameters with an auto type and the compiler will figure things out.
- Lambdas parameters move - you can std::move things into the lambda (before this only copy or reference were possible)
- Constexpr - it can now have if, switch or for statements and local variables in a constexpr
- Return type deduction - auto myFunction() { }
- digit separators - you can now write 1'000'000 instead of 1000000
- binary literals - 0b prefix
- sized deallocation - you can now have a global overload to delete for all sized allocations
- std::gets removed - apparently using fgets is the recommended safe way
- dynamic memory management - reworked spec + optimizations
- deprecated keyword - [[deprecated]] for marking things, calling deprecated functions/using deprecated members gives a compiler warning
- make_unique
- metaprogramming support - improved transformation traits, compile time integer sequences
- stl improvements - null iterators
- variable templates - template<typename T> constexpr T x = T(5)
- shared_mutex is now called shared_timed_mutex
- aggregated member init
- heterogeneous lookup in associative containers - things like using const char* as a key to lookup in a map from std::string to something. this works if you have an operator< overload, also std::less and std::greater support this
- standard user-defined literals - you can write chrono::duration d = 60s; (now alos h, min, s, ms, us, ns)
- tuple addressing via type - being able to fetch a tuple by type (not just by index)
- global std::cend/std::cbegin - const counterparts to std::end/std::begin, globally
- std::quoted - for insertion and extraction of quoted strings

