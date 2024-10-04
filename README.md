# Tetris Game
This project is a C++ implementation of the classic Tetris game, utilizing the SFML library to handle graphics, rendering, and game mechanics. 
Tetris is a tile-matching puzzle game where the objective is to manipulate falling blocks, called Tetromino, to form complete rows, which 
are then cleared from the board. The game speeds up as the player progresses, and the objective is to survive as long as possible without the blocks 
stacking to the top of the game board.
# Gameplay Mechanics
- **Tetrominoes:** The game features 7 distinct shapes (I, O, T, S, Z, J, L), known as Tetrominoes, each made up of four squares arranged in different configurations.
- **Board:** The game is played on a grid (10 columns by 20 rows). Tetrominoes fall from the top and can be rotated and moved left or right by the player before they lock into place.
- **Row Clearing:** When a row is completely filled with blocks, it is cleared, and all blocks above it move down by one row. Clearing multiple rows in quick succession rewards additional points.
- **Game Over:** The game ends when there is no room for new Tetrominoes to appear at the top of the board, i.e., when the blocks stack too high.
# Key Features
1. **Real-Time Gameplay:** The game runs continuously with Tetrominoes falling at increasing speed as the player progresses.
2. **Rotation and Movement:** Players can rotate Tetrominoes clockwise and move them left or right using keyboard input.
3. **Row Clearing:** Full rows of blocks are cleared from the board, adding to the player's score.
4. **Score System:** Points are awarded based on the number of rows cleared at once (single, double, triple, or "Tetris" clears).
5. **Levels:** As the player clears more rows, the game's difficulty increases, making the Tetrominoes fall faster.
# Controls
- **Left Arrow:** Move the current Tetromino left.
- **Right Arrow:** Move the current Tetromino right.
- **Up Arrow:** Rotate the Tetromino clockwise.
- **Down Arrow:** Speed up the falling Tetromino.
# Game Flow
1. **Spawn Tetromino:** A new Tetromino is generated at the top of the grid.
2. **Player Input:** The player controls the Tetromino's movement and rotation.
3. **Collision Detection:** The game checks if the Tetromino has collided with the bottom of the grid or with other blocks.
4. **Locking:** If a Tetromino can no longer move, it locks into place, and a new one spawns.
5. **Row Clearing:** If any rows are completely filled, they are cleared.
6. **Game Over Check:** If the Tetrominoes reach the top of the screen, the game ends.
# Libraries Used
- **SFML (Simple and Fast Multimedia Library):** This game uses SFML, a powerful C++ library for handling multimedia applications, including games. SFML provides functionalities for:

    - **Graphics:** Displaying the Tetrominoes, grid, and score on the screen.
    - **Window Management:** Handling window creation, input events, and the game loop.
    - **Input Handling:** Capturing keyboard inputs for controlling Tetrominoes.
    - Time Management: Handling game speed, event timing, and frame rate.
## Installation
To run this project, you need to have SFML installed. Below are the steps to set up SFML in your environment.
### Windows
1. Download SFML from the official SFML website.
2. Extract the downloaded files and place them in a directory.
3. Set up your development environment (Visual Studio, Code::Blocks, etc.) to link against SFML. You'll need to:

   - Include the SFML headers (include directory).
   - Link the SFML libraries (lib directory) to your project.
   - Copy the SFML .dll files into the same directory as your executable.
### Linux
1. Install SFML through your package manager:

   ```bash
   sudo apt-get install libsfml-dev
   
2. Ensure your compiler is set up to link against SFML:
   ```bash
   g++ -c main.cpp -o tetris -lsfml-graphics -lsfml-window -lsfml-system
