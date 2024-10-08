#include <SFML/Graphics.hpp>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create a window with the size of 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Random Color Pixels with SFML");

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

    return 0;
}
