# Lumo Voice

Lumo Voice is a keyword spotting (KWS) project utilizing the Arduino Nicla Voice platform, designed to control LED lighting. This repository includes:

- **Arduino Code**: Firmware for the Nicla Voice and Nordic Semiconductor nRF52832.
- **KiCAD PCB Files**: Schematics and manufacturing files for the custom LED control PCB.
- **3D Print Files**: .stl files for the project casing.

## Getting Started

1. **Firmware**: Upload the Arduino code to the Nicla Voice..
2. **Hardware**: Use the provided KiCAD files to manufacture the custom PCB.
3. **Case**: 3D print the casing using the included .stl files.

## Usage

The device responds to voice commands "extinguish" and "illuminate" to control the lights. An "z_openset" category handles unrecognized commands.

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.
