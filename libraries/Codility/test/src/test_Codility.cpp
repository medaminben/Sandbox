#include <Sandbox/Codility/Codility.h>
// Include 3rd party headers
#include <gtest/gtest.h>
// Include system headers
#include <iostream>
#include <string>
#include <assert.h>
#include <unordered_set>

using namespace Sandbox::Codility;
// output control
#define BUILD_TEST_ALL 1 // useful for single test build in development
#define VERBOSE_TEST   0// echo the result.


// debugging helper : comment the line #undef VERBOSE_TEST to deploy
std::string to_string(std::vector<int> const& v, std::string const& separator = ""){
    std::string msg{};
    for(size_t i = 0 ; i < v.size() -1; i++) 
        msg += std::to_string(v[i]) + separator;
    msg += std::to_string(v[v.size()-1]);
    return msg;
}

std::string to_string(std::unordered_set<int> st, std::string separator = ","){
    std::vector<int> vc(st.size());
    copy(st.begin(), st.end(), vc.begin());
    return to_string(vc,separator);
}

// vector comparator
bool isEqual(std::vector<int> const& v1, 
             std::vector<int> const& v2) { return std::equal(v1.begin(), v1.end(), v2.begin());}

int solution_task_2(std::string S) {
        const int size  = S.size();

        int start_ptr{0},/*end_ptr{0},*/ counter{0};
        std::unordered_set<int> st{};

        while(size > start_ptr) {  
           //|| size > end_ptr) {

            if(size > start_ptr 
               && !st.contains(S[start_ptr])) {
                st.emplace(S[start_ptr]);
                start_ptr++;
                counter += st.size();

            } else st.clear(); //end_ptr++;
            
        }

       return counter;
    }

