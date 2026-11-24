---
title: Scanning Photonic Imager
github: https://github.com/AstroSparrow/Scanning-Photonic-Imager
description: An Experimental Arduino-based Scanning Imager that uses an Array of moving Light Sensors assembly to construct an Image!
created_at: "2026-11-22"
total_time: "8h"
---

# November 24, 2026: 1 - PreLiminary LDR Sensitivity Test
<!-- fabricate:entry 3852 -->

## **Data:**
`LDR 1: Normal: 960; Max: 1019; Low: 76
LDR 2: Normal: 918; Max: 1017; Low: 70
LDR 3: Normal: 935; Max: 1018; Low: 30
LDR 4: Normal: 934
LDR 5: Normal: 909
LDR 6: Normal: 930
LDR 7: Normal: 894
LDR 8: Normal: 931
LDR 9: Normal: 926
LDR 10: Normal: 968`

(Gave up on taking Low and Max readings for the other LDR's cause of irregular flashing/blocking of lighting conditions for each LDR)


## **Notes:**
**(Date: 11th of August, 2026)**

To measure the response of each LDR, I used a 10KΩ resistor to act as a voltage divider for A0 pin on the Nano.
Only the LDR's were swapped out on the Breadboard pins.
(Each LDR used the same Resistor, Jumper wires, Code and Nano Pin to minimise other factors affecting the readings)
(The 'LDR_Analog_Value_Reader.ino' is the uploaded sketch on the Arduino Nano for this test (With the pin being A0 rather than A2))



Btw, This was only a crude PreLiminary test to gauge the LDR's, The data isnt captured in a perfectly light controlled environment or accurate light angles for each LDR + There were storm clouds rolling outside so the ambient light level was changing slightly aswell during the experiment (I know not the perfect time to do the Test, But eh, I didn't wanna postpone it further).
So we can assume a ±10 ADC Count for each LDR Reading.  


