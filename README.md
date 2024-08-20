# Sandbox
a practice repo based on [project-unit](https://github.com/medaminben/project-unit) repository


## Libraries
The implementation is classified by topic in different libraries:
#### Core
The core library defines the common code base. 
The base unit of the system is a value. The system at any moment of the life cycle is not doing other than managing values from call to result. The result of the processing should be a value but can be errors in exception and corner cases. Following this strategy increases the safety of the development, and converges to the deterministic characteristic of the end product.
- Error 
- Result<Value,Error>  of any type 

Annexed features:
- Index generator: A global core scope counter. can be called by Sc::get_unique_index. To use carefully, that the uniqueness is just in the actual run session by restart jumps to 0 (to do: make it unique forever) 

#### Pot
A container class. Collects all frequently used types of own data structures, to avoid code contamination.
The library is a headers-only library 
- Definition of Numeric concept which constraints templates to arithmetic types such integer or float, and their derivatives.
- Definition of a Point:
    - a point is a bundle of n coordinates 
    - special case 2D point  

#### Tools
A classic boring tools library
it collects some useful features:
- CSV Parser: a tiny csv parser facility highly needed for the deserialization, (no need of serialization right now)
- INI Parser: An ini parser facility, useful to manage data locally by collecting constant information from ini file such as storage, logging locations, user specific things... 

#### Geo
in one way or another like the standard algorithm library, only collects some geometric manipulation features 
- implementation of the factorial template meta-programming 
- implementation of the binomial coefficient using the multiplicative formula
- implementation of gcd function template 
- implementation of reducePoint function template which reduces a point to its gcd value
- implementation of distance function template which return  the distance between 2 2D points using the Pythagorean formula. 
