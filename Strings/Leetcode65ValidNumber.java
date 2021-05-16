// A valid number can be split up into these components (in order):

// A decimal number or an integer.
// (Optional) An 'e' or 'E', followed by an integer.
// A decimal number can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One of the following formats:
// At least one digit, followed by a dot '.'.
// At least one digit, followed by a dot '.', followed by at least one digit.
// A dot '.', followed by at least one digit.
// An integer can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// At least one digit.
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", 
// "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
// while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

// Given a string s, return true if s is a valid number.

// WORST FUCKING PROBLEM EVER


class Solution65 {

  public boolean isNumber(String s) {
    int c2 = 0, c3 = 0;
    int n = s.length();
    int i = 0;

    if (n == 1) {
      if (s.charAt(i) >= 48 && s.charAt(i) <= 57) {
        return true;
      } else {
        return false;
      }
    }

    for (i = 0; i < n; i++) {
      if (s.charAt(i) == '+' || s.charAt(i) == '-') {
        if (i == 0) {
          if (
            !(
              (s.charAt(i + 1) >= 48 && s.charAt(i + 1) <= 57) ||
              s.charAt(i + 1) == '.'
            )
          ) {
            return false;
          }
        }
        if (i > 0) {
          if (i == n - 1) {
            return false;
          }

          if (!(s.charAt(i - 1) == 'e' || s.charAt(i - 1) == 'E')) {
            return false;
          }
        }
      } else if (s.charAt(i) == 'e' || s.charAt(i) == 'E') {
        c2++;

        if (c2 > 1 || i == 0 || i == n - 1) {
          return false;
        }

        if (n == 2) {
          return false;
        } else {
          if (
            !(
              (s.charAt(i - 1) >= 48 && s.charAt(i - 1) <= 57) ||
              s.charAt(i - 1) == '.'
            )
          ) {
            if (i == n - 2) {
              if (!(s.charAt(i + 1) >= 48 && s.charAt(i + 1) <= 57)) {
                return false;
              }
            } else {
              if (
                !(
                  (s.charAt(i + 1) == '+' || s.charAt(i + 1) == '-') ||
                  (s.charAt(i + 2) >= 48 && s.charAt(i + 2) <= 57)
                )
              ) {
                return false;
              }
            }
          }
        }
      } else if (s.charAt(i) == '.') {
        c3++;
        if (c3 > 1 || c2 > 0) {
          return false;
        }

        if (i == 0) {
          // System.out.println("Yay");
          if (!(s.charAt(i + 1) >= 48 && s.charAt(i + 1) <= 57)) {
            // System.out.println("Yay");
            return false;
          }
        } else if (i == n - 1) {
          if (!(s.charAt(i - 1) >= 48 && s.charAt(i - 1) <= 57)) {
            return false;
          }
        } else {
          if (i == 1) {
            if (
              !(
                (s.charAt(i + 1) >= 48 && s.charAt(i + 1) <= 57) ||
                s.charAt(i + 1) == 'e' ||
                s.charAt(i + 1) == 'E'
              ) ||
              !(
                (s.charAt(i - 1) >= 48 && s.charAt(i - 1) <= 57) ||
                s.charAt(i - 1) == '+' ||
                s.charAt(i - 1) == '-'
              )
            ) return false;
          } else {
            if (
              !(
                (s.charAt(i + 1) >= 48 && s.charAt(i + 1) <= 57) ||
                s.charAt(i + 1) == 'e' ||
                s.charAt(i + 1) == 'E'
              ) ||
              !(s.charAt(i - 1) >= 48 && s.charAt(i - 1) <= 57)
            ) {
              return false;
            }
          }
        }
      } else if (s.charAt(i) >= 48 && s.charAt(i) <= 57) {} else {
        return false;
      }
    }

    return true;
  }
}
