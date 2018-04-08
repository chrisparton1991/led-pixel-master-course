# Bomb Defusal Game Shopping List

## Required Tools
* Safety glasses
* Soldering iron
* Solder (preferably 1mm or thinner)
* Side cutters or scissors
* 3mm (#0) or similar Phillips head screwdriver

## Required Components
These components are required to complete the project in its minimal form.

### 1x Arduino Uno + USB cable ([Buy on eBay](https://www.ebay.com/itm/253347374216))
* The microcontroller we will be using to control our LED strip.
* You can also buy an original Arduino brand from the Arduino.cc store if you want to, they are higher quality but much more expensive!

### 1 metre WS2812B 5V addressable LED strip ([Buy on eBay](https://www.ebay.com/itm/322058431958))
* The strip of LED pixels that we will use to show the player, bombs and wall of our game.
* You want a 1 metre, 30 leds/metre, waterproof strip. Black or white PCB (strip color) is up to you!
* We only need 12 pixels for this project, which is 40cm of strip, but it's useful to have extra in case you make a mistake.
* You can certainly buy more strip for use in future projects!

### 1x 5V 2A power supply with female adapter (Buy on eBay: [AU Plug](https://www.ebay.com.au/itm/182936154591))
*Please note that these power supplies are cheap, but they aren't high quality. Don't leave them turned on unattended, or use them near anything flammable! For a higher quality power supply you can trust, go to your local electronics store.*
* Make sure you get the correct input voltage and plug type for your country.
* You could also consider getting a more powerful 5 Amp power supply for use with larger projects.
* You'll need a [5.5x2.1mm female adapter](https://www.ebay.com/itm/221503522013). The eBay links above include these, but you can also buy them on their own.

### 8x Jumper cables (a.k.a. Dupont cables) ([Buy on eBay](https://www.ebay.com/itm/182871686698))
* We will use male-to-male jumper cables, but depending on the plug your LED strip comes with, you may need male-to-female as well.
* Since these cables are cheap, I'd recommend getting a set of female-to-female, male-to-female, and male-to-male. Chances are they'll come in handy someday!

### 2x Push buttons (12x12mm) ([Buy on eBay](https://www.ebay.com/itm/182387276369))
* The user presses these to move the player.
* These buttons come with black caps, but you can also buy buttons without caps and buy separate caps of any color you like!

### 1x Breadboard ([Buy on eBay](https://www.ebay.com/itm/183043997431))
* Used to connect the buttons to the Arduino via the jumper cables.

### 1x 3-pin LED strip connector set ([Buy on eBay](https://www.ebay.com/itm/322560873224))
* Depending on the LED strip you buy, this may already be attached.
* There's usually no guarantee of what type of cable, if any, will be attached to the LED strip.
* You can buy a single pair of connectors, but it's not much more expensive to get the pack of 10.

# Optional Components
These components are not essential, but will contribute to the safety, reliability or usability of the finished project.

### 1x 10V 1000uF electrolytic capacitor ([Buy on eBay](https://www.ebay.com/itm/292018365054))
* Used to smooth out power spikes from the power supply in order to protect the LED strip

### 1x 470Ω Resistor ([Buy on eBay](https://www.ebay.com/itm/192076577170))
* Used to prevent power spikes on the data line of the LED strip.
* Anything between 200Ω and 500Ω will work fine.

### 2x 10mm silicone LED strip end caps ([Buy on eBay](https://www.ebay.com/itm/182087898104))
* Used to cap off the ends of the LED strip.
* We will be using them mainly for cosmetic appearance in this project
* When applied correctly with silicone sealant, they can be used for waterproofing LED strips.

### 2cm 10mm heat shrink tubing ([Buy on eBay](https://www.ebay.com/itm/172969343833))
* Used for added protection around the LED strip connections.
* Requires a cigarette lighter (or similar) for shrinking.
