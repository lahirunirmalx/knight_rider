**Knight Rider LED Scanner**

This project brings the iconic KITT LED scanner from the 1980s TV show Knight Rider to life using Arduino or ESP32 boards. It simulates the signature scanning pattern across a row of LEDs, replicating the classic visual effect.

**Features**

- Supports both Arduino and ESP32 boards for flexibility.
- Customizable scanning speed for tailoring the animation's intensity.
- Clear and concise code structure for easy understanding and modification.

**Hardware Requirements**

- Arduino or ESP32 development board (e.g., Arduino Uno, ESP32 DevKitC)
- `N` LEDs (where `N` is the desired number of LEDs in your scanner)
- Resistors (values depend on LED specifications and board voltage)
- Breadboard and jumper wires

**Software Requirements**

- Arduino IDE ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software))

**Wiring**

1. Connect each LED's positive terminal to a resistor suitable for the LED's forward voltage and the board's operating voltage.
2. Connect the resistors' other ends to individual digital output pins on your Arduino or ESP32 board.
3. Connect all LED negative terminals to a common ground pin on the board.

**Installation**

1. Download or clone this repository.
2. Open the `knight_rider_(xxx).ino` file in the Arduino IDE.
3. Select the appropriate board type and serial port in the Arduino IDE settings.
4. If using an ESP32 board, you might need to install the necessary board support package in the IDE's Boards Manager (Tools > Board > Boards Manager). Refer to ESP32 documentation for specific instructions.
5. Upload the code to your board.

**Usage**

Once uploaded, the code will automatically initiate the KITT LED scanner animation. You can adjust the scanning speed by modifying the `DELAY_TIME` constant in the code. Lower values result in a faster-moving scan, while higher values create a slower scan.

**Code Structure**

```c++
#define DELAY_TIME 100
#define FULL_BRIGHTNESS 255
#define Q1_BRIGHTNESS 200
#define Q2_BRIGHTNESS 155
#define HALF_BRIGHTNESS 100
#define Q3_BRIGHTNESS 55

----- 
``` 

**Additional Notes**

- Feel free to experiment with different LED colors and arrangements to create variations of the KITT scanner effect.
- For more advanced control, consider using libraries or functions specifically designed for LED animation on Arduino or ESP32 boards.

**Contributing**

We welcome pull requests to improve this project or add functionality. Please create an issue to discuss any changes before submitting a pull request.

**License**

This project is licensed under the MIT License (see LICENSE file for details).

**Enjoy building your own KITT LED scanner!**
