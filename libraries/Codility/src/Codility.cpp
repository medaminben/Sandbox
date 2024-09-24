#include "Codility_impl.h"
#include <Sandbox/Codility/Codility.h>

namespace Sandbox { namespace Codility {

    
    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/1-iterations/

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
    int solution_BinaryGap(int N){ 
        return BinaryGap(N); 
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/0-Arrays.pdf

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
    std::vector<int> solution_CyclicRotation(std::vector<int> &A, int K){
        return CyclicRotation(A,K);
    }

    // https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
    int solution_OddOccurencyInArray(std::vector<int> &A) {
        return OddOccurencyInArray(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/1-TimeComplexity.pdf

    //////////////////////////////////////////////////////////////////////  
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
    int solution_JumpingFrog(int X, int Y, int D) {
        return JumpingFrog(X,Y,D);
    }

    // https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
    int solution_MissingElement(std::vector<int> &A) {
        return MissingElement(A);
    }

    // https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
    int solution_TapeEquilibrium(std::vector<int> &A) {
        return TapeEquilibrium(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/2-CountingElements.pdf

    //////////////////////////////////////////////////////////////////////  
        
    //https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
    int solution_FrogRiver(int X, std::vector<int> &A) {
        return FrogRiver(X,A);
    }

     //https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
    int solution_PermCheck(std::vector<int> &A) {
        return PermCheck(A);
    }

     //https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/   
    std::vector<int> solution_MaxCounters(int N, std::vector<int> &A) {
        return MaxCounters(N,A);
    }

    int solution_MissingInteger(std::vector<int> &A) {
        return MissingInteger(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/3-PrefixSums.pdf

    //////////////////////////////////////////////////////////////////////  

    //https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/ 
    int solution_PassingCars(std::vector<int> &A) {
        return PassingCars(A);
    }
   // https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

    int solution_CountDiv(int A, int B, int K) {
        return CountDiv(A,B,K);
    }

    std::vector<int> 
    solution_GenomicRangeQuery(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
        return GenomicRangeQuery(S,P,Q);
    }
    // https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
    int solution_MinAvgTwoSlice(std::vector<int> &A) {
        return MinAvgTwoSlice(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/4-Sorting.pdf

    //////////////////////////////////////////////////////////////////////  
        
    // https://app.codility.com/programmers/lessons/6-sorting/distinct/
    int solution_Distincts(std::vector<int> &A) {
        return Distincts(A);
    }

    // https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
    int solution_MaxProductOfThree(std::vector<int> &A) {
        return MaxProductOfThree(A);
    }

    // https://app.codility.com/programmers/lessons/6-sorting/triangle/
    int solution_Triangle(std::vector<int> &A) {
        return Triangle(A);
    }

    // https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
    int solution_NumberOfDiscIntersections(std::vector<int> &A) {
        return NumberOfDiscIntersections(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/5-Stacks.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
    int solution_Brackets(std::string &S) {
         return Brackets(S);
    }
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
    int solution_Fish(std::vector<int> &A, std::vector<int> &B) {
        return Fish(A,B);
    }

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
    int solution_Nesting(std::string &S) { 
        return Nesting(S);
    }

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
    int solution_StoneWall(std::vector<int> &H) {
        return StoneWall(H);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/6-Leader.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/8-leader/dominator/
    int solution_Dominator(std::vector<int> &A) {
        return Dominator(A);
    }

    // https://app.codility.com/programmers/lessons/8-leader/equi_leader/
    int solution_EquiLeader(std::vector<int> &A) {
        return EquiLeader(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/7-MaxSlice.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
    int solution_MaxProfit(std::vector<int> &A) {
        return MaxProfit(A);
    }
    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
    int solution_MaxSliceSum(std::vector<int> &A) {
        return MaxSliceSum(A);
    }
    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/    
    int solution_MaxDoubleSliceSum(std::vector<int> &A) {
        return MaxDoubleSliceSum(A);
    }
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/8-PrimeNumbers.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
    int solution_CountFactors(int A) {
        return CountFactors(A);
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
    int solution_MinPerimeterRectangle(int N) {
        return MinPerimeterRectangle(N);    
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
    int solution_Flags(std::vector<int> &A) {
        return Flags(A);
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
    int solution_Peaks(std::vector<int> &A) {
        return Peaks(A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/9-Sieve.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/
    std::vector<int> 
    solution_CountNonDivisible(std::vector<int> &A) {
        return CountNonDivisible(A);
    }

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
    std::vector<int> 
    solution_CountSemiprimes(int N, std::vector<int> &P, std::vector<int> &Q) {
        return CountSemiprimes(N,P,Q);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/   
    int 
    solution_CommonPrimeDivisors(std::vector<int> &A, std::vector<int> &B) {
        return CommonPrimeDivisors(A,B);
    }
    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
    int solution_ChocolatesByNumbers(int N, int M) {
        return ChocolatesByNumbers(N,M);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/
    int solution_FibFrog(std::vector<int> &A){
        return FibFrog(A);
    }

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/
    std::vector<int> 
    solution_Ladder(std::vector<int> &A, std::vector<int> &B) {
        return Ladder(A,B);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/
    int solution_MinMaxDivision(int K, int M, std::vector<int> &A) {
        return MinMaxDivision(K,M,A);
    }

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/
    int solution_NailingPlanks(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {
        return NailingPlanks(A,B,C);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/abs_distinct/
    int solution_AbsDistinct(std::vector<int> &A) {
        return AbsDistinct(A);
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
    int solution_CountDistinctSlices(int M, std::vector<int> &A) {
        return CountDistinctSlices(M,A);
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/
    int solution_CountTriangles(std::vector<int> A) {
        return CountTriangles(A);
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/
    int solution_MinAbsSumOfTwo(std::vector<int> &A) {
        return MinAbsSumOfTwo(A);
    }
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/14-GreedyAlgorithms.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/
    int solution_MaxNonoverlappingSegments(std::vector<int> &A, std::vector<int> &B) { 
        return MaxNonoverlappingSegments(A,B);
    }


    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
    int solution_TieRopes(int K, std::vector<int> &A) {
        return TieRopes(K,A);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/15-DynamicProgramming.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/
    int solution_NumberSolitaire(std::vector<int> &A) {
        return NumberSolitaire(A);
    }

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
    int solution_MinAbsSum(std::vector<int> &A){
        return MinAbsSum(A);
    }
}}
