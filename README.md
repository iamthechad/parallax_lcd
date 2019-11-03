![Maintenance](https://img.shields.io/maintenance/yes/2019)


<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Parallax LCD](#parallax-lcd)
  - [Functions](#functions)
  - [Example](#example)
  - [Installing](#installing)
    - [Download](#download)
    - [Manual Installation](#manual-installation)
    - [After Installation](#after-installation)
- [License](#license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Parallax LCD

The Parallax LCD library allows for writing to Parallax three wire LCDs.
It is known to work with Parallax LCD's (27976, 27977, 27979).

For more information about Parallax LCDs, see [http://www.parallax.com](http://www.parallax.com)	

## Functions

The library offers the following functions:

* `setup`
* `on`
* `off`
* `scrollLeft`
* `scrollRight`
* `empty`
* `cursorUnderline`
* `cursorBlock`
* `cursorOff`
* `cursorOnChrBlink`
* `cr`
* `lf`
* `backLightOn`
* `backLightOff`
* `playTone`
* `setCustomCharacter`
* `printCustomCharacter`
* `pos`
* `at`

## Example

Using the library is simple. See the included example for more.

    #include <ParallaxLCD.h>

    ParallaxLCD lcd(2,2,16); // desired pin, rows, cols

    void setup () {
      lcd.setup();
      delay(1000); // Wait for the LCD to start up
      lcd.at(1,3,"Hello World!");
    }

## Installing

Installation is performed via the Arduino Library Manager (Sketch -> Include Library)

### Download

* In the library manager, select "Manage Libraries..."
* In the search box, enter "Parallax LCD"
* Select the library in the results, pick the desired version and click "Install"

### Manual Installation

* Download the latest zip from the Releases tab. (Alternatively - clone this repository or select the "Zip" button above to download the code.)
* In the library manager, select "Add .ZIP Library"
* Select the downloaded zip file

### After Installation
* Once installed, you may need to restart the Arduino IDE
* Go to `File`->`Examples`. There should now be an entry for `Parallax LCD` in the list. Select it to see the example.
* Using the example as a guide, write your own code!

# License

This library is provided under the MIT license. You can obtain a copy of this license at http://opensource.org/licenses/MIT.
