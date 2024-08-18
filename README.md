# Calculator Project

## Overview
-This project is an expression-based calculator implemented using an ATmega32 microcontroller, an LCD display, and a keypad. The calculator can evaluate full arithmetic expressions, supporting operations such as addition, subtraction, multiplication, and division.
- **LCD && KEYPAD** are connected Randomly ----> (PORT && PIN) ----> that user determing them.

## Features
- **Expression Evaluation**: Handles complete arithmetic expressions, not just operations between two numbers.
- **4x4 Keypad Input**: Allows users to input numbers, operators, and parentheses for expressions.
- **16x2 LCD Display**: Displays the input expression and the result.
- **Basic Operations**: Addition, subtraction, multiplication, and division.

## Components Used
- **ATmega32 Microcontroller**: Manages the expression parsing, calculation, and controls the display and keypad.
- **16x2 LCD Display**: Shows the input expression and final result.
- **4x4 Keypad**: Takes input from the user for the entire expression.
- **Power Supply**: 5V DC for the microcontroller and peripherals.
  

## Circuit Diagram
The circuit connects the ATmega32 microcontroller to a 4x4 keypad and a 16x2 LCD. The keypad inputs are connected to **(PORTA && PORTB)**, while the LCD is connected to **(PORTC && PORTD)**. The circuit is powered by a 5V supply.

## Pin Configuration
- **LCD Connections**:
  - RS: PORTC && PIN0
  - RW: PORTC && PIN1
  - E:  PORTC && PIN3
  - Data Pins: PORTC && PORTD.
  
- **Keypad Connections**:
  - Rows: PORTA
  - Columns: PORTB

## Software
The code for this project is written in C and compiled using AVR-GCC. The code includes libraries for interfacing the LCD and the keypad, as well as the logic for parsing and evaluating arithmetic expressions.

## Usage
1. **Input Expression**: Use the keypad to enter a full arithmetic expression, including numbers and operators.
2. **Evaluate**: Press the `=` key to evaluate the expression and display the result on the LCD.

## Future Enhancements
- Support for floating-point arithmetic.
- Error handling for cases like division by zero, invalid input, or overflow.

## License
This project is open-source and available under the MIT License.
