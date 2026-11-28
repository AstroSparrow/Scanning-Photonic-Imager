---
title: "Scanning Photonic Imager"
github: "https://github.com/AstroSparrow/Scanning-Photonic-Imager"
description: "A weird Experimental Thingy i am making to explore how Camera Sensors work. But I'll be using just a couple of Light Dependant Resistors and some Servo Motors!"
created_at: "2026-07-22"
total_time: "12h"
---

# August 11, 2026: 1 -  PreLiminary LDR Sensitivity Test

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


**0h - 1:30h: Data Collection and Experimentation**

**1:30h - 2h: Note/Journal Writing**

**Total time spent: 2h**

# August 20, 2026: 2 - PreLiminary Colour Filter Response Test

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

**0h - 2h: Fighting with the Colour Filters and the LDRs to get them to work correctly**

**2h - 3h: Finally got the Experiment working and started collecting the Data**

**3h - 4h: Reviewing the Data, Analysing the Pattern, Getting Unusually Excited that it's working! And Wrote the Note/Journal**

**Total time spent: 4h**

# August 20, 2026: My reasoning behind choosing LDRs as the Main Light Sensors

So, For SPI, I had 3 options of Light sensors available:

1. CdS Light Dependent Resistors
2. Reverse Biased Light Emitting Diodes
3. Photo Diodes

-I ruled out using Photo Diodes pretty early on in the planning of the Project. Good quality, High Field of View (FOV) Photo Diodes are pretty expensive to buy (Especially since i had to use atleast 4 of them) and were only availible on Online stores (Which i do not trust much for Hobbyist Electronics).
Plus i would have to use external Colour Filters for them to work for SPI (Which is a major downside due to the Quality of the colour filters i had available) cause they don't have their own Colour Filtering.

- I could use simple LEDs and Reverse Bias them to calculate the Photocurrent they produce when struck with the Light of their specific Wavelength (Colour) [This option does not require any other Colour filters, as LEDs are generally most sensitive to their own Colour of Light].
The problem with this type of setup is that the Photocurrents produced by a Reverse Bias LED are extremely tiny (On the order of microamps), So it is not possible to sense such a weak signal without some sort of Amplification.
I really wanted to use this setup but tbh, I didn't cause i for the love of my life couldn't figure out how to utilise Op-Amps or any other sort of Amplification for this Approach (Major Skill issue on my side, My apologies) :/

- I could use CdS (Cadmium Sulfide) based LDRs (Light Dependent Resistors) to detect how much light is hitting each LDR and move forward with that Data.
LDR's have a pretty wide FOV + They are dirt cheap to buy and use!
The problem with this type of Setup again being that LDRs are not sensitive to only a narrow range of colours, They are sensitive to all Light, But we care only to sense the brightness of Red, Green and Blue to construct the images.
So i had to introduce some Light Filters that only allow Specific colours of light to be "sensed" by the LDR.


So, Out of All these options, I eventually settled on using the LDR approach with Red, Green and Blue Gelatin Sheets acting as their Colour Filters
(I know, I know... Gelatin Sheets are not the best Colour Filters to use here, But i didn't have any other similarly priced/available options)

I plan to give a shot with LED's once again in the future tho!

(Image taken on 25th of November, 2026)
![](https://fabricate.hackclub-assets.com/faf08f91396891e9cde28c9e9ab6858c127794f8ae843a6d1d5e32718447c843/image-jpeg/IMG_20261125_103658.jpg)

**0h - 1h: Writing/Explaining the Journal/Reasoning**

**Total time spent: 1h**

# November 25, 2026: How i Plan to use a single set of LDR's as a Image Sensor

Now, I am an amateur hobbyist (And a Teenager at that too), So naturally i dont have access to work with Millions or even Thousands of Light Sensors that i could arrange in arrays (Money and skill issue, I know) + I didn't really wanna use an actual Camera sensor, as that would defeat the entire point of testing this Experimental Setup yk.

Then i thought of using a Single Set/Array of (Improvised) Light sensors and then physically move them in a way that i could scan the required Field of View (FOV) of the scene in front of them.
This would prove to be much cheaper to work with (Cheaper Money-wise, But Harder to implement Skill-wise).

The only other downside of this would be that constructing an image this way would take much more time than a Normal Sensor would cause we have to move 1 "Sensing Pixel" to different positions, Then Read the Data, Send them to the Computer to be Compiled, Move the Sensor assembly to the new position and repeat. But as a proof of concept, This shouldn't be much of an issue (Hopefully).

So, I had to get Servo Motors involved into the Project for Precise Movement (Again, Couldn't afford to have multiple Stepper Motors instead). This meant i had to get my hands dirty with some Inverse Kinematics (Which should be fun to study.... right?)

So, The Design i have in Mind will use 4 Servo Motors:
- 1 Servo Controlling the Y-Axis Movement
- 1 Servo Sitting on the Edge of the Y-Axis Control Beam to Counteract the Y-Axis Rotation and keep the Sensor Assembly Perfectly Horizontal
- 1 Servo Controlling the Linear Movement of the Sensor Assembly via some Linear Movement Apparatus like Guide Rods, Rack and Pinion Arrangement etc 
- 1 Servo Controlling the X-Axis Rotation of the Sensor Assembly
(There are some Screenshots for the Crude Design of SPI attached Below)


I have Tried to operate the Servo Motors using just the Small Arduino Nano's Power Output. And well as expected, the Nano fell short by a long shot. So, In the further steps, I will have to use a SMPS Power Supply that can provide a Substantial Current, Which will be further regulated by a DC-DC Buck Converter!

I am so excited to finally make this Project actually Move!

![](https://cdn.hackclub.com/01a2217e-c754-7f30-aa73-8ac4662a8afe/SPI_Design(Crude_Model)_%231.png)
![](https://cdn.hackclub.com/01a2217e-c891-79b4-9f7b-81b7d6289f13/SPI_Design(Crude_Model)_%232.png)
![](https://fabricate.hackclub-assets.com/f7db8fd5b52d60747ab6ce839776915a1ec9ef3d29785ed9ad200fda4ba060b1/image-png/Screenshot%202026-11-25%20173330.png)

**0h - 2h (August 26, 2026): Trying and failing to drive the Servo Motors using the Nano (and getting so frustrated that i wanted to quit the project entirely). Ended up Ordering a DC-DC Buck Converter from Robocraze in the end**

**2h - 4h (August 31, 2026): Recieved the Ordered DC-DC Buck Converter, Experimented with it to run/drive the Servo Motors. Excited beyond belief that it finally worked!**

**4h - 5h (November 25, 2026): Writing the Journal Entry for the entire Endeavour**

**Total time spent: 5h**

----

# The End... For now! :D