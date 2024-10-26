// // Merge function to combine two sorted halves of the array
// void merge(std::vector<int>& vec, int left, int mid, int right)
// {
//     int n1 = mid - left + 1; // Size of left half
//     int n2 = right - mid;    // Size of right half

//     std::vector<int> leftVec(n1);
//     std::vector<int> rightVec(n2);

//     // Copy data to temporary vectors
//     for (int i = 0; i < n1; i++)
//         leftVec[i] = vec[left + i];
//     for (int j = 0; j < n2; j++)
//         rightVec[j] = vec[mid + 1 + j];

//     // Merge the temporary vectors back into vec
//     int i = 0; // Initial index of first sub-array
//     int j = 0; // Initial index of second sub-array
//     int k = left; // Initial index of merged sub-array

//     while (i < n1 && j < n2)
// 	{
//         if (leftVec[i] <= rightVec[j])
// 		{
//             vec[k] = leftVec[i];
//             i++;
//         }
// 		else
// 		{
//             vec[k] = rightVec[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of leftVec, if any
//     while (i < n1)
// 	{
//         vec[k] = leftVec[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of rightVec, if any
//     while (j < n2)
// 	{
//         vec[k] = rightVec[j];
//         j++;
//         k++;
//     }
// }

// // Ford-Johnson sorting algorithm
// void fordJohnsonSort(std::vector<int>& vec, int left, int right)
// {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         fordJohnsonSort(vec, left, mid);
//         fordJohnsonSort(vec, mid + 1, right);
//         merge(vec, left, mid, right);
//     }
// }



#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>

// Merge function to combine two sorted halves of the container
template <typename T>
void merge(T& T, typename T::iterator left, typename T::iterator mid, typename T::iterator right)
{
    // Create temporary Ts for merging
    std::vector<typename T::value_type> leftVec(left, mid + 1);
    std::vector<typename T::value_type> rightVec(mid + 1, right + 1);

    auto i = 0, j = 0;
    auto k = left;

    // Merge the two halves
    while (i < leftVec.size() && j < rightVec.size())
	{
        if (leftVec[i] <= rightVec[j])
            *k++ = leftVec[i++];
        else
            *k++ = rightVec[j++];
    }

    // Copy remaining elements from leftVec, if any
    while (i < leftVec.size())
        *k++ = leftVec[i++];

    // Copy remaining elements from rightVec, if any
    while (j < rightVec.size())
        *k++ = rightVec[j++];
}

template <typename T>
void fordJohnsonSort(T& container, typename T::iterator left, typename T::iterator right)
{
    if (left < right)
	{
        typename T::iterator mid = left + std::distance(left, right) / 2;
        fordJohnsonSort(container, left, mid);
        fordJohnsonSort(container, mid + 1, right);
        merge(container, left, mid, right);
    }
}

int main() {
    // Example with std::vector
    std::vector<int> vecData = {5, 2, 9, 1, 5, 6};
    fordJohnsonSort(vecData, vecData.begin(), vecData.end() - 1);
    std::cout << "Sorted vector: ";
    for (const auto& num : vecData) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example with std::deque
    std::deque<int> dequeData = {3, 7, 2, 4, 8, 1};
    fordJohnsonSort(dequeData, dequeData.begin(), dequeData.end() - 1);
    std::cout << "Sorted deque: ";
    for (const auto& num : dequeData) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
