# CO-measurement
Implementation MQ-7 in htcc-ab02s
##  Understanding PPM (Parts Per Million)

PPM stands for "parts per million," and it is a unit of measurement used to describe the concentration of one substance in a million parts of another substance. It is commonly used to measure very dilute concentrations of substances, especially in gases, liquids, and solids.

### Thresholds for CO Concentration

1. **Good Air Quality**: Very low CO concentrations, such as 5 ppm (parts per million), are considered safe and indicate good air quality.
2. **Alarm and Danger Levels**:
   - **9 ppm**: The WHO recommends that long-term exposure (8 hours) should not exceed 9 ppm.
   - **50 ppm**: Prolonged exposure at this level can be hazardous to health.
   - **70 ppm**: Exposure at this level for several hours can cause symptoms like headaches and nausea.
   - **150-200 ppm**: Exposure can cause disorientation, unconsciousness, and can be fatal if continued for a prolonged period.

### Specific Thresholds and Guidelines

Here is a table of common CO thresholds based on guidelines from various agencies:

| CO Concentration (ppm)      | Effects and Guidelines                                                         |
|-----------------------------|--------------------------------------------------------------------------------|
| 0-9                         | No known adverse effects for long-term exposure                                 |
| 10-34                       | Time-weighted average exposure limit over 8 hours (EPA, OSHA, NIOSH)            |
| 35                          | Time-weighted average exposure limit over 1 hour (EPA, WHO)                     |
| 50                          | Time-weighted average exposure limit over 8 hours (OSHA)                        |
| 70                          | Possible mild symptoms after prolonged exposure                                 |
| 150-200                     | Headache, nausea, disorientation, risk of unconsciousness                       |
| >400                        | Severe health risk, potential death with prolonged exposure                     |

## Code explenation
The code measures the amount of CO in ppm in the air using an MQ-7 sensor. By using a resistor, you can obtain the voltage value, which is then converted into ppm with the help of the Arduino MQ-7 library from which the formulas are derived.

The HTCC-AB02S is slightly different from Arduino because it accepts voltage values up to 2.4V maximum. Therefore, a voltage divider is necessary to reduce the sensor voltage (which can be up to 5V) to 2.4V. For this purpose, a voltage divider with two 10k ohm resistors is used. This way, the input resistance to the sensor is known, and the maximum voltage will be 2.35V.
SendReceiveLoraWan_HTCC-AB02S_co sends also data from MQ-7 to loraWan
