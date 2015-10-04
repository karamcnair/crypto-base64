#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>
#include <math.h>

  // for next 3 octets (assuming there are at least 3 left)


  // grab the 1st 6 bits out of 1st octet & save them into a new char

  // grab remaining 2 bits from 1st & the first 4 from 2nd octet & save into new char

  // grab remaining 4 bits from 2nd octet & first 2 from 3rd octet & save into new

  // grab remaining 6 bits from 3rd octet & save into new char

  // stick all 4 chars into the base64 string.

const char hex_string[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
const char base64_string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

//  int * hexStringToByteArray(char *s) {
//     int len = s.length();
//     int[] data = new int[len / 2];
//     for (int i = 0; i < len; i += 2) {
//         data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
//                              + Character.digit(s.charAt(i+1), 16));
//     }
//     return data;
// }
void byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    printf("%s ", b);
}

// not error checking for illegal hex chars b/c this is a canned example with known input
// assume 
int convert_hex_chars_to_int(char cs[]) {

  int hexval = 0;

  hexval = strtol(cs, NULL, 16);

  return hexval;
}

int convert_hex_string_to_byte_array(const char hex_string[], int byte_array[], int num_chars) {

  // int byte = 0;
  // for (int i = 0; i < num_chars; i++) {
  //   byte = convert_hex_char_to_int(hex_string[i]);
  //   printf("byte = %d ", byte);
  //   byte_array[i] = byte;
  // }
  // printf("\n");
  char hexpair[3] = "";
  int i = 0, j = 0;

  for (i = 0, j = 0; i < num_chars; i+=2, j++) {
    hexpair[0] = hex_string[i];
    hexpair[1] = hex_string[i+1];
    hexpair[2] = '\0';

    byte_array[j] = convert_hex_chars_to_int(hexpair);

  }

  for (i = 0; i <  j; i++) {

    if(byte_array[i]) 
      printf("%c", byte_array[i]);
  }
  byte_array[j] = '\0';
  return 1;
}
// pass in space to hold the chars 
int convert_bytes_to_base64(int bytes[], int num_bytes, char base64_chars[], int num_b64c) {

  printf("In convert_bytes_to_base64. num_bytes= %d, num_b64c = %d\n", num_bytes, num_b64c);
  int b64_i = 0;
  int i = 0;
  char * cur_ptr = base64_chars;

  for (i = 0; i < num_bytes; i+= 3) {

    // first byte. 
    b64_i = (bytes[i] >> 2) & 0x3F;
    int btry = (bytes[i] & 0xF3) >> 2;
   // printf("i = %d, bytes[i] = %d, wb = %c ;", i, bytes[i], base64_string[b64_i]);
    // printf("99: & >> 2: ");
    // byte_to_binary(bytes[i]);
    // byte_to_binary(0x3F);
    // byte_to_binary(b64_i);
    // byte_to_binary(btry);
    // printf("\n");

    *cur_ptr = base64_string[b64_i];
    cur_ptr++;

    // Put last 2 bits of 1st byte in next char at positions 6 & 5
    b64_i = 0;
    b64_i = ((bytes[i]& 0x3)  << 4) ;


    // if there's a second byte, add the first 4 bits of it
    if (i + 1 < num_bytes) {

      b64_i |= ((bytes[i+1] & 0xF0) >> 4);
   
      *cur_ptr = base64_string[b64_i];
      cur_ptr++;

      // add the last 4 bits of the second byte to pos 6,5
      b64_i = ((bytes[i+1] & 0x0F) << 2);

     // if there's a third byte, add the first 2 bits of it to end of cur.
      if (i + 2 < num_bytes) {
        b64_i |= (bytes[i+2] & 0b11000000) >> 6;

        *cur_ptr = base64_string[b64_i];
        cur_ptr++;

        // fill in the last 6 bits of the 3rd byte
        b64_i = bytes[i+2] & 0x3F;
        *cur_ptr = base64_string[b64_i];
        cur_ptr++;
      } 
      else {
        // we have the 2nd half of the 2nd byte only.
        *cur_ptr = base64_string[b64_i];
        cur_ptr++;
        // MIME only
        // *cur_ptr = '=';
        // cur_ptr++;
      }
    } 
    else {
      // we have the last 2 bits of the first byte only
        *cur_ptr = base64_string[b64_i];
        cur_ptr++;
        // MIME only
        // *cur_ptr = '=';
        // cur_ptr++;
        // *cur_ptr = '=';
        // cur_ptr++;
    }
    *cur_ptr = '\0';

  }
  return i;
}



int main(void)
{
  printf("hex_string = %s\n", hex_string);

  int num_hex_digits = sizeof(hex_string) / sizeof(hex_string[0]) - 1;
  int num_bytes = num_hex_digits/2;
  int *bytes = malloc (num_hex_digits * sizeof(int));

  int result = convert_hex_string_to_byte_array(hex_string, bytes, num_hex_digits);

  // for next 3 octets (assuming there are at least 3 left)


  // grab the 1st 6 bits out of 1st octet & save them into a new char

  // grab remaining 2 bits from 1st & the first 4 from 2nd octet & save into new char

  // grab remaining 4 bits from 2nd octet & first 2 from 3rd octet & save into new

  // grab remaining 6 bits from 3rd octet & save into new char


  // we are going to need at least 4/3 the size of the original array. 
  // for first rough cut, I'm going to just double it. I'll figure out the 
  // real size later.

  // google suggests this is the real number:
  // (floor(n / 3) + 1) * 4 + 1

  int num_b64_chars = ceil(4/3 * num_bytes);
  char *base_64_array = malloc(sizeof(char) * num_b64_chars);

  result = convert_bytes_to_base64(bytes, num_bytes, base_64_array, num_b64_chars);

  printf("We had %d bytes in the array\n", num_hex_digits);
  printf("We had %d chars in the \n%s\n", num_b64_chars, base_64_array);
  printf("encoded string: %s\n", base_64_array);

  return 0;
}
