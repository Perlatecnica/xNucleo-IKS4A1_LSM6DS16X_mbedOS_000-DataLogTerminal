# xNucleo-IKS4A1_LSM6DSV16X_mbedOS_000-DataLogTerminal

This application shows how to get data from LSM6DSV16X accelerometer and gyroscope and print them on terminal.

---

### Description:

This code is an example of utilizing the LSM6DSV16X inertial measurement sensor with an mbed microcontroller. It reads data from the accelerometer and gyroscope of the sensor and prints it over a serial connection.

### How it works:

- **Initialization**: 
  - It includes necessary libraries for communication (`mbed.h`) and for interfacing with the LSM6DSV16X sensor (`plt_iks4a1.h`).
  - It initializes objects for serial communication (`Serial`) and for controlling the onboard LED (`DigitalOut`).
  - It initializes an object for the LSM6DSV16X sensor, specifying the pins for I2C communication.

- **Data Reading and Printing**:
  - It defines arrays to store data from the accelerometer and gyroscope.
  - It defines a function `blinkLed()` to blink the LED connected to the microcontroller.
  - In the `main()` function:
    - It sets the baud rate for serial communication.
    - It initializes the LSM6DSV16X sensor and enables both the accelerometer and gyroscope.
    - It reads the sensor ID and prints it over the serial connection.
    - It prints a header for the data output.
    - It enters an infinite loop where it continuously reads data from the sensor:
      - It reads accelerometer and gyroscope data.
      - It prints the data over the serial connection.
      - It blinks the LED to indicate activity.

---

This description provides an overview of what each part of the code does and how it achieves its functionality.