== SCServo

SC-series servo library for ESP32 and Arduino

=== Usage

The `+SCServo+` library may be installed like any other Arduino library.
A tutorial is available on
https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-installing-a-library/[docs.arduino.com].

Alternatively, the contents of this repository may be installed via the
`+arduino-cli+` through a direct installation.

____
WARNING:
This process requires enabling the installation of
https://arduino.github.io/arduino-cli/1.0/configuration/#configuration-methods[unsafe
libraries].
____


[source,shell]
----
arduino-cli \
  config \
    set \
      library.enable_unsafe_install true
----

Once the installation of unsafe libraries is enabled, the `+SCServo+`
library may be installed by running the following command:

[source,shell]
----
arduino-cli \
  lib \
    install \
      --git-url "https://github.com/workloads/scservo.git"
----

=== Notes

1.) The code in this repository is based on the `+SCServo+` library, initially made available by https://github.com/waveshareteam/ugv_base_general[@waveshareteam].

2.) The code for the `+SCServo+` library is divided into the following
parts:

* communication layer: link:src/SCS.cpp[SCS.cpp]
* hardware interface layer: link:src/SCSerial.cpp[SCSerial.cpp]
* application layer:
  ** corresponds to the three series of FIT servos
  ** `+SCSCL+` application layer program: link:src/SCSCL.h[SCSCL.h] and
  link:src/SCSCL.cpp[SCSCL.cpp]
  ** `+SMSBL+`, `+SMSCL+`, and `+STSCL+` application layer program:
  link:src/SMS_STS.h[SMS_STS.h] and link:src/SMS_STS.cpp[SMS_STS.cpp]
* instruction definition header file: link:src/INST.h[INST.h]
* communication layer program: link:src/SCS.h[SCS.h] and
  link:src/SCS.cpp[SCS.cpp]
* hardware interface program: link:src/SCSerial.h[SCSerial.h] and
  link:src/SCSerial.cpp[SCSerial.cpp]

3.) There are differences in the memory table definitions of different
series of servos.

=== Contributors

For a list of current (and past) contributors to this repository, see
https://github.com/workloads/scservo/graphs/contributors[GitHub].

=== License

Licensed under the General Public License, Version 3.0 (the
"`License`").

You may download a copy of the License at
https://www.gnu.org/licenses/gpl-3.0.txt[gnu.org/licenses/gpl-3.0.txt].

See the License for the specific language governing permissions and
limitations under the License.