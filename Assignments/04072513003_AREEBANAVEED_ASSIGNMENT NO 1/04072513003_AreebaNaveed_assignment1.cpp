// 04072513003_AreebaNaveed_assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <string>

// Clock used for measuring execution time.
// using is an allias clock is avariable.
using Clock = std::chrono::steady_clock;//calculate ellapse time.


// Number of elements.
const int N = 100000;


// Generate random numbers.
std::vector<int> generateRandom()
{
    std::random_device rd;//seed value.
    std::mt19937 gen(rd());

    // Random integers between 1 and 1,000,000.
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::vector<int> values;

    for (int i = 0; i < N; i++)
    {
        values.push_back(dist(gen));
    }

    return values;
}


// Calculate elapsed time in milliseconds.
double getTime(Clock::time_point start, Clock::time_point end)//starttime and endtime give us a time, time point is its datatype
{
    return std::chrono::duration<double, std::milli>(end - start).count();
}


// Display operation name and execution time.
void printTime(const std::string& operation, double time)
{
    std::cout << std::left << std::setw(35) << operation
        << std::right << std::setw(12) << std::fixed
        << std::setprecision(3) << time << " ms" << std::endl;
}


// ---------------- HEAP SORT ----------------

// ReheapDown maintains the max heap property.
template <typename t>
void ReheapDown(std::vector<t>& v, int first, int last)
{
    int left, right, max;

    left = first * 2 + 1;
    right = first * 2 + 2;
    max = left;

    while (left <= last)
    {
        // Select the larger child.
        if (right <= last && v[right] > v[left])
        {
            max = right;
        }

        // Swap parent with larger child if necessary.
        if (v[first] < v[max])
        {
            std::swap(v[first], v[max]);

            first = max;
            left = first * 2 + 1;
            right = first * 2 + 2;
            max = left;
        }
        else
        {
            break;
        }
    }
}


// Heap Sort arranges vector in ascending order.
template <typename t>
void heapSort(std::vector<t>& v)
{
    int n = static_cast<int>(v.size());

    // Build a valid max heap.
    for (int i = (n / 2) - 1; i >= 0; --i)
    {
        ReheapDown(v, i, n - 1);
    }

    // Move the largest element to the end.
    for (int i = n - 1; i > 0; --i)
    {
        int first = 0;
        int last = i;

        std::swap(v[first], v[last]);

        ReheapDown(v, 0, i - 1);
    }
}


// ---------------- INSERTION SORT ----------------

