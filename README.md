# SC-Series Servo

> SC-Series Servo library for Arduino and ESP32

## Table of Contents

<!-- TOC -->
* [SC-Series Servo](#sc-series-servo)
  * [Table of Contents](#table-of-contents)
  * [Requirements](#requirements)
  * [Usage](#usage)
    * [Installation via Arduino IDE](#installation-via-arduino-ide)
    * [Installation via Arduino CLI](#installation-via-arduino-cli)
    * [Installation of development versions](#installation-of-development-versions)
  * [Notes](#notes)
    * [Upstream Compatibility](#upstream-compatibility)
    * [Upstream Notes](#upstream-notes)
  * [Contributors](#contributors)
  * [License](#license)
<!-- TOC -->

## Requirements

* `arduino-lint` `1.2.0` or [newer](https://arduino.github.io/arduino-lint/)
* `cpplint` `1.6.0` or [newer](https://github.com/cpplint/cpplint)
* `clang-format` `18.1.0` or [newer](https://clang.llvm.org/docs/ClangFormat.html)

## Usage

For usage examples, see the [examples](./examples) directory.

### Installation via Arduino IDE

For installation via the Arduino IDE, see [docs.arduino.cc](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library/).

### Installation via Arduino CLI

To install the latest version using `arduino-cli`, use the following command:

```shell
arduino-cli lib install SCServo
```

To install a specific version, use the following command:

```shell
arduino-cli lib install SCServo@1.0.2
```

### Installation of development versions

To install an in-development or unreleased version, installation of _unsafe_ libraries must be enabled.

To enable the installation of unsafe libraries, use the following command:

```shell
arduino-cli config set library.enable_unsafe_install true
```

See [docs.arduino.cc](https://arduino.github.io/arduino-cli/1.0/configuration/#configuration-methods) for more information on the implications.

Once the installation of unsafe libraries is enabled, the `SCServo` library may be installed by running the following command:

```shell
arduino-cli lib install --git-url "https://github.com/workloads/scservo.git"
```

## Development

This repository provides a [Makefile](./Makefile)-based workflow to aid in development.

Running `make` without commands will print out the following help information:

```text
📚 SCSERVO LIBRARY

Target          Description                                     Usage
lint-arduino    lint Arduino code using arduino-lint            `make lint-arduino`
lint-cpp        lint C++ code using cpplint and clang-format    `make lint-cpp`
help            display a list of Make Targets                  `make help`
_listincludes   list all included Makefiles and *.mk files      `make _listincludes`
_selfcheck      lint Makefile                                   `make _selfcheck`
vale            lint prose with Vale                            `make vale`
vale-sync       sync Vale dependencies                          `make vale-sync`
```

## Notes

### Upstream Compatibility

The initial version of this library (`1.0.1`) represents a direct fork of [@waveshareteam/ugv_base_general](https://github.com/waveshareteam/ugv_base_general/tree/main/SCServo).

The fork is based on commit [91e5871](https://github.com/workloads/scservo/commit/91e58712176c6d98a9476a74c7a1712f3d631114) and extracts the `SCServo` directory from the original repository to allow for easier downstream consumption via the Arduino CLI and IDE.

While the intent of this fork is to remain compatible with the upstream repository, no guarantees are made regarding the stability or compatibility of this library with the original repository.

### Upstream Notes

The code for the `SCServo` library is divided into the following
parts:

* communication layer: [src/SCS.cpp](src/SCS.cpp)
* hardware interface layer: [src/SCSerial.cpp](src/SCSerial.cpp)
* application layer:
  * corresponds to the three series of FIT servos
    * `SCSCL` application layer program: [src/SCSCL.h](src/SCSCL.h) and
      [src/SCSCL.cpp](src/SCSCL.cpp)
    * `SMSBL`, `SMSCL`, and `STSCL` application layer program:
      [src/SMS_STS.h](src/SMS_STS.h) and [src/SMS_STS.cpp](src/SMS_STS.cpp)
* instruction definition header file: [src/INST.h](src/INST.h)
* communication layer program: [src/SCS.h](src/SCS.h) and
  [src/SCS.cpp](src/SCS.cpp)
* hardware interface program: [src/SCSerial.h](src/SCSerial.h) and
  [src/SCSerial.cpp](src/SCSerial.cpp)

Note that there are differences in the memory table definitions of different series of servos.

### Release Ingressing

New (GitHub) releases of this library are automatically ingressed by the Arduino Library Manager.

A log of currently "visible" releases can be found at [downloads.arduino.cc](https://downloads.arduino.cc/libraries/logs/github.com/workloads/scservo/).

## Contributors

For a list of current (and past) contributors to this repository, see [GitHub](https://github.com/workloads/scservo/graphs/contributors).

## License

Licensed under the General Public License, Version 3.0 (the "License").

You may download a copy of the License at [gnu.org/licenses/gpl-3.0.txt](https://www.gnu.org/licenses/gpl-3.0.txt).

See the License for the specific language governing permissions and limitations under the License.