On testing, LDR number 7 seemed to have the lowest response to ambient light and was also intermittently causing the Nano to reset (Possible due to it shorting out the Nano's GND and 5V pins)
So, LDR #7 is unfortunately disqualified from contributing further in SPI (My apologies mate, Maybe next time!)


According to the Data gathered, LDRs 1, 3, 4, 6, 8, 9 and 10 will be used in SPI and LDRs 2 and 5 will remain as Spare secondaries (Don't worry, You guys are still good to go, You will be called upon soon!)


Time for the RGB Filter Calibration test next!

![](https://fabricate.hackclub-assets.com/3a3866690b67130d37db2d971314024cbeb92847a5f405cb65b29ace6d380f49/image-png/Serial%20Monitor.png)
![](https://fabricate.hackclub-assets.com/dbf9a7ce916fad0be59c206720569e40cd44a518694c698d359350072b790840/image-jpeg/Setup%20Closeup.jpg)
![](https://fabricate.hackclub-assets.com/047b6036fccc5513bfea331b0f1c2c00d15968a75abbc6e9870b86db2254a27d/image-jpeg/Test%20in%20Progress.jpg)
![](https://fabricate.hackclub-assets.com/c56b3a330dda3de506f4e756597cd7d0d6d5bdc402c7dda2143a36564d504f04/image-jpeg/Test%20Setup.jpg)

**Total time spent: 2h**

# November 25, 2026: 2 - PreLiminary Colour Filter Response Test
<!-- fabricate:entry 3854 -->

## **Data**
Pre-Liminary Colour Filter Response Test
(Using LDR #5 and a Phone Screen displaying pure Colours at full Brightness)

LDR Responses (As reported by the Arduino Nano's ADC):

`No Screen/No Filter (Ambient Light): 690`
`Red Screen/No Filter: 512`
`Green Screen/No Filter: 610`
`Blue Screen/No Filter: 508`

`No Screen/Red Filter (Ambient Light): 404`
`Red Screen/Red Filter: 374`
`Green Screen/Red Filter: 284`
`Blue Screen/Red Filter: 260`

`No Screen/Green Filter (Ambient Light): 352`
`Red Screen/Green Filter: 262`
`Green Screen/Green Filter: 356`
`Blue Screen/Greeb Filter: 260`

`No Screen/Blue Filter (Ambient Light): 301`
`Red Screen/Blue Filter: 190`
`Green Screen/Blue Filter: 220`
`Blue Screen/Blue Filter: 320`

**[Extra Fun Stuff :D]**

`No Screen/All Filters (Ambient Light): 170`
(Probably above 0 or Negligible cause of residual Reflections from beneath the Gelatin Sheets)

`No Screen/Yellow Filter (Ambient Light): 410`
`Red Screen/Yellow Filter: 361`
`Green Screen/Yellow Filter: 376`
`Blue Screen/Yellow Filter: 208`
`Yellow Screen/Yellow Filter: 461`
`Magenta Screen/Yellow Filter: 357`
`Cyan Screen/Yellow Filter: 383`

`White Screen/No Filters: 690`
`Black Screen/No Filters: 170`


## **Notes:**
**(Date: 20th of August, 2026)**

So, In this test, I had to measure the response of a chosen LDR (In this case LDR #5 from the previous Experiment) Illuminated by my Phone's Screen displaying Pure Colours at full Brightness through the Red, Green and Blue Gelatin Colour Filters.
I used a 10KΩ resistor to act as a voltage divider for A2 pin on the Nano (The Circuit Schematic is almost the same as the Last experiment's one)

The 'LDR_Analog_Value_Reader.ino' is also the uploaded sketch on the Arduino Nano for this test.

I tried my best to keep the LDR position and angle the same between the Colour and Filter changes while keeping the Phone Screen at full brightness pressed flat to the Colour Filter.
The entire setup was held up in the air by my hand with approximately a 1cm Gap between the Filter and the LDR

For All the 3 (Well 4), There were 4 Layers of filter (3 times folded) between the Screen and the LDR 

This was a crude PreLiminary test to gauge the response of each of the Colour Filters, I did this test in my Bedroom which is not a perfectly Light controlled environment (I don't have a lab... Yet!).
The Screen Angles were also not completely the same between the Colours.
Plus, Gelatin sheets aren't perfect Colour filters, So they also let other colours leak into each other (I only had access to Gelatin sheets as my colour filter due to cost and availability constraints).

So again like the other test, We can assume a ±10 ADC Count for the LDR Readings for each of the Colour Filter.  

(Note: The Ambient LDR response is stronger than the Screen Responses because the LDR was pointed at my roof which is white coloured and was reflecting light from outside during the day, Compared to that, The Phone's screen through 4 layers of Gelatin Sheets is dimmer, Thus the Reduced ADC Values)

I did some tests with the Yellow Gelatin Sheet too + With no filters and All the filters for Funsies!

I also wanted to do some tests combining the Gelatin sheets (like Red + Green or Blue + Red etc) and then measure their corresponding LDR responses
But i figured that each filter i add on top will introduce 4 more layers of an imperfect filter which will block more and more of light that should ideally would've passed through, Thus producing negligible results
So, I scraped that idea...

Now, According to the Data gathered, There is a noticeable difference in the ADC Readings for the corresponding Colour and it's Filter. Proving my colour sensing idea works!

I am honestly so excited and relieved that this Proof of Concept for the project worked!! Cause the entire project (Or Atleast it's colour sensing part) was basically relying on this one experiment to produce meaningful results.
And Thankfully it did! So, Now we can calibrate some weights in the Code now to distinguish between the colours better and go ahead with the Project!! :D

![](https://fabricate.hackclub-assets.com/508ff26cd609711f19e9681c75f32579bcf1259bbb21403d76b639358afc56bd/image-jpeg/Colour%20Filter%20Test%20Setup.jpg)
![](https://fabricate.hackclub-assets.com/b02618a27b92e32b2736c69080ceb7e749324e3a3003a90baa29df337a312598/image-jpeg/RGB%20Filters%20on%20my%20Tab%27s%20Screen.jpg)

**Total time spent: 4h**