void insertionSort(std::vector<int>& arr)
{
    int n = static_cast<int>(arr.size());
    int num;

    for (int i = 1; i < n; i++)
    {
        num = arr[i];

        int j = i - 1;

        while (j >= 0)
        {
            if (num < arr[j])
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = num;
    }
}


// ---------------- MAIN FUNCTION ----------------

int main()
{
    // Generate random values only once.
    // The same values are used for all containers.
    std::vector<int> randomValues = generateRandom();
    
    // PART 1: VECTOR

    std::cout << std::endl;
    std::cout << "---------- VECTOR ----------" << std::endl;

    std::vector<int> A, B, C;
    std::vector<int> E, F, G;


    // A: Ascending insertion.
    auto startTime = Clock::now();

    for (int i = 1; i <= N; i++)
    {
        A.push_back(i);
    }

    auto endTime = Clock::now();

    printTime("Vector - Ascending Insertion",
        getTime(startTime, endTime));


    // B: Descending insertion.
    startTime = Clock::now();

    for (int i = N; i >= 1; i--)
    {
        B.push_back(i);
    }

    endTime = Clock::now();

    printTime("Vector - Descending Insertion",
        getTime(startTime, endTime));


    // C: Random insertion.
    startTime = Clock::now();

    for (int i = 0; i < N; i++)
    {
        C.push_back(randomValues[i]);
    }

    endTime = Clock::now();

    printTime("Vector - Random Insertion",
        getTime(startTime, endTime));


    // we store original data for Heap Sort.
    std::vector<int> HA = A;
    std::vector<int> HB = B;
    std::vector<int> HC = C;


    // STL sorting.
    startTime = Clock::now();
    std::sort(A.begin(), A.end());
    endTime = Clock::now();

    printTime("Vector - STL Sort A",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::sort(B.begin(), B.end());
    endTime = Clock::now();

    printTime("Vector - STL Sort B",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::sort(C.begin(), C.end());
    endTime = Clock::now();

    printTime("Vector - STL Sort C",
        getTime(startTime, endTime));


    // E: Ascending insertion.
    startTime = Clock::now();

    for (int i = 1; i <= N; i++)
    {
        E.push_back(i);
    }

    endTime = Clock::now();

    printTime("Vector - E Ascending Insertion",
        getTime(startTime, endTime));


    // F: Descending insertion.
    startTime = Clock::now();

    for (int i = N; i >= 1; i--)
    {
        F.push_back(i);
    }

    endTime = Clock::now();

    printTime("Vector - F Descending Insertion",
        getTime(startTime, endTime));


    // G: Random insertion.
    startTime = Clock::now();

    for (int i = 0; i < N; i++)
    {
        G.push_back(randomValues[i]);
    }

    endTime = Clock::now();

    printTime("Vector - G Random Insertion",
        getTime(startTime, endTime));


    // we store E, F and G before deleting odd numbers.
    std::vector<int> IE = E;
    std::vector<int> IF = F;
    std::vector<int> IG = G;


    // Delete odd numbers using std::erase_if().
    // The lambda returns true for odd numbers.

    startTime = Clock::now();
    std::erase_if(E, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Vector - Delete Odd from E",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(F, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Vector - Delete Odd from F",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(G, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Vector - Delete Odd from G",
        getTime(startTime, endTime));


    // PART 1: list

    std::cout << std::endl;
    std::cout << "------------ LIST ---------" << std::endl;

    std::list<int> LA, LB, LC;
    std::list<int> LE, LF, LG;


    // Ascending insertion.
    startTime = Clock::now();

    for (int i = 1; i <= N; i++)
    {
        LA.push_back(i);
    }

    endTime = Clock::now();

    printTime("List - Ascending Insertion",
        getTime(startTime, endTime));


    // Descending insertion.
    startTime = Clock::now();

    for (int i = N; i >= 1; i--)
    {
        LB.push_back(i);
    }

    endTime = Clock::now();

    printTime("List - Descending Insertion",
        getTime(startTime, endTime));


    // Random insertion.
    startTime = Clock::now();

    for (int i = 0; i < N; i++)
    {
        LC.push_back(randomValues[i]);
    }

    endTime = Clock::now();

    printTime("List - Random Insertion",
        getTime(startTime, endTime));


    // List uses its own member sort().
    startTime = Clock::now();
    LA.sort();
    endTime = Clock::now();

    printTime("List - Sort A",
        getTime(startTime, endTime));


    startTime = Clock::now();
    LB.sort();
    endTime = Clock::now();

    printTime("List - Sort B",
        getTime(startTime, endTime));


    startTime = Clock::now();
    LC.sort();
    endTime = Clock::now();

    printTime("List - Sort C",
        getTime(startTime, endTime));


    // E: Ascending insertion.
    startTime = Clock::now();

    for (int i = 1; i <= N; i++)
    {
        LE.push_back(i);
    }

    endTime = Clock::now();

    printTime("List - E Ascending Insertion",
        getTime(startTime, endTime));


    // F: Descending insertion.
    startTime = Clock::now();

    for (int i = N; i >= 1; i--)
    {
        LF.push_back(i);
    }

    endTime = Clock::now();

    printTime("List - F Descending Insertion",
        getTime(startTime, endTime));


    // G: Random insertion.
    startTime = Clock::now();

    for (int i = 0; i < N; i++)
    {
        LG.push_back(randomValues[i]);
    }

    endTime = Clock::now();

    printTime("List - G Random Insertion",
        getTime(startTime, endTime));


    // Delete odd numbers.
    startTime = Clock::now();
    std::erase_if(LE, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("List - Delete Odd from E",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(LF, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("List - Delete Odd from F",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(LG, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("List - Delete Odd from G",
        getTime(startTime, endTime));

    // PART 1: FORWARD LIST

    std::cout << std::endl;
    std::cout << "----------- FORWARD LIST ----------" << std::endl;

    std::forward_list<int> FA, FB, FC;
    std::forward_list<int> FE, FF, FG;


    // Forward_list does not have push_back().
    // We use insert_after() and keep track of the last position.

    // Ascending insertion.
    startTime = Clock::now();

    {
        auto it = FA.before_begin();

        for (int i = 1; i <= N; i++)
        {
            it = FA.insert_after(it, i);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - Ascending Insertion",
        getTime(startTime, endTime));


    // Descending insertion.
    startTime = Clock::now();

    {
        auto it = FB.before_begin();

        for (int i = N; i >= 1; i--)
        {
            it = FB.insert_after(it, i);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - Descending Insertion",
        getTime(startTime, endTime));


    // Random insertion.
    startTime = Clock::now();

    {
        auto it = FC.before_begin();

        for (int i = 0; i < N; i++)
        {
            it = FC.insert_after(it, randomValues[i]);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - Random Insertion",
        getTime(startTime, endTime));


    // Forward_list uses its own member sort().
    startTime = Clock::now();
    FA.sort();
    endTime = Clock::now();

    printTime("Forward List - Sort A",
        getTime(startTime, endTime));


    startTime = Clock::now();
    FB.sort();
    endTime = Clock::now();

    printTime("Forward List - Sort B",
        getTime(startTime, endTime));


    startTime = Clock::now();
    FC.sort();
    endTime = Clock::now();

    printTime("Forward List - Sort C",
        getTime(startTime, endTime));


    // E: Ascending insertion.
    startTime = Clock::now();

    {
        auto it = FE.before_begin();

        for (int i = 1; i <= N; i++)
        {
            it = FE.insert_after(it, i);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - E Ascending Insertion",
        getTime(startTime, endTime));


    // F: Descending insertion.
    startTime = Clock::now();

    {
        auto it = FF.before_begin();

        for (int i = N; i >= 1; i--)
        {
            it = FF.insert_after(it, i);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - F Descending Insertion",
        getTime(startTime, endTime));


    // G: Random insertion.
    startTime = Clock::now();

    {
        auto it = FG.before_begin();

        for (int i = 0; i < N; i++)
        {
            it = FG.insert_after(it, randomValues[i]);
        }
    }

    endTime = Clock::now();

    printTime("Forward List - G Random Insertion",
        getTime(startTime, endTime));


    // Delete odd numbers.
    startTime = Clock::now();
    std::erase_if(FE, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Forward List - Delete Odd from E",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(FF, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Forward List - Delete Odd from F",
        getTime(startTime, endTime));


    startTime = Clock::now();
    std::erase_if(FG, [](int x) { return x % 2 != 0; });
    endTime = Clock::now();

    printTime("Forward List - Delete Odd from G",
        getTime(startTime, endTime));

    // PART 2: HEAP SORT

    std::cout << std::endl;
    std::cout << "---------- HEAP SORT ----------" << std::endl;

    // HA, HB and HC contain original unsorted data.

    startTime = Clock::now();
    heapSort(HA);
    endTime = Clock::now();

    printTime("Heap Sort - A",
        getTime(startTime, endTime));


    startTime = Clock::now();
    heapSort(HB);
    endTime = Clock::now();

    printTime("Heap Sort - B",
        getTime(startTime, endTime));


    startTime = Clock::now();
    heapSort(HC);
    endTime = Clock::now();

    printTime("Heap Sort - C",
        getTime(startTime, endTime));

    // PART 2: INSERTION SORT

    std::cout << std::endl;
    std::cout << "---------- INSERTION SORT ----------" << std::endl;

    // IE, IF and IG contain original E, F and G.

    startTime = Clock::now();
    insertionSort(IE);
    endTime = Clock::now();

    printTime("Insertion Sort - E",
        getTime(startTime, endTime));


    startTime = Clock::now();
    insertionSort(IF);
    endTime = Clock::now();

    printTime("Insertion Sort - F",
        getTime(startTime, endTime));


    startTime = Clock::now();
    insertionSort(IG);
    endTime = Clock::now();

    printTime("Insertion Sort - G",
        getTime(startTime, endTime));


    std::cout << std::endl;
    std::cout << "All operations completed." << std::endl;

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
