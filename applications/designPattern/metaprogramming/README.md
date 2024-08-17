Illustration of the difference between compiler time and run time function initialization

## ct_vs_rt : compile-time versus run-time 
It's to take in knowledge the different interpretation of computing in compile-time and run-time. More than that. There is difference between compilers interpretation like shown below:

with msvc compiler we get the folloing output 

![output_msvc_19](https://github.com/user-attachments/assets/968c3f4c-e6b4-4571-be78-a4ba2a43ff87) 

But in the other hand using gcc the result differs 

![output_gcc_14](https://github.com/user-attachments/assets/2a3cf763-a0bd-496f-991b-81edf0e90822)


## const_versus_constexpr : const versus constexpr 
It just print adressing of different use of constants
To take away:
- const entities can be initialized either at compile-time or run-time.They can be shared among different translation units such as (.cpp) files; using the extern keyword.
- constexpr entities should be always initialized at compile-time, and can not be shared among different translation units.

![output_const_vs_constexpr](https://github.com/user-attachments/assets/016863bb-dd1e-44c3-8c8b-e1a72a572e85)

## non_typed_class_template : sum function
3 types of implementations of the sum function:
- iteratif using for loop
- recursif using selfcall sum(x) = x + sum(x-1) 
- non typed class template that constructs the value by accumulation using recursive constructor call

## deep_non_typed_class_template : prime number function
Different implementations of the prime number function

## constexpr_tuple : std::tuple
Practice manipulation of tuple objects

## mpl_traits :  
Template functions using policies and traits

## construct_validation : default constructor validation
How to check default constructor is available
