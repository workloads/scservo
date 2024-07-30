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

The program running on the lower computer is either named [ugv_base_ros](https://github.com/effectsmachine/ugv_base_ros.git) or [ugv_base_general](https://github.com/effectsmachine/ugv_base_general.git) depending on the type of robot driver being used.  

Copy `SCServo` folder into `C:\Users\[username]\AppData\Local\Arduino15\libraries\`

Install libraries with **`Library Manager`**: ArduinoJson, LittleFS, Adafruit_SSD1306, INA219_WE, ESP32Encoder, PID_v2, SimpleKalmanFilter, Adafruit_ICM20X, Adafruit_ICM20948, Adafruit_Sensor

### Basic Use
You can send JSON command to robot via UART/USB@115200 or Http Request/Web App.
## Notes


## Contributors

For a list of current (and past) contributors to this repository, see [GitHub](https://github.com/workloads/scservo/graphs/contributors).

## License

Licensed under the General Public License, Version 2.3 (the "License").

You may download a copy of the License at [gnu.org/licenses/gpl-3.0.txt](https://www.gnu.org/licenses/gpl-3.0.txt).

See the License for the specific language governing permissions and limitations under the License.
