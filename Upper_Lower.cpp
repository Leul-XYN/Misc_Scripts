/* ASCII Table from https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

Dec  = Decimal Value
Char = Character

Dec  Char                           Dec  Char     Dec  Char     Dec  Char
---------                           ---------     ---------     ----------
  0  NUL (null)                      32  SPACE     64  @         96  `
  1  SOH (start of heading)          33  !         65  A         97  a
  2  STX (start of text)             34  "         66  B         98  b
  3  ETX (end of text)               35  #         67  C         99  c
  4  EOT (end of transmission)       36  $         68  D        100  d
  5  ENQ (enquiry)                   37  %         69  E        101  e
  6  ACK (acknowledge)               38  &         70  F        102  f
  7  BEL (bell)                      39  '         71  G        103  g
  8  BS  (backspace)                 40  (         72  H        104  h
  9  TAB (horizontal tab)            41  )         73  I        105  i
 10  LF  (NL line feed, new line)    42  *         74  J        106  j
 11  VT  (vertical tab)              43  +         75  K        107  k
 12  FF  (NP form feed, new page)    44  ,         76  L        108  l
 13  CR  (carriage return)           45  -         77  M        109  m
 14  SO  (shift out)                 46  .         78  N        110  n
 15  SI  (shift in)                  47  /         79  O        111  o
 16  DLE (data link escape)          48  0         80  P        112  p
 17  DC1 (device control 1)          49  1         81  Q        113  q
 18  DC2 (device control 2)          50  2         82  R        114  r
 19  DC3 (device control 3)          51  3         83  S        115  s
 20  DC4 (device control 4)          52  4         84  T        116  t
 21  NAK (negative acknowledge)      53  5         85  U        117  u
 22  SYN (synchronous idle)          54  6         86  V        118  v
 23  ETB (end of trans. block)       55  7         87  W        119  w
 24  CAN (cancel)                    56  8         88  X        120  x
 25  EM  (end of medium)             57  9         89  Y        121  y
 26  SUB (substitute)                58  :         90  Z        122  z
 27  ESC (escape)                    59  ;         91  [        123  {
 28  FS  (file separator)            60  <         92  \        124  |
 29  GS  (group separator)           61  =         93  ]        125  }
 30  RS  (record separator)          62  >         94  ^        126  ~
 31  US  (unit separator)            63  ?         95  _        127  DEL
*************************************************************************************/

// This Program support the Conversion of Sentences to
// "lower case"
// "UPPER CASE"
// "Sentence case"
// "Capitalize Each Word"

#include <iostream>
using namespace std;

// Accepts a Character and returns an UPPER_CASE of the Charachter
char To_Upper_char(char c){
    int ic = (int)c;
    if (ic >= 97 && ic <= 122){
        ic = ic - 32;
        c = (char)ic;
    }
    return c;
}

// Accepts a Character and returns a lower_case of the Charachter
char To_Lower_char(char c){
    int ic = (int)c;
    if (ic >= 65 && ic <= 90){
        ic = ic + 32;
        c = (char)ic;
    }   
    return c;
}

// checks for Every charachter in a Sentence 
// if the Charachter is lower_case it calls "To_Upper_char" Function on each Charachter
string UPPER_CASE (string sen){
    int i = 0;
    while (i < sen.size()){
        int Char_I = (int)sen[i];

        if (Char_I >= 97 && Char_I <= 122){
            sen[i] = To_Upper_char(sen[i]);
        }
        i++;
    }
    return sen;
}

// checks for Every charachter in a Sentence 
// if the Charachter is UPPER_CASE it calls "To_Lower_char" Function on each Charachter
string lower_case (string sen){
    int i = 0;
    while (i < sen.size()){
        int Char_I = (int)sen[i];

        if (Char_I >= 65 && Char_I <= 90){
            sen[i] = To_Lower_char(sen[i]);
        }
        i++;
    }
    return sen;
}

// checks for Every charachter in a Sentence 
// if the First Charachter is lower_case it calls "To_Upper_char" Function
// Then if the rest Charachters are UPPER_CASE it calls "To_Lower_char" Function on each Charachter
string Sentence_case (string sen){
    int i = 0;
    while (i < sen.size()){
        int Char_I = (int)sen[i];
        if (i == 0){
            if (Char_I >= 97 && Char_I <= 122){
                sen[i] = To_Upper_char(sen[i]);
            }    
        }
        else if (Char_I >= 65 && Char_I <= 90){
            sen[i] = To_Lower_char(sen[i]);
        }
        i++;
    }
    return sen;
}

// checks for Every charachter in a Sentence 
// if the First Charachter is lower_case it calls "To_Upper_char" Function
// Every time it finds a Space it Sets "Space_Flag = 1"
// On the next loop if Space_Flag is set to "1" it calls "To_Upper_char" Function
// Then sets "Space_Flag = 0"
// Then if the rest Charachters are UPPER_CASE it calls "To_Lower_char" Function on each Charachter
string Capitalize_Each_Word (string sen){
    int i = 0;
    int Space_Flag = 0;
    while (i < sen.size()){
        int Char_I = (int)sen[i];
        if (i == 0){
            if (Char_I >= 97 && Char_I <= 122){
                sen[i] = To_Upper_char(sen[i]);
            }    
        }
        else if (Space_Flag == 0 && Char_I >= 65 && Char_I <= 90){
            sen[i] = To_Lower_char(sen[i]);
        }
        else if (Space_Flag == 1){
            Space_Flag = 0;

            if(Char_I >= 97 && Char_I <= 122){
                sen[i] = To_Upper_char(sen[i]);
            }
            else if (Char_I == 32){
                Space_Flag = 1;
            }
        }
        else if (Char_I == 32){
            Space_Flag = 1;
        }
        i++;
    }
    return sen;
}

// Main Function
int main(){

    string Sentence;
    string Case_Error = "Error Please Enter 1-4: ";
    int Case_Type = 1;

// Accepts a Sentence to be converted
    cout << "Enter a Sentence: ";
    getline (cin >> ws, Sentence);

// Gives a choice of 1-4 the Accepts the choice
    cout << endl;
    cout << "To convert to 'UPPER_CASE' Enter ...... 1"<< endl;
    cout << "To convert to 'lower_case' Enter ...... 2"<< endl;
    cout << "To convert to 'Sentence_case' Enter ... 3"<< endl;
    cout << "To 'Capitalize_Each_Word' Enter ....... 4"<< endl;
    Case_Req: cin >> Case_Type;

// Checks If user inputs a "Non Number" or a number below 1 or above 4
// Then Shows Error message and Requests again for an input
    if (cin.fail() || Case_Type < 1 || Case_Type > 4){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << Case_Error;
        goto Case_Req;
        }
    
    if (Case_Type == 1) {
        Sentence = UPPER_CASE (Sentence);
        cout << Sentence;
    }
    else if (Case_Type == 2) {
        Sentence = lower_case (Sentence);
        cout << Sentence;
    }
    else if (Case_Type == 3) {
        Sentence = Sentence_case (Sentence);
        cout << Sentence;
    }
    else if (Case_Type == 4) {
        Sentence = Capitalize_Each_Word (Sentence);
        cout << Sentence;
    }
}