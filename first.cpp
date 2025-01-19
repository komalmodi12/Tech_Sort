#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "sortingAlgorithms.h"

// Visualization parameters
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BAR_WIDTH = 20;

void visualizeArray(sf::RenderWindow &window, const std::vector<int> &arr, int highlightedIndex)
{
    window.clear();
    int maxVal = *std::max_element(arr.begin(), arr.end());

    for (size_t i = 0; i < arr.size(); ++i)
    {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, (arr[i] / float(maxVal)) * WINDOW_HEIGHT));
        bar.setPosition(sf::Vector2f(i * BAR_WIDTH, WINDOW_HEIGHT - bar.getSize().y));
        bar.setFillColor(i == highlightedIndex ? sf::Color::Red : sf::Color::White);
        window.draw(bar);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

int main()
{
    // Create SFML window with corrected VideoMode constructor (using Vector2u)
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Sorting Visualizer");

    // Create a random array of integers
    // std::vector<int> arr(WINDOW_WIDTH / BAR_WIDTH);
    std::vector<int> arr(20);
    std::generate(arr.begin(), arr.end(), []()
                  { return rand() % 100 + 1; });
    std::cout << "The array taken is: \n";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    while (window.isOpen())
    {
        // Poll events
        std::optional<sf::Event> event = window.pollEvent();

        if (event)
        { // Check if there's an event
            // Check for window close event using is<sf::Event::Closed>()
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Visualize Sorting Algorithms
        bubbleSort(window, arr); // Replace with other sorting algorithms as needed
        // quickSort(window, arr, 0, arr.size() - 1);
       // mergeSort(window, arr, 0, arr.size());
        break; // Stop after one sort for now
    }

    return 0;
}
