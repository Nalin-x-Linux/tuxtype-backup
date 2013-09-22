Accessibility extensions for TuxType
=====

When you enter the program, tts will announce these items while navigating with up and down arrow. fish cascade,comet sap,lessons,options,and quit. If you enter option menu, you will get these items. phrase typing, project info, set up language, main menu, and edit word list.


One can change the language using set up  menu and if the language is not supported by espeak, accessibility feature will be disabled. supported languages will be listed at the end of the document.

### Lessons  
One can choose the lesson from the main menu and select the lesson to be played using arrow keys.
To start the lesson press space and then press "P" in the keyboard. Press the keys as in the order announced by the tts. 
After the lesson is over tts will announce your speed and efficiency and other details.


### Fish-Cascade  
After the letters are practised, one can start the game fish cascade.
In fish cascade, one can  choose easy, medium, hard, levels and also choose to listen to the instructions, and if necessary go back to main menu. After choosing the level, one should use the arrow keys to select the type of words including finger exercise, numbers, short-words, long words, etc. after choosing the type of words, fish will start coming from the top. Now tts will start announcing the word in the fish with spelling . As the fish goes down, tts will change its pitch and speed to show how much down is the fish, which indicate the urgency of saving the word and make it eatable. If the fish become eatable and reach at bottom the tux will eat it with a crowling sound.  If a letter is typed wrong, one has to type the entire word once again. Game is over, when one has made certain number of fish made eatable. if the user fails to type the word, the fish will reach at the bottom and splat which cause reduction of lives and a splat sound. When remaining lives become zero one is lost.    

However tts will announce result message and ask to press to go back to the menu. To avoid confusion for a tts user, tts will announce only lower most three words, though there may be more than that number on the screen. By pressing 'F1' key one can understand how many fish remain and 'F2' key will help to know how many lives remaining. 
 

### Comet-Zap 
In this game comets comes downward toward the buildings. If they hit the buildings down, they will  destroy them. One should type the words announced by the tts. In this game one has to type only the remaining letters when a mistake is made. And also the program will make different sounds with respect to the letter typed is correct or wrong. Pitch and rate of the word increases as it approaches the building. Only the lowermost word is announced for the convenience of visually challenged. When each wave finishes tts will announce the score. When the game is over tts will announce the position and the final score as well.  Here 'F1' key will announce score, 'F2' announces number of cities alive and 'F3" will announce current wave.
pilot,  space cadet, and commander are of different levels of comet-zap.

### Phrase typing 
in this options, press the enter key on the menu and program will speak out the whole sentence and also tell each word to be typed . After the phrase is typed tts will announce the details of the speed and other details.

In Fish-Cascade and Comet-Zap, one can pause the game by pressing escape key, and resume game by pressing space. When the game is paused one can use up or down arrow to control the background music volume, 
and left and right arrow to control effects volume. This will help one to get maximum support from espeak.

### Espeak supported languages 
afrikaans, bulgarian-test, bosnian, catalan, czech, welsh-test, danish, german, greek, default, default-female, default-male, en-scottish, english, lancashire, english_rp, english_wmids, english-us, en-westindies, esperanto, spanish, spanish-latin-american, estonian, finnish, french (Belgium), french, greek-ancient, hindi, hindi-female, hindi-male, croatian, hungarian, armenian, armenian-west, indonesian-test, icelandic-test, italian, lojban, georgian-test, kannada, kannada-female, kannada-male, kurdish, latin, latvian, macedonian-test, malayalam, malayalam-female, malayalam-male, nahuatl - classical, dutch-test, norwegian, papiamento-test, polish, brazil, portugal, romanian, russian_test, slovak, albanian, serbian, swedish, swahili-test, tamil, tamil-female, tamil-male, turkish, vietnam, Mandarin, cantonese.

## Adding a language to tuxtype braille mode 
first one should create a text file named languagename.txt, in which there should include a list with raw key-combination,beginning-letter,middle-letter and end-letter separated by a space. Here f, d, s represent the braille dot 1, 2, 3 and j, k, l represent 4, 5, 6 dots of braille. 

For Example  
f a a a  
fd b b b  
fj c c c  
fsjl x x x  
fsjkl y y y  
fskl z z z 

Example for an Indian language(Hindi). 

f अ अ अ   
sjk आ ा ा 
dsk फ फ  !   
dj इ ि ि   
fdsjl ष ष ष   

We require three letters for a key-combination in the text file as many languages have same braille combinations in the beginning, middle , and very often same combination for punctuations in the end. That is same combination in braille indicate different letters,signs and punctuation in different position of the word. After creating the list in above shown format you have to place this file in /usr/local/share/tuxtype/braille folder.  
### Get Sharada-Braille-Writer from [here](http://sourceforge.net/projects/sbrw) ###
