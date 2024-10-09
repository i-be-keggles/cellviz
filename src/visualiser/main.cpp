#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "backend/cellviz.h"
#include "backend/board.h"
#include "backend/cells.h"

void update_window(Board board, sf::RenderWindow &window){
    for (int x = 0; x < window.getSize().x; ++x) {
        for (int y = 0; y < window.getSize().y; ++y) {
            CellularAutomaton * c = board.get_cell(x,y);
        }
    }
}

void do_window_thing(sf::RenderWindow &window){
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Loop through each pixel of the window
        for (int x = 0; x < window.getSize().x; ++x) {
            for (int y = 0; y < window.getSize().y; ++y) {
                // Generate a random color
                sf::Color randomColor(std::rand() % 256, std::rand() % 256, std::rand() % 256);
                // Set the pixel color using a small rectangle
                sf::RectangleShape pixel(sf::Vector2f(1, 1)); // 1x1 pixel
                pixel.setPosition(static_cast<float>(x), static_cast<float>(y));
                pixel.setFillColor(randomColor);
                window.draw(pixel);
            }
        }

        // Display the contents of the window
        window.display();
    }
}

int main() {
    int size = 100;

    Board board = initialise_board(size);

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(size, size), "Cellular automaton visualiser");

    while (window.isOpen()) {
        SmithLife::compute(&board);
        update_window(board, window);
    }

    int runtime = 1000;
    runtime = 0;

    for(int i = 0; i < runtime; i++){
        SmithLife::compute(&board);
        update_window(board, window);
    }

    return 0;
}