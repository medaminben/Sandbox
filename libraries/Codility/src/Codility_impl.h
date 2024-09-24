#ifndef CODILITY_IMPL_H
#define CODILITY_IMPL_H
#include <vector>
#include <string>
namespace Sandbox { namespace Codility {
    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/1-iterations/

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
    int BinaryGap(int N);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/0-Arrays.pdf

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
    std::vector<int> CyclicRotation(std::vector<int> &A, int K);

    // https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
    int OddOccurencyInArray(std::vector<int> &A) ;

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/1-TimeComplexity.pdf

    //////////////////////////////////////////////////////////////////////  
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
    int JumpingFrog(int X, int Y, int D);

    // https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
    int MissingElement(std::vector<int> &A) ;

    // https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
    int TapeEquilibrium(std::vector<int> &A) ;

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/2-CountingElements.pdf

    //////////////////////////////////////////////////////////////////////  
        
    //https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
    int FrogRiver(int X, std::vector<int> &A) ;

     //https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
    int PermCheck(std::vector<int> &A) ;

     //https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/   
    std::vector<int> MaxCounters(int N, std::vector<int> &A) ;

    //https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
    int MissingInteger(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/3-PrefixSums.pdf

    //////////////////////////////////////////////////////////////////////  

    //https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/ 
    int PassingCars(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
    int CountDiv(int A, int B, int K) ;

    // https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
    std::vector<int> GenomicRangeQuery(std::string &S, std::vector<int> &P, std::vector<int> &Q);

    // https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
    int MinAvgTwoSlice(std::vector<int> &A) ;

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/4-Sorting.pdf

    //////////////////////////////////////////////////////////////////////  
        
    // https://app.codility.com/programmers/lessons/6-sorting/distinct/
    int Distincts(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
    int MaxProductOfThree(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/6-sorting/triangle/
    int Triangle(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
    int NumberOfDiscIntersections(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/5-Stacks.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
    int Brackets(std::string &S);
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
    int Fish(std::vector<int> &A, std::vector<int> &B);

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
    int Nesting(std::string &S);

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
    int StoneWall(std::vector<int> &H);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/6-Leader.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/8-leader/dominator/
    int Dominator(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/8-leader/equi_leader/
    int EquiLeader(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/7-MaxSlice.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
    int MaxProfit(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
    int MaxSliceSum(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/    
    int MaxDoubleSliceSum(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/8-PrimeNumbers.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
    int CountFactors(int A);

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
    int MinPerimeterRectangle(int N);

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
    int Flags(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
    int Peaks(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/9-Sieve.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/
    std::vector<int> CountNonDivisible(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
    std::vector<int> 
    CountSemiprimes(int N, std::vector<int> &P, std::vector<int> &Q);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/   
    int 
    CommonPrimeDivisors(std::vector<int> &A, std::vector<int> &B);

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
    int ChocolatesByNumbers(int N, int M);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/
    int FibFrog(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/
    std::vector<int> 
    Ladder(std::vector<int> &A, std::vector<int> &B);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/
    int MinMaxDivision(int K, int M, std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/
    int NailingPlanks(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/abs_distinct/
    int AbsDistinct(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
    int CountDistinctSlices(int M, std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/
    int CountTriangles(std::vector<int> A);

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/
    int MinAbsSumOfTwo(std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/14-GreedyAlgorithms.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/
    int MaxNonoverlappingSegments(std::vector<int> &A, std::vector<int> &B);

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
    int TieRopes(int K, std::vector<int> &A);

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/15-DynamicProgramming.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/
    int NumberSolitaire(std::vector<int> &A);

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
    int MinAbsSum(std::vector<int> &A);

}}

#endif // CODILITY_IMPL_H