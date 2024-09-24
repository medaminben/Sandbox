#include "Codility_impl.h"
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <array>
#include <cmath>
#include <functional>
#include <list>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_map>
namespace Sandbox { namespace Codility {


    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/1-iterations/

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
    int BinaryGap(int N) {
        //initialization 
        int   largest_gap{0}, gap_counter{0};
        bool  gap_started{false};
        std::vector<bool> bits{};
        // generate the bit sequence
        while(N){ 
            bits.emplace_back(N % 2); 
            N /= 2; 
        }
        //scan the vector for gaps
        for(auto itr  =  bits.crbegin(); 
                itr !=  bits.crend(); itr++) {
            auto bit  = *itr;
            if(bit) { // we have a 1
                if(gap_started) { // check if it's a gap end
                    largest_gap = std::max(gap_counter,largest_gap);
                    // reset for the next gap 
                    gap_counter = 0;   
                    gap_started = false;
                } 
            } else {
                gap_counter++;
                if(!gap_started) 
                    gap_started = true;
            }
        }       
        // done
        return largest_gap;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/0-Arrays.pdf

    ////////////////////////////////////////////////////////////////////// 

    // https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
    std::vector<int> CyclicRotation(std::vector<int> &A, int K){
        if(A.empty()) return A;
        for(auto i= 0; i < K; i++) {
            int temp = *(A.end()-1); // remember the last element
            for(size_t j = A.size()-2; j > 1; j--) {
                A[j+1] = A[j]; 
            }
            A[0] = temp;
        }
        return A;
    }

    // https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
    int OddOccurencyInArray(std::vector<int> &A){
        std::unordered_set<int> result{};
        for(auto item : A) 
            if (result.contains(item)) 
                result.erase(item);
            else 
                result.insert(item); 
        for(auto item : A) 
            if (result.contains(item)) return item;
        return -1;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/1-TimeComplexity.pdf

    //////////////////////////////////////////////////////////////////////  
    
    // https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
    int JumpingFrog(int X, int Y, int D) {
        auto distance  = Y - X;
        auto steps     = distance / D;
        auto remaining = distance % D;
        if(remaining != 0) steps++;
        return steps;
    }

    // https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
    int MissingElement(std::vector<int> &A) {
        std::unordered_set<int> set {};  
        size_t i= 0;

        while(i <= A.size()) set.insert(i++);

        for(auto const& i : A) set.erase(i);

        return *set.begin();
    }

    // https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
    int TapeEquilibrium(std::vector<int> &A) {
        std::vector<int> diffs{};
        for(size_t i = 1 ; i < A.size(); i++) {
            auto left_side  = std::accumulate(A.begin()      , A.begin() + i-1,0);
            auto right_side = std::accumulate(A.begin() + i-1, A.end()        ,0);
            diffs.emplace_back(std::abs(left_side - right_side));
        }
        auto min_iter = std::min_element(diffs.begin(), diffs.end());
        return *min_iter; 
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/2-CountingElements.pdf

    //////////////////////////////////////////////////////////////////////  
        
    //https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
    int FrogRiver(int X, std::vector<int> &A)  {
        std::unordered_set<int> st{};

        for(int i = 1; i <= X ;i++) 
                        st.emplace(i);

        for(size_t i = 0; i < A.size() ;i++) 
            if( st.contains(A[i])) {
                st.erase(A[i]);
                if( st.empty()) return i; 
            } 
        return -1;
    }

     //https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
    int PermCheck(std::vector<int> &A){
        /*
        A non-empty array A consisting of N integers is given.
        A permutation is a sequence containing each element from 1 to N once, and only once.
        */
        std::vector<int> checker = A;
        // dominant conplexity Onlogn
        std::sort(checker.begin(), checker.end());
        // check for a missing number for non permutation
        for(size_t i = 0; i < checker.size(); i++)
                        if((int)i+1 != checker[i]) return 0;
        // passed the test then is permutation
        return 1;
    }

     //https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/   
    std::vector<int> MaxCounters(int N, std::vector<int> &A) { 
        std::vector<int> counters(N,0); int maxValue=0;
        for(auto const& operation : A) 
            if(operation < N) { 
                counters[operation-1]++;
                maxValue = std::max(maxValue,counters[operation-1]);
            }
            else for(auto& c : counters) c = maxValue; 
        return counters;
    }

    //https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
    int MissingInteger(std::vector<int> &A) {
        std::unordered_set<int> set{};

        for(size_t i = 1; i <= A.size()+1; i++) set.insert(i);

        for(auto a : A) set.erase(a); 

        return *std::min_element(set.begin(),set.end());
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/3-PrefixSums.pdf

    //////////////////////////////////////////////////////////////////////  

    //https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/ 
    int PassingCars(std::vector<int> &A) {
        const int pair_limit = 1000000000;
        size_t numPassing = 0;
        // prefix sums
        std::vector<int> P(A.size(), 0);

        std::partial_sum(A.begin(), A.end(), P.begin());
        for (size_t i=0; i<A.size(); i++) {
            if (!A[i]) {  
                int num = P[A.size()-1] - P[i];
                numPassing += num;
                if (numPassing > pair_limit) return -1;  
            }
        }
        return numPassing;
    }

    // https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
    int CountDiv(int A, int B, int K) {
        int distance = B - A;
        std::unordered_set<int> set{};
        for(int i = 0; i <= distance;i++) {
            if((A+i) % K ==0){
                set.insert(i);
            }
        }
        return set.size();
    }

    // https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
    std::vector<int> GenomicRangeQuery(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
        std::vector<int> result{};
        std::vector<int> A, C, G, T; 
        A = C = G = T = std::vector<int>(S.size(),0);
        [[maybe_unused]] 
        int a{0},c{0},g{0},t{0};

        for(size_t i = 0; i <S.size(); i++) {
            switch (S[i]) {
            case 'A': a++; break;
            case 'C': c++; break;
            case 'G': g++; break;
            case 'T': t++; break;
            default:       break;
            };
            A[i] = a; C[i] = c; G[i] = g; T[i] = t;
        }
        for(size_t i = 0; i < P.size();i++) {
            //special case: one letter sequence
            if (P[i] == Q[i]) {
                switch (S[P[i]]) {
                case 'A': result.emplace_back(1); break;
                case 'C': result.emplace_back(2); break;
                case 'G': result.emplace_back(3); break;
                case 'T': result.emplace_back(4); break;
                default: break;
                };
                continue;
            }
            // check the impact of A on the sequence 
            if ((A[P[i]] < A[Q[i]]) || S[P[i]] == 'A') {
                result.emplace_back(1); continue;
            }
            // check the impact of C
            if ((C[P[i]] < C[Q[i]]) || S[P[i]] == 'C') {
                result.emplace_back(2); continue;
            }
            // check the impact of G
            if ((G[P[i]] < G[Q[i]]) || S[P[i]] == 'G') {
                result.emplace_back(3); continue;
            }
            // check the impact of T
            if ((T[P[i]] < T[Q[i]]) || S[P[i]] == 'T') {
                result.emplace_back(4); continue;
            }
        }
        return result;
    }

    // https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
    int MinAvgTwoSlice(std::vector<int> &A){
        /*
        1- have two pointers p < q;
        2- iterate through q to generate slices
        3- compute the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
        4- if gloabal_average is bigger then the current one then update it
        5- optemization: observation, the minimal average have to be at least in one of the smallest possible slice
           which lead us to the smallest way to slice and cover all possibility (odd and even). it's faster too scan just the slices of width 2 and 3. 
        */
        float min_avg_all = INT_MAX;
        float current_avg = INT_MAX;
        size_t min_avg_pos = 0L;
        int    prefix_sum  = 0;
        
        for (size_t p = 0; p < A.size(); p++) { 
            prefix_sum = A[p];

            for (size_t q = p + 1 ; q < A.size() 
                                    && (q - p + 1) <= 3; q++) { 
                prefix_sum += A[q];
                current_avg = prefix_sum * 1.0 / (q - p + 1);
                if (current_avg < min_avg_all) {
                    min_avg_all = current_avg;
                    min_avg_pos = p;
                }
            }
        }
        return min_avg_pos;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/4-Sorting.pdf

    //////////////////////////////////////////////////////////////////////  
        
    // https://app.codility.com/programmers/lessons/6-sorting/distinct/
    int Distincts(std::vector<int> &A) {
        std::unordered_set<int> set{}; //O1
        for(auto const& a : A) //On
            set.insert(a);
        return set.size();
    }

    // https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
    int MaxProductOfThree(std::vector<int> &A){
        /*
            The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
            N is an integer within the range [3..100,000];
            each element of array A is an integer within the range [−1,000..1,000].
            the maximal product of any triplet.

            - sort the array
            - the maximum of triplet should be on the top, but due to sign mirroring, 
              we should check the first triplet at the beginning (corner case 2 neg + 1 pos)
        */
       std::sort(A.begin(), A.end());//Onlogn
       return std::max(A[0]          * A[1]          * A[2]         ,
                       A[A.size()-3] * A[A.size()-2] * A[A.size()-1]);

    }

    // https://app.codility.com/programmers/lessons/6-sorting/triangle/
    int Triangle(std::vector<int> &A) {

        /*
        returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

        A[0] = 10    A[1] = 50    A[2] = 5 A[3] = 1    -> the function should return 0.
        
        */
        // N is an integer within the range [0..100,000];
        if(A.size() <= 3) return 0;
        std::sort(A.begin(), A.end()); //Onlogn
        for(size_t i = 2; i < A.size(); i++)  
            if(A[i] < A[i-1] + A[i-2]) return 1;
        return 0;
    }

    // https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
    int NumberOfDiscIntersections(std::vector<int> &A)  {
    /*
    - calculate the start and end points
    - calculate the intersections 
    */
    int size = A.size(), start{0}, end{0};

    std::vector<int> circle_start_points(size,0);
    std::vector<int> circle_end_points(size,0);

    // find start and end points of circles
    for(int i = 0; i < size; i++) {
         start = i - A[i]; 
         end   = A[i] + i; 

        if(start < 0 ) start = 0;
        if(end > size -1) end = size;

        circle_start_points[start]++;
        circle_end_points[end]++;
    }

    int open_circles{0};
    int intersection_count{0};
    // calculate the intersections of the circles
    for(int i = 0; i < size; i++) {
        if(circle_start_points[i] != 0) {
            // calculate intersections contributed by already open circles
            intersection_count += open_circles * circle_start_points[i];
            // intersections contributed starting at this point 
            intersection_count +=  circle_start_points[i] * (circle_start_points[i] -1)/2;
            if(intersection_count > 10000000) return -1;

            open_circles += circle_start_points[i];
        }
        open_circles -= circle_end_points[i];
    }
    return intersection_count;
   }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/5-Stacks.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
    int Brackets(std::string &S) {
        std::stack<char> st{};
        switch (S[0]) {
        case '(':
        case '[':
        case '{':
            st.emplace(S[0]); 
            break;
        default: return 0;
        }

        for(size_t i = 1; i <= S.length()-1;i++) {
            switch (S[i])
            {
            case '(':
            case '[':
            case '{':
                st.emplace(S[i]); break;

            case ')': if(st.top() == '(') st.pop(); else  st.emplace(S[i]);  break;
            case ']': if(st.top() == '[') st.pop(); else  st.emplace(S[i]);  break;
            case '}': if(st.top() == '{') st.pop(); else  st.emplace(S[i]);  break;
            default:  return 0;
            }
        }
        return (int) st.size() == 0;
    }
    
    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
    int Fish(std::vector<int> &A, std::vector<int> &B) {
        /*
            iterate through the arrays, if the current fish 
            is downstream oriented, add it to the opponent stack, 
            otherwise, declare it as survival by incrementeing the 
            survival count and then scan the opponent stack to 
            confirm its survival. If it counters a bigger opponent 
            then it (B[fish]). It dies -break to move to another fish-. 
            that's why decrease them survival counter. but if the opponent
            dies (fish is bigger) just pop it from the stack and let the 
            fish pass to the next opponent.  
            at the end of the day retrun the count of survivals  
            eather in the upstream (survivals) or downstream (stack size)  
        */
       /* std::stack<int> downstream{};
        int survivals{0}, fish{0}, 
            direction{0}, opponent{0}; 

        for(size_t i = 0; i < A.size(); i++) {
            //Aliassing
            fish      = A[i];
            direction = B[i];
            if(direction == 0) {
                // let's suppose that he survives now
                survivals++;
                while(!downstream.empty()) {
                    opponent = downstream.top();
                    if(opponent > fish) {
                        survivals--;// fish is dead
                        break;
                    } // opponent is dead
                    else downstream.pop(); 
                }
            }else downstream.push(fish);
        }
        return survivals + downstream.size();*/

        
        std::stack<int> st{}; int ctr{0}; 

        for(size_t i = 0; i < A.size(); i++) 
            if(B[i] == 0) {
                ctr++;
                while(!st.empty()) {
                    if(st.top() > A[i]) { ctr--; break; } 
                    else st.pop(); 
                }
            } else st.emplace(A[i]);
        
        return ctr + st.size();
        
    }

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
    int Nesting(std::string &S) {
        std::stack<char> st_left{},st_right{};
        for(char const& s : S)
        switch (s) {
        case '(':
        case '[':
        case '{':
            st_left.emplace(s); 
            break;
        case ')': 
        case ']': 
        case '}':
            st_right.emplace(s); 
            break; 
        default: return 0;
        }
        return (int) (st_left.size() == st_right.size());
    }

    // https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
    int StoneWall(std::vector<int> &H) {

        std::stack<int> st{}; int ctr{0};
        for(const auto h : H) {
            while(!st.empty() 
                && st.top() > h) st.pop(); 
            if(st.empty() 
            || st.top() != h) {
                st.emplace(h); ctr++;
            }
        }
        return ctr;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/6-Leader.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/8-leader/dominator/
    int Dominator(std::vector<int> &A) {
        std::unordered_map<int,int> mp{};

        for(size_t i = 0; i < A.size();i++) {
            if(mp.contains(A[i])) { 
                if(++mp[A[i]] > (int)A.size()/2) return i;
            } else mp.emplace(A[i],1);
        }
        return -1;
    }

    // https://app.codility.com/programmers/lessons/8-leader/equi_leader/
    int EquiLeader(std::vector<int> &A) {
        std::unordered_map<int,int> mp{};
        int leader{}, leader_count{0};
        ///////////////////////////////////////////
        // find the Dominator
        for(size_t i = 0; i < A.size();i++) {
            if(mp.contains(A[i])) { 
                if(++mp[A[i]] > (int)A.size()/2) {
                    leader = A[i];
                    leader_count = mp[A[i]];
                }
            } else mp.emplace(A[i],1);
        }
        if(leader_count == 0) return -1;
        ///////////////////////////////////////////
        int equileader_count{0}, left_pointer{0}, 
            right_pointer{(int)A.size()}, 
            right_leader_count{leader_count}, 
            left_leader_count{0}; 
        ///////////////////////////////////////////
        // check the equi leader repartions
        for(const auto a : A) {
            // if a is dominator re-adjust the counter repartition
            if(a == leader) {
                left_leader_count++;
                right_leader_count--;
            }
            // move the pointers to shrink the window
            left_pointer++; right_pointer--;
            // check for equileader [Dominator the same left and right sides]
            bool isEquileader = (left_leader_count > left_pointer/2) 
                            && (right_leader_count > right_pointer/2);
            // in case of equi leader increment                        
            if(isEquileader)  equileader_count++;
        }
        ///////////////////////////////////////////
        return equileader_count;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/7-MaxSlice.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
    int MaxProfit(std::vector<int> &A){
        int max_profit{0}, cumulative_profit{0};
        for(size_t i = 1; i < A.size();i++) {
            cumulative_profit += A[i] - A[i-1];
            if(cumulative_profit >0) 
              max_profit = (cumulative_profit > max_profit)
                          ? cumulative_profit : max_profit;
             else cumulative_profit = 0;
        }
        return max_profit;
    }

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
    int MaxSliceSum(std::vector<int> &A) {
        long sum{INT_MIN}, maxSum{INT_MIN};
        for(auto const& a : A) {
            sum    = std::max(sum + a, (long)a);
            maxSum = std::max(sum, maxSum);
        }
        return (int) maxSum;
    }

    // https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/    
    int MaxDoubleSliceSum(std::vector<int> &A) {
        size_t size = A.size();
        if(size <= 3) return 0;

        std::vector<int> left(size,0), right(size,0);

        int sum{0};
        for(size_t i = 1; i < size-1; i++) {
            sum += A[i];
            if(sum < 0) sum = 0;
            left[i] = sum;
        }
        sum =0;
        for(size_t i = size - 2; i >= 1; i--) {
            sum += A[i];
            if(sum < 0) sum = 0;
            right[i] = sum;
        }
        int max = 0;
        for(size_t i = 0; i < size - 2; i++) {
            max = std::max(left[i] + right[i+2],max);
        }
        return max;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/8-PrimeNumbers.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
    int CountFactors(int N) {
        // any number has at least 2 factors 1 and itself
        int counter{2}; 
        int stepper{};
        while(++stepper < N / 2) 
            if(N % stepper == 0) counter++;
        return counter;
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
    int MinPerimeterRectangle(int N)  {
        int min_perim{INT_MAX}; 
        int stepper{};
        while(++stepper < N / 2) 
            if(N % stepper == 0) 
                min_perim = std::min(min_perim, 
                            2 * (stepper + (N/stepper)));   
        return min_perim;
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
    int Flags(std::vector<int> &A) {
        int size = A.size();
        if(size < 3) 
            return 0;
        std::vector<int> peaks{};
        //avoid the borders
        for(int i= 1; i < size-1; i++) {
            if(A[i] > A[i-1] && A[i] > A[i+1])
                peaks.emplace_back(i);
        }
        int peaks_size = peaks.size();

        if(peaks_size <=1) 
            return peaks_size;

        int c =1, m =0, 
        i = std::min(peaks_size, (int) std::sqrt(size)) +1;

        for(; i > 1 ; i--) {
            int lastFlag{0};
            c = 1;
            for(int j = 1 ; j < peaks_size; j++) 
                if(peaks[j] - peaks[lastFlag]>=i && c < i) {
                    lastFlag = j;
                    c++;
                }
            
            if(c<m) return m;
            else if(m<c) m=c;
        }
        return m;
    }

    // https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
    int Peaks(std::vector<int> &A) {
        int size = A.size();
        if(size <= 3) return 0;
        std::vector<int> Peaks(size,0);
        for(auto i = 1; i < size-1 ; i++) {
            if(A[i] > A[i-1] && A[i] > A[i+1])
                Peaks[i] = 1;
        }

        int sum = std::accumulate(Peaks.begin(), Peaks.end(), 0);
        if(sum==0) 
            return 0;

        for(auto k = sum ; k >=2; k--) {
            if(size % k != 0) continue;

            auto n = size / k;
            int subsum = 0;
            int peaks_size = Peaks.size();
            for(int i =0; i < peaks_size; i++){
                subsum += Peaks[i];
                if( (i+1)%n == 0 && subsum < 1)
                    break;
                else if((i+1)%n == 0) {
                    subsum = 0; 
                }
                
                if(i == size-1) return k;
            }  
        }
        return 1;
   }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/9-Sieve.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/
    std::vector<int> CountNonDivisible(std::vector<int> &A) {
        std::vector<int> result{};
        std::vector<int> counts(*std::max_element(A.begin(),A.end()) + 1, 0);
        for(size_t i = 0; i < A.size(); i++) {
            counts[A[i]]++;
        }
        for(size_t i =0; i < A.size(); i++) {
            int s=0;
            for(int j=1; j*j <=A[i]; j++) {
                if(A[i]%j ==0) {
                    s += counts[j];
                    if(A[i]/j != j)
                         s += counts[A[i]/j];
                }
            }
            result.emplace_back(A.size()-s);
        }
        return result;
   }

    // https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_semiprimes/
    std::vector<int> 
    CountSemiprimes(int N, std::vector<int> &P, std::vector<int> &Q) {
        std::vector<int> primes(N+1,1);
        primes[0] = primes[1] = 0;

        for(int i=2; i*i<=N; i++) {
            if(primes[i]) {
                int k=i*i;
                while(k <=N){
                    primes[k]=0;
                    k+=i;
                }
            }
        }

        std::vector<int> semiprimes_all(N+1,0);
        for(int i = 0; i <= N;i++) {
            for(int j = 0; j <= N; j++) {
                if(primes[i]*primes[j]==1 && i*j <=N) {
                    semiprimes_all[i*j] = 1;
                }
                if(i*j >N) 
                    break;
            }
        }
         std::vector<int> semiprimes(P.size(),0), semiprimes_cumul(N+1,0);

         int sum{0};
         for(int i=0; i <N+1;i++) {
            sum += semiprimes_all[i];
            semiprimes_cumul[i] = sum;
         }
         for(size_t i= 0; i < P.size(); i++) {
            semiprimes[i] = semiprimes_cumul[Q[i]] - semiprimes_cumul[P[i]-1];
         }

        return semiprimes;
   }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/common_prime_divisors/   
    int CommonPrimeDivisors(std::vector<int> &A, std::vector<int> &B) {

        std::function<int(int,int)> gcd;
        gcd = [&gcd](int a, int b) -> int {
             if (a%b == 0) return b;
            else return gcd(b,a%b);
        };
        int size = A.size();
        int a, b, D, count = 0;
        for(int i = 0; i < size; i++) {
            a = A[i];
            b = B[i];
            D = gcd(a,b);
            while(gcd(a,D) != 1) {
                a /= gcd(a,D);
            }
            while(gcd(b,D) != 1) {
                b /= gcd(b,D);
            }
            if(a ==1 && b ==1) count++;
        }
        return count;
   }

    // https://app.codility.com/programmers/lessons/12-euclidean_algorithm/chocolates_by_numbers/
    int ChocolatesByNumbers(int N, int M) {
        // gcd closure
        std::function<int(int,int)> gcd;
        gcd = [&gcd](int a, int b) -> int {
             if (a%b == 0) return b;
            else return gcd(b,a%b);
        };
        return N/gcd(N,M);
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/11-Fibonacci.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/fib_frog/
    int FibFrog(std::vector<int> &A) {
        // padding by one to include the other side border
        A.emplace_back(1);
        std::vector<float> fib(100,0);
        fib[1] = 1;
        //generate the fib values
        for(size_t i =2; i < fib.size(); i++) {
            fib[i] = fib[i-1] + fib[i-2];
            if(fib[i]> A.size()) break;
        }
        // erase the 2 first items
        fib.erase(fib.begin()); 
        fib.erase(fib.begin());

        std::vector<int> reach_path(A.size(),0);

        for(size_t i =0; i < A.size(); i++) {
            if(A[fib[i]-1] == 1) 
                reach_path[fib[i]-1]=1;
        }

        for(size_t i =0; i < A.size(); i++) {

            if(A[i] == 0 || reach_path[i]> 0)
                continue;

            int min_i = -1;
            int min_v = 100000;
            for(size_t j = 0; j < fib.size(); j++) {
                int prev_i = i - fib[j];
                if(prev_i<0) break;
                
                if((reach_path[prev_i] > 0) && (min_v > reach_path[prev_i])) {
                    min_v = reach_path[prev_i];
                    min_i = prev_i;
                }
            }
            if(min_i != -1) 
                reach_path[i] = min_v+1;
        }

        if(reach_path[A.size() -1] >0) 
             return reach_path[A.size() -1];
        else return -1;
   }

    // https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/
    std::vector<int> 
    Ladder(std::vector<int> &A, std::vector<int> &B){
        std::vector<int> result(A.size(),0);
        int max_A = 0;
        for(auto const& a : A) 
            max_A = std::max(max_A, a);
        
        std::vector<int> fib(A.size()+1,0); 
        fib[0] = 1;
        fib[1] = 1;
        
        for(size_t i = 2; i < fib.size(); i++) 
            fib[i] = (fib[i-1] + fib[i-2]) % (int) std::pow(2,30);

        int mem=0;
        for(size_t i = 0; i < A.size(); i++){
            mem = (int) std::pow(2,B[i]);
            result[i] = fib[A[i]] % mem ;
        }
        return result;
   }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/
    int MinMaxDivision(int K, int M, std::vector<int> &A) {
        //closure
        std::function<bool(int,std::vector<int>,int)> 
        validateSolution = [](int K, std::vector<int> A, int max_sum)->bool {
            int numBlocks = 1; int sum = 0;
            for (const auto &a: A) {
                sum += a;
                if ( sum > max_sum ) {
                    numBlocks++;
                    sum = a;
                }
                if (numBlocks > K) return false;
            } return true; 
        };
            
        // Going to use B to reduce the rank of A, since 0s do not count toward
        // anything.  Might as well reduce overhead.
        std::vector<int> B;

        // Binary search uses information that data is sorted, so this
        // means we are going to use partial sums which will be sorted
        // But reduce the number of elements so that Rank(P) = Rank(A)+1;
        int sum = 0;
        int max = 0;
        for (size_t i=0; i< A.size(); i++) {
            if (A[i]) {
                B.emplace_back(A[i]);
                sum+= A[i];
                max = std::max(max, A[i]);
            }
        }

        // Quick check - if B is empty then return 0
        if (B.empty()) return 0;
        

        // Quick check - if Rank(B) <= K then answer is max(B);
        if ((int) B.size() <= K) 
            return *std::max_element(std::begin(B), std::end(B));
        

        // The answer is somewhere between max(A) and sum(A)
        int lowerBound = max;
        int upperBound = sum;

        // Implement the classic binary search algorithm
        while ( lowerBound <= upperBound ) {
            int candidate = (lowerBound+upperBound)/2;
            if ( validateSolution(K, B, candidate) ) {
                upperBound = candidate - 1;
            } else {
                lowerBound = candidate + 1;
            }
        }
        return lowerBound;
   }

    // https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/
    int NailingPlanks(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {

        //closure 
        std::function<int(int,int,std::vector<std::vector<int>>,int)>
        getMinIndex = [] (int startPlank, int endPlank, 
                          std::vector<std::vector<int>> nail, int preIndex) {
            int min = 0;
            int max = nail.size() - 1;
            int minIndex = -1;
            while (min <= max) {
                int mid = (min + max) / 2;
                if (nail[mid][0] < startPlank)
                    min = mid + 1;
                else if (nail[mid][0] > endPlank)
                    max = mid - 1;
                else {
                    max = mid - 1;
                    minIndex = mid;
                }
            }
            if (minIndex == -1) return -1;

            int minIndexOrigin = nail[minIndex][1];
            // this check is to get the minimal index of the original array of nails
            for (size_t i = minIndex; i < nail.size(); i++) {
                if (nail[i][0] > endPlank)
                    break;
                minIndexOrigin = std::min(minIndexOrigin, nail[i][1]);
                // we need the maximal index of nails to nail every plank, so the
                // smaller index can be omitted
                if (minIndexOrigin <= preIndex)
                    return preIndex;
            }
            return minIndexOrigin;
        };

        int N = A.size();
        int M = C.size();
        // two dimension array to save the original index of array C
        std::vector< std::vector<int>> 
        sortedNail(M,std::vector<int>(2,0));
        for (int i = 0; i < M; i++) {
            sortedNail[i][0] = C[i];
            sortedNail[i][1] = i;
        }

        // for each plank , we can use binary search to get the minimal index of the
        // sorted array of nails, and we should check the candidate nails to get the
        // minimal index of the original array of nails.

        // use the lambda expression to sort the two dimension array based on index C
        std::sort(sortedNail.begin(), sortedNail.end(), 
             [](std::vector<int> const& p1, 
                std::vector<int> const& p2) {
                return p1[0] < p2[0]; 
            });
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            result = getMinIndex(A[i], B[i], sortedNail, result);
            if (result == -1)
                return -1;
        }
        return result + 1;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/13-CaterpillarMethod.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/abs_distinct/
    int AbsDistinct(std::vector<int> &A) {
        std::unordered_set<int> st{};
        int counter{0};
        for(auto a : A)
            if(!st.contains(std::abs(a))) {
                st.emplace(std::abs(a));
                counter++;
            }
        return counter;
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_distinct_slices/
    int CountDistinctSlices(int M, std::vector<int> &A) {
        const int size  = A.size();
        const int limit = 1000000000;
        int front_pointer{0},back_pointer{0}, counter{0};
        std::unordered_set<int> st{};

        if( M> limit) return limit;
        while(size > front_pointer  
           || size > back_pointer) {

            if(size > front_pointer && !st.contains(A[front_pointer])) {
                st.emplace(A[front_pointer]);
                front_pointer++;
                counter += st.size();

                if(counter >= limit) return limit;
            } else {
                st.erase(A[back_pointer]);
                back_pointer++;
            }
        }

       return counter;
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/count_triangles/
    int CountTriangles(std::vector<int> A) {

        std::sort(A.begin(),A.end());

        size_t triangle_counter{0};
        size_t front_ptr{0};

        for(size_t back_ptr = 0; 
                   back_ptr < A.size()-2; back_ptr++) {

            front_ptr = back_ptr + 2;

            for(size_t mid_ptr = back_ptr + 1; 
                       mid_ptr < A.size()-1; mid_ptr++) {

                while(front_ptr < A.size() &&  
                     A[back_ptr] + A[mid_ptr] > A[front_ptr] )  front_ptr++;

                triangle_counter += front_ptr - mid_ptr - 1;
            }
        }
        return triangle_counter;
    }

    // https://app.codility.com/programmers/lessons/15-caterpillar_method/min_abs_sum_of_two/
    int MinAbsSumOfTwo(std::vector<int> &A) {
        // first sort the vector
        std::sort(A.begin(), A.end(), std::less());
        // define the start and end index pointers
        int start_index{0};
        int end_index = A.size()-1;
        int minimal_absolute_sum{INT_MAX};
        // scan the vector until the pointers overlap
        while(start_index < end_index) {
            // calculate the abs sum of the pointers and save it if minimal
            minimal_absolute_sum = std::min(minimal_absolute_sum,
                                   std::abs(A[start_index] + A[end_index]));
            // shrink the window by moving the heavier pointer (bigger abs)
            if(std::abs(A[start_index]) < std::abs(A[end_index]) ){
                end_index--;
            } else start_index++;
        }
        //return the minimal saved value
        return minimal_absolute_sum;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/14-GreedyAlgorithms.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/max_nonoverlapping_segments/
    int MaxNonoverlappingSegments(std::vector<int> &A, std::vector<int> &B) { 
        int no_overlap_secment_count{0};
        int current_pointer = -1;

        for(size_t i = 0; i < A.size(); i++)
            if(A[i] > current_pointer) {
                current_pointer = B [i];
                no_overlap_secment_count++;
            }
        return no_overlap_secment_count;
    }

    // https://app.codility.com/programmers/lessons/16-greedy_algorithms/tie_ropes/
    int TieRopes(int K, std::vector<int> &A) { 
        /*      =      =          |            |     =    =
           1 __   2____   3______   4________   1__   1__   3______
             1      2        3         4         5     6      7
        
            ropes:  123 / 4 / 567
        */
       int rope_counter{1};
       int current_length{0};

       for(size_t i =0 ; i < A.size(); i++) {
            current_length    += A[i];
            if(current_length  > K) {
                current_length = 0;
                rope_counter++;
            }
        }
        return rope_counter;
    }

    //////////////////////////////////////////////////////////////////////

    // https://codility.com/media/train/15-DynamicProgramming.pdf

    //////////////////////////////////////////////////////////////////////

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/number_solitaire/
    int NumberSolitaire(std::vector<int> &A) {
       // create a memo vector to ttrack the score
        std::vector<int> note(A.size(),INT_MIN+1); // +1 to avoid the undefined behaviour with min int
        // isolate corner case index 0 
        note[0] = A[0];
        // roll the dice
        for(size_t i = 0; i < A.size();i++) 
            // review the old score 
            for(size_t j = i + 1; 
                       j < A.size() && 
                       j < i + 7; j++)   
                //find the maximum using the prefix note
                note[j] = std::max(note[j], note[i] + A[j]);
        // the last computed operation is the target
        return note[A.size()-1];
    }

    // https://app.codility.com/programmers/lessons/17-dynamic_programming/min_abs_sum/
    int MinAbsSum(std::vector<int> &A) { 
        //val(A, S) = |sum{ A[i]*S[i] for i = 0..N−1 }|
		if (A.size() == 0) return 0;
		if (A.size() == 1) return A[0];

		int max = *std::max_element(A.begin(), A.end());

        int sum = 0; for (size_t i = 0; i < A.size(); i++) {
			A[i] = std::abs(A[i]);
			sum += A[i];
		}


		std::vector<int>  count(max + 1,0);
		for (int num : A) count[num]++;
		

		std::vector<int> dp(sum + 1,-1);
		dp[0] = 0;

		for (int i = 0; i <= max; i++) {
			if (count[i] > 0) {
				for (int val = 0; val <= sum; val++) {
					if (dp[val] >= 0)
						dp[val] = count[i];
					else if (val >= i && dp[val - i] > 0) {
						dp[val] = dp[val - i] - 1;
					}
				}
			}
		}

		int result = sum;
		for (int i = 0; i <= sum / 2; i++) {
			if (dp[i] >= 0)
				result = std::min(result, sum - (2 * i));
		}
		return result;
    }

}}