#if BUILD_TEST_ALL 
    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/1-iterations/

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
TEST (test_Codility_bin_gap, reulut) {
    int N = 1041;
    int result = solution_BinaryGap(N);
#if VERBOSE_TEST
    std::cout << "largest gap in "<< N << " is = " << result << "\n";
#endif
    EXPECT_EQ(5, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/0-Arrays.pdf

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
TEST (test_Codility_cyc_rot, reulut) {
    std::vector<int> A = {1,2,3,4};
    int K = 4;
    auto result = solution_CyclicRotation(A,K);
#if VERBOSE_TEST
    std::cout << "vec after rotation: ["<< to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(result, A));
}

    // https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
TEST (test_Codility_odd_occurency_in_array, result) {
    std::vector<int> A = {2,2,4,9,4};
    int res = solution_OddOccurencyInArray(A);
#if VERBOSE_TEST
    std::cout << "odd occurency in array is : ["<<  res << "]\n";
#endif
    EXPECT_EQ(res, 9); 
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/1-TimeComplexity.pdf

    //////////////////////////////////////////////////////////////////////  
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
TEST (test_Codility_jumping_frog , result) {
    auto result = solution_JumpingFrog(10,85,30);
#if VERBOSE_TEST
    std::cout << "jumping frog will jump "<< result<< " times \n";
#endif

    EXPECT_EQ(3,result);
}
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
TEST (test_Codility_missing_element , result) {
    std::vector<int> A = {1,2,5,0,3,4,7};
    auto result = solution_MissingElement(A);
#if VERBOSE_TEST
    std::cout << "missing_element is "<< result<< " \n";
#endif
    EXPECT_EQ(6,result);
}
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
TEST (test_Codility_tape_equilibrium , result) {
    
    std::vector<int> the_vec{ 3 , 1 , 2 , 4 , 3};
    auto result = solution_TapeEquilibrium(the_vec);
#if VERBOSE_TEST
    std::cout << "tape equilibrium of  in the vector [" << to_string(the_vec,",")
    <<"] is " << result << " \n";
#endif
    EXPECT_EQ(1, result);
}
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/2-CountingElements.pdf

    //////////////////////////////////////////////////////////////////////  
        
    //https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
TEST (test_Codility_frog_river , result) {
    int X{5};
    std::vector<int> A {1, 3, 1, 4, 2, 3, 5, 4} ;
    auto result = solution_FrogRiver(X,A);
#if VERBOSE_TEST
    std::cout << "the earliest coverage of all positions in the river is at index "
    << result << " in the vector [" << to_string(A,",") <<  "]\n";
#endif
    EXPECT_EQ(6, result);
}
    
    //https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
 TEST (test_Codility_PermCheck, result) {
    std::vector<int> A = {4,1,3,2};
    int res = solution_PermCheck(A);
#if VERBOSE_TEST
    std::cout << "if array A is a permutation? (1 else 0 if it is not).: ["<<  res << "]\n";
#endif
    EXPECT_EQ(res, 1); 

     A   = {4,1,3};
     res = solution_PermCheck(A);
#if VERBOSE_TEST
    std::cout << "if array A is a permutation? (1 else 0 if it is not).: ["<<  res << "]\n";
#endif
    EXPECT_EQ(res, 0); 
}

    //https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/
TEST(test_Codility_max_counters, result) {
    int N{5};
    std::vector<int> A{3 ,4 ,4 ,6 ,1 ,4,4};
    std::vector<int> expectation{3, 2, 2, 4, 2};
    auto result = solution_MaxCounters(N,A);
#if VERBOSE_TEST
    std::cout << "the counters value at " << N 
    << " in the vector are [" << to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(expectation, result));
}
    
    //https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
TEST(test_Codility_missing_integer, result) {
    std::vector<int> A{1, 3, 6, 4, 1, 2};
    auto result = solution_MissingInteger(A);
#if VERBOSE_TEST
    std::cout << "the missing integer is [" << result << "]\n";
#endif
    EXPECT_EQ(5, result);
}
    
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/3-PrefixSums.pdf

    //////////////////////////////////////////////////////////////////////

    //https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
TEST(test_Codility_PassingCars, result) {
    std::vector<int> A({0,1,0,1,1}); 
    int result = solution_PassingCars(A);
#if VERBOSE_TEST
    std::cout << " the number of pairs of passing cars is [ " << result << " ]\n";
#endif
    EXPECT_EQ(5, result);
}
  
    // https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

    
TEST(test_Codility_count_div, result) {
    //  A = 6, B = 11 and K = 2, your function should return 3, 
    int A = 6, B = 11 , K = 2;
    auto result = solution_CountDiv(A,B,K);
#if VERBOSE_TEST
    std::cout << "the countDiv is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}
    
    // https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
TEST(test_Codility_GenomicRangeQuery, result) {
    std::string S = "CAGCCTA";
    std::vector<int> P({2,5,0}) , Q({4,5,6}), expectation({2, 4, 1});
    std::vector<int> result = solution_GenomicRangeQuery(S,P,Q);
#if VERBOSE_TEST
    std::cout << " the consecutive answers to all queries  [" << to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(expectation, result));
}
    
    // https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
TEST(test_Codility_MinAvgTwoSlice, result) {
    std::vector<int> A({4,2,2,5,1,5,8});
    int result = solution_MinAvgTwoSlice(A);
#if VERBOSE_TEST
    std::cout << " the starting position of a slice whose average is minimal, is [" << result << "]\n";
#endif   
    EXPECT_EQ(1, result);
}
    
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/4-Sorting.pdf

    //////////////////////////////////////////////////////////////////////
        
    // https://app.codility.com/programmers/lessons/6-sorting/distinct/
TEST(test_Codility_Distincts, result) {
    std::vector<int> A({2,1,1,2,3,1}); 
    int result = solution_Distincts(A);
#if VERBOSE_TEST
    std::cout << " the count of distinct integers is [" << result << "]\n";
#endif

    EXPECT_EQ(3, result);
}
    
    // https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
TEST(test_Codility_MaxProductOfThree, result) {
    std::vector<int> A({-3,1,2,-2,5,6}); 
    int result = solution_MaxProductOfThree(A);
#if VERBOSE_TEST
    std::cout << " the value of the maximal product of any triplet is [ " << result << " ]\n";
#endif

    EXPECT_EQ(60, result);
}
    
    // https://app.codility.com/programmers/lessons/6-sorting/triangle/
TEST(test_Codility_Triange, result) {
    std::vector<int> A({10,50,5,1}), B({10,2,5,1,8,20});
    int result_1 = solution_Triangle(A);
    int result_2  = solution_Triangle(B);
#if VERBOSE_TEST
    std::cout 
    << " 1 if there exists a triangular triplet 0 otherwise:\n - {10,50,5,1} =  [ " 
    << result_1 << " ] \n - {10,2,5,1,8,20} =  [ " << result_2 << " ] \n" ;
#endif
    EXPECT_EQ(0, result_1);
    EXPECT_EQ(1, result_2);
}

    // https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
TEST(test_Codility_DiscIntersections, result) {
    std::vector<int> A({1,5,2,1,4,0});
    int result = solution_NumberOfDiscIntersections(A);
#if VERBOSE_TEST
    std::cout << " the number of pairs of intersecting discs. is [" << result << "]\n";
#endif
    EXPECT_EQ(result,11);
}
    
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/5-Stacks.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
TEST(test_Codility_Brackets, result) {
    std::string S1{"[()()]"},S2{"[(}()]"};

    int result = solution_Brackets(S1);
#if VERBOSE_TEST
    std::cout 
    << "  is properly nested?:\n - \"[()()]\" =  [ "<< result << " ] \n" ;
#endif
    EXPECT_EQ(1, result);

    result = solution_Brackets(S2);
#if VERBOSE_TEST
    std::cout 
    << "  is properly nested?:\n - \"[(}()]\" =  [ "<< result << " ] \n" ;
#endif
    EXPECT_EQ(0, result);
}
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
TEST(test_Codility_Fish, result) {
    std::vector<int> A({4,3,2,1,5}), B({0,1,0,0,0}); 
    int result = solution_Fish(A,B);
#if VERBOSE_TEST
    std::cout << " the number of fish that will stay alive, is [" << result << "]\n";
#endif
    EXPECT_EQ(2, result);
}
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
TEST(test_Codility_Nesting, result) {
    std::string S1{"(()(())())"},S2{"())"};

    int result = solution_Nesting(S1);
#if VERBOSE_TEST
    std::cout 
    << "  is properly nested?:\n - \"(()(())())\" =  [ "<< result << " ] \n" ;
#endif
    EXPECT_EQ(1, result);

    result = solution_Nesting(S2);
#if VERBOSE_TEST
    std::cout 
    << "  is properly nested?:\n - \"())\" =  [ "<< result << " ] \n" ;
#endif
    EXPECT_EQ(0, result);
}
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
TEST(test_Codility_StoneWall, result) {
    std::vector<int> H({8,8,5,7,9,8,7,4,8}); 
    int result = solution_StoneWall(H);
#if VERBOSE_TEST
    std::cout << " the minimum number of blocks needed to build is [ " << result << " ]\n";
#endif
    EXPECT_EQ(7, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/6-Leader.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/8-leader/dominator/
TEST(test_Codility_Dominator, result) {
    std::vector<int> A({3,4, 3,2,3,-1,3,3}); 
    int result = solution_Dominator(A);
#if VERBOSE_TEST
    std::cout << " the Dominator is at index : [ " << result << " ]\n";
#endif
    EXPECT_EQ(7, result);
}
    
    // https://app.codility.com/programmers/lessons/8-leader/equi_leader/
TEST(test_Codility_EquiLeader, result) {
    std::vector<int> A({4,3,4,4,4,2}); 
    int result = solution_EquiLeader(A);
#if VERBOSE_TEST
    std::cout << " the equi leader is at index : [ " << result << " ]\n";
#endif
    EXPECT_EQ(2, result);
}


    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/7-MaxSlice.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
TEST(test_Codility_MaxProfit, result) {
    std::vector<int> A({23171,21011,21123,21366,21013,21367}); 
    int result = solution_MaxProfit(A);
#if VERBOSE_TEST
    std::cout << " the MaxProfit is  : [ " << result << " ]\n";
#endif
    EXPECT_EQ(356, result);
}
    
    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
TEST(test_Codility_MaxSliceSum, result) {
    std::vector<int> A({3,2,-6,4,0});
    int result = solution_MaxSliceSum(A);
#if VERBOSE_TEST
    std::cout << " the maximal sum of any slices. is [" << result << "]\n";
#endif
    EXPECT_EQ(5, result);
}

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/
TEST(test_Codility_MaxDoubleSliceSum, result) {
    std::vector<int> A({3,2,6,-1,4,5,-1,2});
    int result = solution_MaxDoubleSliceSum(A);
#if VERBOSE_TEST
    std::cout << " the maximal sum of any double slice. is [" << result << "]\n";
#endif
    EXPECT_EQ(17, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/8-PrimeNumbers.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
TEST(test_Codility_CountFactors, result) {
    int N = 24;
    auto result = solution_CountFactors(N);
#if VERBOSE_TEST
    std::cout << " the count of factors is [" << result << "]\n";
#endif
    EXPECT_EQ(8, result);
}
    
    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
TEST(test_Codility_MinPerimeterRectangle, result) {
    int N = 30;
    auto result = solution_MinPerimeterRectangle(N);
#if VERBOSE_TEST
    std::cout << " minimal rectangle perometer is [" << result << "]\n";
#endif
    EXPECT_EQ(22, result);
}

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
TEST(test_Codility_Flags, result) {
    std::vector<int> A({1,5,3,4,3,4,1,2,3,4,6,2}); // 1,3,5 ,10
    int result = solution_Flags(A);
#if VERBOSE_TEST
    std::cout << " the maximum number of flags that can be set on the peaks of the array is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}
    
    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
TEST(test_Codility_Peaks, result) {
    std::vector<int> A({1,1,2,3,4,3,4,1,2,3,6,2}); // 3,5,10
    int result = solution_Peaks(A);
#if VERBOSE_TEST
    std::cout << " the maximum number of blocks into which the array A can be divided is [" << result << "]\n";
#endif
    EXPECT_EQ(2, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/9-Sieve.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/
TEST(test_Codility_CountNonDivisible, result) {

    std::vector<int> A({3,1,2,3,6}) , expectation({2, 4, 3, 2, 0});
    std::vector<int> result = solution_CountNonDivisible(A);
#if VERBOSE_TEST
    std::cout << " sequence of integers representing the amount of non-divisors is [" << to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(expectation, result));
}
    
    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
TEST(test_Codility_CountSemiprimes, result) {
    int N{26}; 
    std::vector<int> A({3,1,2,3,6}), P({1,4 ,16}), Q({26,10,20}), 
                     expectation({10, 4, 0});
    std::vector<int> result = solution_CountSemiprimes(N,P,Q);
#if VERBOSE_TEST
    std::cout << " the array consisting of M elements specifying the consecutive answers to all the querie is [" << to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(expectation, result));
}
    
    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    ////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/
TEST(test_Codility_CommonPrimeDivisors, result) {
    std::vector<int> A({15,10, 3}),
                     B({75,30,20}); 
    int result = solution_CommonPrimeDivisors(A,B);
#if VERBOSE_TEST
    std::cout << " the number of positions K for which the prime divisors of A[K] and B[K] are exactly the sam, is [" << result << "]\n";
#endif
    EXPECT_EQ(1, result);
}

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
TEST(test_Codility_ChocolatesByNumbers, result) {
    int N = 10, M = 4;
    auto result = solution_ChocolatesByNumbers(N,M);
#if VERBOSE_TEST
    std::cout << " the number of eaten chocolates is [" << result << "]\n";
#endif
    EXPECT_EQ(5, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    ////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/
TEST(test_Codility_FibFrog, result) {
    std::vector<int> A( {0,0,0,1,1,0,1,0,0,0,0}); 
    int result = solution_FibFrog(A);
#if VERBOSE_TEST
    std::cout << " the number of positions K for which the prime divisors of A[K] and B[K] are exactly the sam, is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}
    
    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/
TEST(test_Codility_Ladder, result) {
    std::vector<int> A({4,4,5,5,1}), B({3,2,4,3,1}), expectation({5, 1, 8, 0, 1});
    std::vector<int> result = solution_Ladder(A,B);
#if VERBOSE_TEST
    std::cout << " the number of different ways of climbing the ladder is [" << to_string(result,",") << "]\n";
#endif
    EXPECT_TRUE(isEqual(expectation, result));
}

    ///////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    ///////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/
TEST(test_Codility_MinMaxDivision, result) {
    std::vector<int> A({2,1,5,1,2,2,2}); 
    int K = 3, M = 35;
    int result = solution_MinMaxDivision(K,M,A);
#if VERBOSE_TEST
    std::cout << " the minimal large sum is [" << result << "]\n";
#endif
    EXPECT_EQ(6, result);
}
    
    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/
TEST(test_Codility_NailingPlanks, result) {
    std::vector<int> A({1,4,5,8}),B({4,5,9,10}),C({4,6,7,10,2}); 
    int result = solution_NailingPlanks(A,B,C);
#if VERBOSE_TEST
    std::cout << " the minimal large sum is [" << result << "]\n";
#endif
    EXPECT_EQ(4, result);
}

    ///////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    ///////////////////////////////////////////////////////////////////
    
    // https://app.codility.com/programmers/lessons/15-caterpillar_method/abs_distinct/
TEST(test_Codility_AbsDistinct, result) {
    std::vector<int> A({-5,-3,-1, 0, 3, 6}); 
    auto result = solution_AbsDistinct(A);
#if VERBOSE_TEST
    std::cout << " the number of distinct absolutes is [" << result << "]\n";
#endif
    EXPECT_EQ(5, result);
}
    
    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
TEST(test_Codility_CountDistinctSlices, result) {
    std::vector<int> A({3,4,5,5,2}); 
    int N =6;
    auto result = solution_CountDistinctSlices(N,A);
#if VERBOSE_TEST
    std::cout << " the number of distinct slices is [" << result << "]\n";
#endif
    EXPECT_EQ(9, result);
}
    
    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/
TEST(test_Codility_CountTriangles, result) {
    std::vector<int> A({10,2,5,1,8,12}); 
    auto result = solution_CountTriangles(A);
#if VERBOSE_TEST
    std::cout << " the number of traingles is [" << result << "]\n";
#endif
    EXPECT_EQ(4, result);
}
    
    // https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/
TEST(test_Codility_MinAbsSumOfTwo, result) {
    std::vector<int> A({-8,4,5,-10,3}); 
    int result = solution_MinAbsSumOfTwo(A);
#if VERBOSE_TEST
    std::cout << " the minimal absolute sum  of Tow is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/14-GreedyAlgorithms.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/
TEST(test_Codility_MaxNonoverlappingSegments, result) {
    std::vector<int> A({1,3,7,9,9}), B({5,6,8,9,10}); 
    int result = solution_MaxNonoverlappingSegments(A,B);
#if VERBOSE_TEST
    std::cout << " the size of a non-overlapping set containing a maximal number of segments., is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}
    
    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
TEST(test_Codility_TieRopes, result) {
    std::vector<int> A({1,2,3,4,1,1,3}); 
    int K =4;
    auto result = solution_TieRopes(K,A);
#if VERBOSE_TEST
    std::cout << " the number of distinct slices is [" << result << "]\n";
#endif
    EXPECT_EQ(3, result);
}

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/15-DynamicProgramming.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/
TEST(test_Codility_NumberSolitaire, result) {
    std::vector<int> A({1,-2,0,9,-1,-2}); 
    int result = solution_NumberSolitaire(A);
#if VERBOSE_TEST
    std::cout << " the maximal result that can be achieved on the board is [" << result << "]\n";
#endif

    EXPECT_EQ(8, result);
}

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
TEST(test_Codility_minAbsSum, result) {
    std::vector<int> A{1,5,2,-2};
    auto result = solution_MinAbsSum(A);
#if VERBOSE_TEST
    std::cout << "the lowest absolute sum of elements is [" << result << "]\n";
#endif
    EXPECT_EQ(0, result);
}

#endif// BUILD_TEST_ALL