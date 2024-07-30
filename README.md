# SCServo

> SC-series servo library for ESP32 and Arduino

## Table of Contents

<!-- TOC -->
* [SCServo](#scservo)
  * [Table of Contents](#table-of-contents)
  * [Usage](#usage)
  * [Notes](#notes)
  * [Contributors](#contributors)
  * [License](#license)
<!-- TOC -->

## Usage

The `SCServo` library may be installed like any other Arduino library. A tutorial is available on [docs.arduino.com](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library/).

Alternatively, the contents of this repository may be downloaded and installed manually by copying them to the `libraries` folder of the Arduino IDE.

## Notes

1.) The code for the `SCServo` library is divided into the following parts:

- communication layer: [SCS.cpp](./SCS.cpp)
- hardware interface layer: [SCSerial.cpp](./SCSerial.cpp)
- application layer: 
  - corresponds to the three series of FIT servos
  - `SCSCL` application layer program: [SCSCL.h](./SCSCL.h) and [SCSCL.cpp](./SCSCL.cpp)
  - `SMSBL`, `SMSCL`, and `STSCL` application layer program: [SMS_STS.h](./SMS_STS.h) and [SMS_STS.cpp](./SMS_STS.cpp)
- instruction definition header file: [INST.h](./INST.h)
- communication layer program: [SCS.h](./SCS.h) and [SCS.cpp](./SCS.cpp)
- hardware interface program: [SCSerial.h](./SCSerial.h) and [SCSerial.cpp](./SCSerial.cpp)

2.) There are differences in the memory table definitions of different series of servos.

## Contributors

For a list of current (and past) contributors to this repository, see [GitHub](https://github.com/workloads/scservo/graphs/contributors).

## License

Licensed under the General Public License, Version 2.3 (the "License").

You may download a copy of the License at [gnu.org/licenses/gpl-3.0.txt](https://www.gnu.org/licenses/gpl-3.0.txt).

See the License for the specific language governing permissions and limitations under the License.
