# Vending Machine GUI Using Qt5

This project is a Human Machine Interface (HMI) for a vending machine, developed using Qt5 on a Debian-based Linux system with the Allwinner H618.

## Project Structure


## Description

- **fonts/**: Contains the font files used in the project.
- **img/**: Contains images, icons, and other graphical resources.
- **widgets/**: Houses the reusable widgets and components for building the GUI. This folder includes `.h`, `.ui`, and `.cpp` files for custom widgets.
- **main.cpp**: The entry point of the application that initializes and starts the program.
- **mainwindow.cpp**: Contains the implementation and logic for the main application window.

## Prerequisites

- **Qt5**: Ensure that Qt5 is installed on your system.
- **Debian-based Linux**: The project is configured for Debian-based systems such as those running on the Allwinner H618.

## Building and Running

1. **Set Up the Development Environment**:  
   Ensure that Qt5 and necessary tools such as `qmake` and `make` are installed.

2. **Build the Project**:
   ```bash
   qmake
   make
