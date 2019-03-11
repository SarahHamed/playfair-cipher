# playfair-cipher
Assumptions:
    I handled J as I.
    When two characters are in the same row, i take the one on the right.
    When two characters are in the same column, i take the one below.
    If it end up with one letter, it appends 'X'.
    When two characters are the same, It separates them with 'X'
    If it gets two consecutive 'X' ('XX') it separates them by the second least used character which is 'Q'.
    
    Example:
    
        input:
           KEYWORD
           BALLOON
       
        output:
          CBIZSCES
