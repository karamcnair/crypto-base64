extern crate rustc_serialize;

use rustc_serialize::hex::{FromHex};
use std::char;


fn main () {
	let hex_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	println!("String is {} and {} long", hex_string, hex_string.len());

    let bytes_1 = hex_string.from_hex();
    let bytes = bytes_1.unwrap();

    println!("Bytes are (in decimal): {:?}", bytes);
    for i in 0..bytes.len() {
       println!("Byte (in binary (assuming this works)): {:b}", bytes[i]);
    }

    let result_str = String::from_utf8(bytes).unwrap();
    println!("This is the 'text' result? {}", result_str);

    // next, for each byte in the byte string, encode it as ascii?
    // what does base64 even mean?
    // so we got the ascii text and... then what?

    let x: u8 = 255 ;
	println!("Binary {:b}, int {}", x, x);

	let y: u8 = x << 2;

	println!("lsh 2 {:b}, int {}", y, y);


	let z: u8 = x & 0x3F;
	let c = char::from_digit(z as u32, 2);

	println!("bitand 2 {:b}, int {}, char {:?}", z, z, c);


	let q: u8 = z | 0x00;

	println!("q 2 {:b}, int {}", q, q as char);


	// this is gonna be seriously ugly, but goal 1 is just to get something working in
	// a language I only started looking at yesterday.

	// I have the octet stream of the original input string (although I used a utility as
	// opposed to decoding it manually - at least I undersatnd how that was done)

	// I'm going to somewhat brute force the encoding. For every 3 octets I'll process 
	// them as a unit for now. I'll create a special case for the trailing 3.

	// for next 3 octets (assuming there are at least 3 left)


	// grab the 1st 6 bits out of 1st octet & save them into a new char

	// grab remaining 2 bits from 1st & the first 4 from 2nd octet & save into new char

	// grab remaining 4 bits from 2nd octet & first 2 from 3rd octet & save into new

	// grab remaining 6 bits from 3rd octet & save into new char

	// stick all 4 chars into the base64 string.

	// 



 }

 fn sliceThreeOctets()

