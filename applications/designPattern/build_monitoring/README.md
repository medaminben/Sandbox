Illustration of the difference between compiler time and run time function initialization

# ct_vs_rt : compile-time versus run-time 
It's to take in knowledge the different interpretation of computing in compile-time and run-time. More than that. There is difference between compilers interpretation like shown below:

# const_versus_constexpr : const versus constexpr 
To take away:
- const entities can be initialized either at compile-time or run-time.They can be shared among different translation units such as (.cpp) files; using the extern keyword.
- constexpr entities should be always initialized at compile-time, and can not be shared among different translation units.
