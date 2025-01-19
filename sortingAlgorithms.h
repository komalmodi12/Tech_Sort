#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <SFML/Graphics.hpp>
#include <vector>

// Function to visualize the array
void visualizeArray(sf::RenderWindow &window, const std::vector<int> &arr, int highlightedIndex = -1);

// Sorting algorithms
void bubbleSort(sf::RenderWindow &window, std::vector<int> &arr);
void quickSort(sf::RenderWindow &window, std::vector<int> &arr, int low, int high);
void mergeSort(sf::RenderWindow &window, std::vector<int> &arr, int left, int right);
int partition(std::vector<int> &arr, int low, int high);
void merge(std::vector<int> &arr, int left, int mid, int right);

#endif // SORTING_ALGORITHMS_H
