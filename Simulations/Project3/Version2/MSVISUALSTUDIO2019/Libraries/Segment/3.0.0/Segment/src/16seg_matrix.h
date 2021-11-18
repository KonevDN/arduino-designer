/*
 * Sixteen-Segment display matrix of bits to write numbers, characters and letters to shift-register/parallel displays
 * Also includes bits required for special functions/examples
 * Used by Segment.h and Segment.cpp
*/
const int Segment::_16numMatrix[84][16] PROGMEM {
     //segments
     //m,l,k,j,i,h,g2,g1,f,e,d2,d1,c,b,a2,a1
      // NUMBERS
      {1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1}, //ZERO
      {0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0}, //ONE
      {0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1}, //TWO
      {0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1}, //THREE
      {0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0}, //FOUR
      {0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1}, //FIVE
      {0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1}, //SIX
      {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, //SEVEN
      {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1}, //EIGHT
      {0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1}, //NINE
      // LETTERS
      {0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1}, //LETTER A
      {0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,1}, //LETTER B
      {0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1}, //LETTER C
      {0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1}, //LETTER D
      {0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1}, //LETTER E
      {0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1}, //LETTER F
      {0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1}, //LETTER G
      {0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0}, //LETTER H
      {0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,1}, //LETTER I
      {0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0}, //LETTER J
      {0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0}, //LETTER K
      {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0}, //LETTER L
      {0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0}, //LETTER M
      {0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0}, //LETTER N
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}, //LETTER O
      {0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1}, //LETTER P
      {0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1}, //LETTER Q
      {0,0,1,0,0,0,1,1,1,1,0,0,0,1,1,1}, //LETTER R
      {0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1}, //LETTER S
      {0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1}, //LETTER T
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0}, //LETTER U
      {1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0}, //LETTER V
      {1,0,1,0,0,0,0,0,1,1,0,0,1,1,0,0}, //LETTER W
      {1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0}, //LETTER X
      {0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0}, //LETTER Y
      {1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1}, //LETTER Z
      // PUNCTUATION/CHARACTERS
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //BLANK
      {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0}, //CHARACTER "
      {0,1,0,0,1,0,1,1,0,0,1,1,1,1,0,0}, //CHARACTER #
      {0,1,0,0,1,0,1,1,1,0,1,1,1,0,1,1}, //CHARACTER $
      {1,1,0,1,1,0,1,1,1,0,0,1,1,0,0,1}, //CHARACTER %
      {0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,1}, //CHARACTER &
      {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, //CHARACTER ' `
      {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0}, //CHARACTER ( [ {
      {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}, //CHARACTER ) ] }
      {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}, //CHARACTER *
      {0,1,0,0,1,0,1,1,0,0,0,0,0,0,0,0}, //CHARACTER +
      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //CHARACTER ,
      {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0}, //CHARACTER - ~
      {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, //CHARACTER /
      {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}, //CHARACTER :
      {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, //CHARACTER ;
      {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1}, //CHARACTER <
      {0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1}, //CHARACTER =
      {0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0}, //CHARACTER >
      {0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1}, //CHARACTER ?
      {1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1}, //CHARACTER @
      {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0}, //CHARACTER (back slash)
      {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0}, //CHARACTER ^
      {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}, //CHARACTER _
      {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0}, //CHARACTER !
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //CHARACTER .
      // EXAMPLE/ANIMATION ARRAYS
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}, //SEGMENT A1/A2 (A) ONLY
      {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}, //SEGMENT B ONLY
      {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}, //SEGMENT C ONLY
      {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0}, //SEGMENT D1/D2 (D) ONLY
      {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, //SEGMENT E ONLY
      {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}, //SEGMENT F ONLY
      {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0}, //SEGMENT G1/G2 (G) ONLY
      {0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0}, //SEGMENT C+E
      {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0}, //SEGMENT B+F
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0}, //SEGMENT A1/A2 (A) OFF
      {0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1}, //SEGMENT B OFF
      {0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1}, //SEGMENT C OFF
      {0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1}, //SEGMENT D1/D2 (D) OFF
      {0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1}, //SEGMENT E OFF
      {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1}, //SEGMENT F OFF
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}, //SEGMENT G1/G2 (G) OFF
      {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1}, //SEGMENT A+B
      {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}, //SEGMENT A+B+C
      {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1}, //SEGMENT A+B+C+D
      {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1}, //SEGMENT A+B+C+D+E
      {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}, //SEGMENT A+B+C+D+E+F
      {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1}, //SEGMENT A+B+C+D+E+F+G
};